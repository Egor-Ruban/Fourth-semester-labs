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

    //почти случайно строит первое полное бинарное дерево поиска
    Node(int layers, int notLessThan , int notMoreThan, Node* parent = nullptr, bool isFirstIt = true);
    //строит узел без последователей
    Node(int valueOfRoot = 0, Node* parent = nullptr);
    //строит дерево поиска по массиву
    Node(int* values, int amount);
    //копирование
    Node(Node& object);

    ~Node();

    Node& operator=(const Node& object);

    Node* findValue(int value); //найти значение и вернуть адрес его узела
    void insertValue(int value); //добавить значение в дерево
    void deleteNode(Node*& object); //удалить узел
    void findAndDelete(int value); //удалить значение
    void findAndDeleteChallenge(int value);
    int getMinValue(); //минимальное значение (крайний левый лист)
    int getMaxValue(); //максимальное значение (крайнйи правый лист)
    void printByLayers(); //вывод по уровням
    void recursivePrint(); //обход влево в глубину (КЛП вроде)

    int getHeight();
    bool isBalanced();
};


#endif //SEARCHTREE_NODE_H
