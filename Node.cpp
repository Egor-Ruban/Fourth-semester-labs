//
// Created by compucter on 24.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include "Utils.h"
#include "Node.h"

Node::Node(int layers, int notLessThan, int notMoreThan) {
    //std::cout<<"start "<<layers<<" "<<notLessThan<<" "<<notMoreThan<<std::endl;
    if(notLessThan == notMoreThan){
        value = notLessThan;
    } else {
        this->value = notLessThan + rand()%(int)(notMoreThan - notLessThan);
    }
    std::cout << "key " << value << " layer " << layers << std::endl;
    if(layers != 1) {
        this->left = new Node(layers - 1, notLessThan - pow(2, layers - 1), value - 1);
        this->right = new Node(layers - 1, value + pow(2,layers - 1), notMoreThan - 1);
    } else {
        left = nullptr;
        right = nullptr;
    }
    std::cout<<this<<" "<<this->value<<' '<<this->left<<" "<<this->right<<std::endl;
}

Node::~Node() {

    std::cout<<"destruction "<<this<<std::endl;
}
