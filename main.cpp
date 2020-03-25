#include <iostream>
#include "Node.h"
#include <ctime>
#include <cmath>
#include "Utils/Queue.h"

int main() {
    //fun();
    std::srand(unsigned(std::time(0)));
    Node h(4, pow(2, 5), 200);
    h.printByLayers();
    std::cout<<std::endl;
    h.recursivePrint();
    //std::cout<<h.getMinValue()<<std::endl;
    //std::cout<<h.getMaxValue()<<std::endl;
    return 0;
}

    //todo  *ДОПОЛНИТЕЛЬНО на 5* построение дерева на основе добавления узла с балансировкой