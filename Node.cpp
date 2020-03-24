//
// Created by compucter on 24.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include "Utils.h"
#include "Node.h"

Node::Node(int layers, int notLessThan, int notMoreThan) {//генерирует поддерево поиска, с ограниченным корнем
    if(notLessThan == notMoreThan){
        value = notLessThan;
    } else {
        this->value = notLessThan + rand()%(int)(notMoreThan - notLessThan);
    }
    if(layers != 1) {
        this->left = new Node(layers - 1, notLessThan - pow(2, layers - 1), value - 1);
        this->right = new Node(layers - 1, value + pow(2,layers - 1), notMoreThan - 1);
    } else {
        left = nullptr;
        right = nullptr;
    }
}

Node::~Node() {
    std::cout<<"destruction "<<this<<std::endl;
    delete(this->left);
    delete(this->right);
}

Node::Node(int valueOfRoot ) {
    this->value = valueOfRoot;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Node &object) {
    this->value = object.value;
    if(object.left != nullptr) {
        this->left = new Node(*object.left);
    } else {
        this->left = nullptr;
    }
    if(object.right != nullptr) {
        this->right = new Node(*object.right);
    } else {
        this->right = nullptr;
    }
}
