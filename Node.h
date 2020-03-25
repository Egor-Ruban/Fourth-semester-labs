//
// Created by compucter on 24.03.2020.
//

#ifndef SEARCHTREE_NODE_H
#define SEARCHTREE_NODE_H


class Node {
public:
    Node* left;
    Node* right;
    Node* parent;
    int value;
    Node(int layers, int notLessThan , int notMoreThan, Node* parent = nullptr);//полное дерево высотой layers огранич. в root
    Node(int valueOfRoot = 0, Node* parent = nullptr);
    Node(Node& object);

    ~Node();

    Node& operator=(const Node& object);

    Node* findValue(int value);
    void insertValue(int value);
    void deleteNode(Node*& object);
    int getMinValue();
    int getMaxValue();
    void printByLayers();
};


#endif //SEARCHTREE_NODE_H
