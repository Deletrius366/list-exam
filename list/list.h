//
// Created by User on 22.06.2019.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include <iterator>
#include <memory>
#include <assert.h>
#include <cstddef>

template <typename T> struct base_node;
template <typename T> struct node;

template <typename T>
struct base_node {

    base_node<T>* prev;
    base_node<T>* next;

    base_node() : prev(this), next(this) {}

};

template <typename T>
struct node : base_node<T> {
    T value;

    node(T const& value) : value(value) {}
};

template<typename T>
struct list_iterator {
    typedef T value_type;
    typedef T& reference;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef std::bidirectional_iterator_tag iterator_category;

    template <typename > friend class list;
    template <typename > friend class const_list_iterator;

    list_iterator() = default;
    list_iterator(list_iterator const &) = default;

    list_iterator& operator++() {
        ptr = ptr->next;
        return (*this);
    }

    list_iterator& operator--() {
        ptr = ptr->prev;
        return (*this);
    }

    const list_iterator operator++(int) {
        list_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    const list_iterator operator--(int) {
        list_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    friend bool operator==(list_iterator const &it1, list_iterator const &it2) {
        return it1.ptr == it2.ptr;
    }

    friend bool operator!=(list_iterator const &it1, list_iterator const &it2) {
        return it1.ptr != it2.ptr;
    }

    friend bool operator<(list_iterator const &it1, list_iterator const &it2) {
        return it1.ptr < it2.ptr;
    }

    friend bool operator>(list_iterator const &it1, list_iterator const &it2) {
        return it2.ptr < it1.ptr;
    }

    friend bool operator<=(list_iterator const &it1, list_iterator const &it2) {
        return it1.ptr <= it2.ptr;
    }

    friend bool operator>=(list_iterator const &it1, list_iterator const &it2) {
        return it1.ptr >= it2.ptr;
    }

    reference operator*() const {
        return reinterpret_cast<node<value_type>*>(ptr)->value;
    }

    pointer operator->() const {
        auto now = reinterpret_cast<node<value_type>*>(ptr);
        return &now->value;
    }

private:
    explicit list_iterator(base_node<value_type>* p) : ptr(p) {}

    base_node<value_type>* ptr;

};

template<typename T>
struct const_list_iterator {
    typedef T value_type;
    typedef T const& reference;
    typedef ptrdiff_t difference_type;
    typedef T const *pointer;
    typedef std::bidirectional_iterator_tag iterator_category;

    template <typename > friend class list;

    const_list_iterator() = default;
    const_list_iterator(const_list_iterator const &) = default;

    const_list_iterator(list_iterator<T> const& a) : ptr(a.ptr) {}

    const_list_iterator& operator++() {
        ptr = ptr->next;
        return (*this);
    }

    const_list_iterator& operator--() {
        ptr = ptr->prev;
        return (*this);
    }

    const const_list_iterator operator++(int) {
        const_list_iterator<T> tmp(*this);
        ++(*this);
        return tmp;
    }

    const const_list_iterator operator--(int) {
        const_list_iterator<T> tmp(*this);
        --(*this);
        return tmp;
    }

    friend bool operator==(const_list_iterator const &it1, const_list_iterator const &it2) {
        return it1.ptr == it2.ptr;
    }

    friend bool operator!=(const_list_iterator const &it1, const_list_iterator const &it2) {
        return it1.ptr != it2.ptr;
    }

    friend bool operator<(const_list_iterator const &it1, const_list_iterator const &it2) {
        return it1.ptr < it2.ptr;
    }

    friend bool operator>(const_list_iterator const &it1, const_list_iterator const &it2) {
        return it2.ptr < it1.ptr;
    }

    friend bool operator<=(const_list_iterator const &it1, const_list_iterator const &it2) {
        return it1.ptr <= it2.ptr;
    }

    friend bool operator>=(const_list_iterator const &it1, const_list_iterator const &it2) {
        return it1.ptr >= it2.ptr;
    }

    reference operator*() const {
        return reinterpret_cast<node<T>*>(ptr)->value;
    }

    pointer operator->() const {
        auto now = reinterpret_cast<node<value_type>*>(ptr);
        return &now->value;
    }

private:
    explicit const_list_iterator(base_node<value_type>* p) : ptr(p) {}

    base_node<value_type>*ptr;

};

template <typename T>
class list {
    base_node<T> head;
    size_t size_;

    node<T>* alloc_node(T const& elem) {
        auto * ret = new node<T>(elem);
        return ret;
    }


    void dealloc_node(node<T>* t) {
        delete t;
    }

public:
    typedef list_iterator<T> iterator;
    typedef const_list_iterator<T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    list() noexcept {}
    list(list const& other) : list() {
        for (auto it = other.begin(); it != other.end(); ++it) {
            push_back(*it);
        }
    }
    list& operator=(list const& other) {
        if (this != &other) {
            clear();
            for (auto it = other.begin(); it != other.end(); ++it) {
                push_back(*it);
            }
        }
        return (*this);
    }

    ~list() {
        clear();
    }

    iterator begin() {
        return ++iterator(&head);
    }

    iterator end() {
        return iterator(&head);
    }

    const_iterator begin() const {
        return cbegin();
    }

    const_iterator end() const {
        return cend();
    }

    const_iterator cbegin() const {
        return const_iterator(head.next);
    }

    const_iterator cend() const {
        return const_iterator(&(const_cast<base_node<T>&>(head)));
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    iterator insert(const_iterator it, T const& other) {
        auto now = alloc_node(other);
        auto b = it.ptr;
        --it;
        auto a = it.ptr;
        now->prev = a;
        a->next = now;
        now->next = b;
        b->prev = now;
        return iterator(now);
    }

    iterator erase(const_iterator it) {
        auto now = it.ptr;
        auto ret = ++it;
        now->prev->next = now->next;
        now->next->prev = now->prev;
        dealloc_node(reinterpret_cast<node<T>*>(now));
        return iterator(ret.ptr);
    }

    // iterator erase(const_iterator it1, const_iterator it2) {
    //     return iterator(nullptr);
    // }

    void splice(const_iterator pos, list& other, const_iterator first, const_iterator last) {
        if (first == last)
            return;
        base_node<T>* p = pos.ptr;
        base_node<T> *f = first.ptr;
        base_node<T> *l = last.ptr->prev;
        f->prev->next = l->next;
        l->next->prev = f->prev;
        p->prev->next = f;
        f->prev = p->prev;
        l->next = p;
        p->prev = l;
    }

    void push_front(T const& elem) {
        insert(begin(), elem);
    }

    void push_back(T const& elem) {
        insert(end(), elem);
    }

    void pop_back() {
        erase(--end());
    }

    void pop_front() {
        erase(begin());
    }

    T& front() {
        return *begin();
    }

    T const& front() const {
        return *begin();
    }

    T& back() {
        return *(--end());
    }

    T const& back() const {
        return *(--end());
    }

    void clear() {
        for (auto i = begin(); i != end(); i = erase(i)) {
        }
    }

    void cout() {
        for (auto i = begin(); i != end(); ++i) {
            std::cout << *i << " ";
        }
    }

    bool empty () const noexcept {
        return head.next == &head && head.prev == &head;
    }

    void swap(list& other) {
        auto v1 = head;
        auto v2 = other.head;
        auto l1 = v1.prev;
        auto r1 = v1.next;
        auto l2 = v2.prev;
        auto r2 = v2.next;
        std::swap(l1->next, l2->next);
        std::swap(r1->prev, r2->prev);
        std::swap(head, other.head);
    }
};

template<typename C>
void swap(list<C> & a, list<C>& b) {
    a.swap(b);
}

#endif //LIST_LIST_H
