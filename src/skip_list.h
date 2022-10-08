//
// Created by chris on 8/10/2022.
//

#ifndef SKIPLIST_CH_SKIP_LIST_H
#define SKIPLIST_CH_SKIP_LIST_H

template<class ElemType>
class SkipList {
public:
    struct node {
        std::vector<node *> forward;
        ElemType key; //  key
        node(int lvl, const ElemType &value);
    };

    explicit SkipList(int max_lvl);

    node header;
    int current_lvl;
    int max_lvl;
};

template<class ElemType>
SkipList<ElemType>::SkipList(int max_lvl)
: max_lvl(max_lvl), header(max_lvl, ElemType()), current_lvl(1) {}

template<class ElemType>
SkipList<ElemType>::node::node(int lvl, const ElemType &value_)
: key(value_), forward(lvl, nullptr) {}


#endif //SKIPLIST_CH_SKIP_LIST_H
