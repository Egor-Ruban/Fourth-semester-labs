#include <iostream>
#include "Node.h"
#include <ctime>
#include <cmath>

int main() {
    std::srand(unsigned(std::time(0)));
    Node h(4, pow(2, 5), 200);
    int f = h.left->value + 1;
    std::cout<<h.findValue(f)<<" "<<h.left<<std::endl;
    h.insertValue(f);
    std::cout<<h.findValue(f)<<" "<<h.left<<std::endl;
    Node* g = h.findValue(f);
    h.deleteNode(g);
    std::cout<<h.findValue(f)<<" "<<h.left<<std::endl;
    return 0;
}

    //todo минимум и максимум
    //todo обход по уровням
    //todo обход по выбору: ЛПК, КЛП, КПЛ

    //todo  *ДОПОЛНИТЕЛЬНО на 5* построение дерева на основе добавления узла с балансировкой