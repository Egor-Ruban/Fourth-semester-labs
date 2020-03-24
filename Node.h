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
    Node(int layers, int notLessThan , int notMoreThan);//полное дерево высотой layers огранич. в root
    Node(int valueOfRoot = 0);
    Node(Node& object);

    ~Node();
};


#endif //SEARCHTREE_NODE_H
