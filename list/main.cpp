#include <iostream>
#include "list.h"

int main() {
    list<int> l;
    l.insert(l.begin(), 1);
    l.insert(l.begin(), 2);
    l.insert(l.begin(), 3);
    l.insert(++l.begin(), 4);
    l.erase(++l.begin());
    l.cout();
}