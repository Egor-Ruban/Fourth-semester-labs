#include <iostream>
#include "Node.h"
#include <ctime>
#include <cmath>

int main() {
    std::srand(unsigned(std::time(0)));
        Node h = Node(4, pow(2, 5), 200);
        Node* f = h.left;
        Node* g = f->left;
        std::cout<<"\n\n"<<f<<" "<<&h<<std::endl;
        std::cout<<f->value<<" "<<f->right->value<<std::endl;
    return 0;
}

    //todo конструкторы, деструктор, =
    //todo поиск узла по ключу
    //todo добавление узла
    //todo удаление узла
    //todo минимум и максимум
    //todo обход по уровням
    //todo обход по выбору: ЛПК, КЛП, КПЛ

    //todo  *ДОПОЛНИТЕЛЬНО на 5* построение дерева на основе добавления узла с балансировкой