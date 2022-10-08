#include <iostream>
#include <vector>
#include "skip_list.h"

int main() {
    SkipList<int> sl(5);
    using std::cout, std::endl;
    cout << sl.header.key << endl;
    cout << sl.current_lvl << endl;
    cout << sl.max_lvl << endl;
    cout << sl.header.forward.size() << endl;
    return 0;
}
