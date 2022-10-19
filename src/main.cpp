#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include "skip_list.h"


int get_random_int() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(gen);
}

int main() {
    /*SkipList<int> sl(8);
    std::vector<int> test;
    std::cout << "Insertando datos..." << std::endl;
    for (int i = 0; i < 50; i++) {
        int _rand = get_random_int();
        test.push_back(_rand);
        sl.insert(_rand);
    }
    std::cout << "Datos Insertados" << std::endl;
    std::cout << "Lista de datos que se quiso insertar ..." << std::endl;
    std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    sl.print();

    std::cout << "Eliminando datos." << std::endl;
    for (int i: test) {
        sl.erase(i);
    }
    std::cout << "Datos Eliminados" << std::endl;
    sl.print();*/

    SkipList<int> sl(12);
    std::vector<int> test;
    int first = 1, last = 1000;
    srand(time(nullptr));

    std::cout << "Insertando datos..." << std::endl;
    for (int i = 0; i < 1000; i++) {
        int _rand = rand() % (last + 1 - first) + first;
        test.push_back(_rand);
        sl.insert(_rand);
    }
    std::cout << "Datos Insertados" << std::endl;
    std::cout << "Lista de datos que se quiso insertar ..." << std::endl;
    std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    sl.print();
    std::cout << "Eliminando datos." << std::endl;
    for (int i: test) {
        sl.erase(i);
    }
    std::cout << "Datos Eliminados" << std::endl;
    sl.print();
    return 0;
}
