#include <iostream>
#include "Node.h"
#include <ctime>
#include <cmath>

int main() {
    int* values = new int[15]{89,64,78,58,65,3,72,82,44,7,10,49,97,76,71};
    std::srand(unsigned(std::time(0)));
    int* valuesBalanced = new int[6]{50,40,60,30,45,70};
    Node h(valuesBalanced, 6);
    h.printByLayers();
    h.findAndDelete(50);
    h.printByLayers();
    //h.findAndDeleteChallenge(64);
   // h.printByLayers();
    //std::cout<<"\n"<<h.isBalanced()<<std::endl;
    //std::cout<<h.getMinValue()<<std::endl;
    //std::cout<<h.getMaxValue()<<std::endl;
    return 0;
}

    //todo  *ДОПОЛНИТЕЛЬНО на 5* построение дерева на основе добавления узла с балансировкой