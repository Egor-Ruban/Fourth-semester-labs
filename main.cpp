#include <iostream>
#include "Node.h"
#include "Tree.h"
#include <ctime>
#include <cmath>

int main() {
    int* values = new int[15]{89,64,78,58,65,3,72,82,44,7,10,49,97,76,71};
    std::srand(unsigned(std::time(0)));
    int* valuesBalanced = new int[6]{50,40,60,30,45,70};
    Tree test(values, 15);
    std::cout<<"test 1 "<<test.findValue(64)<<std::endl; // существует
    std::cout<<"test 2 "<<test.findValue(67)<<std::endl; // не существует
    test.insertValue(67);
    std::cout<<"test 3 "<<test.findValue(67)<<std::endl;
    test.findAndDelete(67);
    std::cout<<"test 4 "<<test.findValue(67)<<std::endl;
    std::cout<<"test 5 "<< test.getMinValue()<<std::endl;
    std::cout<<"test 6 "<< test.getMaxValue()<<std::endl;
    std::cout<<"test 7 "<<std::endl;
    test.printByLayers();
    std::cout<<"\ntest 8 "<<std::endl;
    test.recursivePrint();
    std::cout<<"\ntest 9 "<< test.getHeight()<<std::endl;
    std::cout<<"test 10 "<< test.isBalanced()<<std::endl;
    return 0;
}

    //todo  *ДОПОЛНИТЕЛЬНО на 5* построение дерева на основе добавления узла с балансировкой