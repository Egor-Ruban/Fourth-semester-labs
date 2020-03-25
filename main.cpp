#include <iostream>
#include "Node.h"
#include <ctime>
#include <cmath>

int main() {
    std::srand(unsigned(std::time(0)));
    Node h(4, pow(2, 5), 200);
    std::cout<<h.getMinValue()<<std::endl;
    std::cout<<h.getMaxValue()<<std::endl;
    return 0;
}

    //todo минимум и максимум
    //todo обход по уровням
    //todo обход по выбору: ЛПК, КЛП, КПЛ

    //todo  *ДОПОЛНИТЕЛЬНО на 5* построение дерева на основе добавления узла с балансировкой