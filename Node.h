//
// Created by compucter on 24.03.2020.
//

#ifndef SEARCHTREE_NODE_H
#define SEARCHTREE_NODE_H


class Node {
public:
    Node* left;
    Node* right;
    int value;
    Node(int layers = 4, int notLessThan = 32, int notMoreThan = 200);//полное дерево высотой layers огранич. в root
};


#endif //SEARCHTREE_NODE_H
