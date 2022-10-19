//
// Created by chris on 8/10/2022.
//

#ifndef SKIPLIST_CH_SKIP_LIST_H
#define SKIPLIST_CH_SKIP_LIST_H

#include "skip_list_node.h"
#include <random>
#include <functional>

template<class ElemType>
class SkipList {
public:
    explicit SkipList(int max_lvl);

    bool get_random_bool();

    bool insert(ElemType key);

    bool erase(ElemType key);

    node<ElemType> *find(std::vector<node<ElemType> *> *predecessor, ElemType key);

    void print();

    node<ElemType> header;  // header(max_lvl, key=infinito)
    int current_lvl;        // 1
    int max_lvl;            // n
};

template<class ElemType>
SkipList<ElemType>::SkipList(int max_lvl)
        : max_lvl(max_lvl), header(max_lvl, -1), current_lvl(1) {}

template<class ElemType>
bool SkipList<ElemType>::get_random_bool() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, 1);
    return distribution(gen);
}

template<class ElemType>
void SkipList<ElemType>::print() {
    typedef node<ElemType> *nd_p;
    using std::cout, std::endl;

    nd_p it = &header;
    for (int j = 0; j <= max_lvl - 1; j++) {
        cout << "[" << j << "]";
    }
    cout << endl;
    while (it->forward[0] != nullptr) {
        for (unsigned int i = 0; i < it->forward.size(); i++) {
            if (it->forward[i] != nullptr)
                std::cout << " " << it->forward[i]->key << " ";
        }
        std::cout << std::endl;
        it = it->forward[0];
    }
    cout << endl;
    nd_p p = &header;
    for (int i = max_lvl - 1; i >= 0; i--) {
        cout << "[" << i << "] -> ";
        if (p->forward[i] == nullptr) {
            cout << "NIL" << endl;
        } else {
            nd_p q = p->forward[i];
            while (q != nullptr) {
                cout << q->key << " ";
                q = q->forward[i];
            }
            cout << endl;
        }
    }
    cout << "-H-" << endl;
}

template<class ElemType>
node<ElemType> *SkipList<ElemType>::find(std::vector<node<ElemType> *> *predecessor, ElemType key) {
    predecessor->resize(max_lvl, nullptr);
    node<ElemType> *it = &header;
    for (int i = current_lvl - 1; 0 <= i; --i) {
        while (it->forward[i] != nullptr && it->forward[i]->key < key) {
            it = it->forward[i];
        }
        (*predecessor)[i] = it;
    }
    it = it->forward[0];

    return it;
}

template<class ElemType>
bool SkipList<ElemType>::insert(ElemType key) {
    std::vector<node<ElemType> *> predecessor;
    node<ElemType> *it = find(&predecessor, key);

    if (it != nullptr && it->key == key) {
        return false;
    }

    unsigned int level = 1;
    while (get_random_bool() == true && level < max_lvl) {
        ++level;
    }

    if (current_lvl < level) {
        predecessor[current_lvl] = &header;
        level = ++current_lvl;
    }

    auto *new_node = new node<ElemType>(level, ElemType(key));
    for (unsigned int i = 0; i < level; ++i) {
        new_node->forward[i] = predecessor[i]->forward[i];
        predecessor[i]->forward[i] = new_node;
    }

    return true;
}

template<class ElemType>
bool SkipList<ElemType>::erase(ElemType key) {
    std::vector<node<ElemType> *> predecessor;
    node<ElemType> *it = find(&predecessor, key);

    if (it != nullptr and it->key == key) {
        for (int i = 0; i <= current_lvl - 1; i++) {
            if (predecessor[i]->forward[i] != it)
                break;
            predecessor[i]->forward[i] = it->forward[i];
        }

        while (current_lvl - 1 > 0 && header.forward[current_lvl - 1] == 0) {
            current_lvl--;
        }
        std::cout << "Successfully deleted key " << key << "\n";
        return true;
    } else {
        return false;
    }
}


#endif //SKIPLIST_CH_SKIP_LIST_H
