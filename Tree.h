//
// Created by compucter on 08.04.2020.
//

#ifndef SEARCHTREE_TREE_H
#define SEARCHTREE_TREE_H


#include "Node.h"

class Tree {
    Node* root;

    //строит дерево с одним числом
    Tree(int valueOfRoot = 0);
    //строит дерево поиска по массиву
    Tree(int* values, int amount);
    //копирование
    Tree(Tree& object);

    Tree& operator=(const Tree& object);

    Node* findValue(int value); //найти значение и вернуть адрес его узела
    void insertValue(int value); //добавить значение в дерево
    void deleteNode(Node*& object); //удалить узел
    void findAndDelete(int value); //удалить значение
    int getMinValue(); //минимальное значение (крайний левый лист)
    int getMaxValue(); //максимальное значение (крайнйи правый лист)
    void printByLayers(); //вывод по уровням
    void recursivePrint(); //обход влево в глубину (КЛП вроде)
    Node* findParentByValue(int value);

    int getHeight();
    bool isBalanced();
};


#endif //SEARCHTREE_TREE_H
