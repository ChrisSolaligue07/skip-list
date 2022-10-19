#include <iostream>
#include <vector>
#include "skip_list.h"

int main() {
    SkipList<int> sl(5);
    sl.insert(3);
    sl.insert(4);
    sl.insert(6);
    sl.insert(8);
    sl.insert(9);
    sl.insert(10);
    sl.print();
    sl.erase(8);
    sl.print();
    return 0;
}
