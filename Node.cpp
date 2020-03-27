//
// Created by compucter on 24.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <queue>
#include "Utils/Utils.h"
#include "Node.h"

Node::Node(int layers, int notLessThan, int notMoreThan, Node* parent, bool isFirstIt) {
    this->parent = parent;
    if(notLessThan == notMoreThan){
        value = notLessThan;
    } else {
        this->value = notLessThan + rand()%(int)(notMoreThan - notLessThan);
    }
    if(isFirstIt) this->value = 2*notLessThan + rand()%(int)(notMoreThan/2 - 2*notLessThan);
    //std::cout<<"layer: "<<layers<<" value: "<<value<<" nmt "<<notMoreThan<<" nlt "<<notLessThan<<std::endl;
    if(layers != 1) {
        this->left = new Node(layers - 1,
                notLessThan - pow(2, layers - 2),
                value - 1,
                this,
                false
                );
        this->right = new Node(layers - 1,
                value + pow(2,layers - 2),
                notMoreThan - 1,
                this,
                false
                );
    } else {
        left = nullptr;
        right = nullptr;
    }

}

Node::~Node() {
    delete(this->left);
    delete(this->right);
}

Node::Node(int valueOfRoot, Node* parent) {
    this->value = valueOfRoot;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = parent;
}

Node::Node(Node &object) {
    this->parent = object.parent;
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

Node &Node::operator=(const Node &object) {
    this->parent = object.parent;
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
    return *this;
}

Node *Node::findValue(int value) {
    if(this->value == value){
        return this;
    }
    if(value < this->value){
        if(this->left == nullptr){
            return nullptr;
        } else {
            return this->left->findValue(value);
        }
    }
    if(value > this->value){
        if(this->right == nullptr){
            return nullptr;
        } else {
            return this->right->findValue(value);
        }
    }
    return nullptr;
}

void Node::insertValue(int value) {
    if(value == this->value) return;
    if(value < this->value){
        if(this->left == nullptr){
            this->left = new Node(value, this);
        } else {
            this->left->insertValue(value);
        }
    }
    if(value > this->value){
        if(this->right == nullptr){
            this->right = new Node(value, this);
        } else {
            this->right->insertValue(value);
        }
    }
}

void Node::deleteNode(Node *&object) {
    if(object->left == nullptr && object->right == nullptr){
        if(object->parent->left == object) object->parent->left = nullptr;
        else object->parent->right = nullptr;
        delete(object);
    } else if(object->left != nullptr && object->right == nullptr){
        if(object->parent->left == object) object->parent->left = object->left;
        else object->parent->right = object->left;
        object->right = nullptr;
        delete(object);
    } else if(object->left == nullptr && object->right != nullptr){
        if(object->parent->left == object) object->parent->left = object->right;
        else object->parent->right = object->right;
        object->left = nullptr;
        delete(object);
    } else if(object->left != nullptr && object->right != nullptr){
        Node* temp = object->right;
        while(temp->left != nullptr){
            temp = temp->left;
        }
        temp->left = object->left;
        if(object->parent->left == object) object->parent->left = object->right;
        else object->parent->right = object->right;
        object->left = nullptr;
        object->right = nullptr;
        delete(object);
    }
}

int Node::getMinValue() {
    if(this->left == nullptr) return this->value;
    else {
        Node* temp = this->left;
        while(temp->left != nullptr) temp = temp->left;
        return temp->value;
    }
}

int Node::getMaxValue() {
    if(this->right == nullptr) return this->value;
    else {
        Node* temp = this->right;
        while(temp->right != nullptr) temp = temp->right;
        return temp->value;
    }
}

void Node::printByLayers() {
    std::queue<Node*> queue;
    queue.push(this);
    while(!queue.empty()){
        Node* temp = queue.front();
        queue.pop();
        if(temp->left != nullptr) queue.push(temp->left);
        if(temp->right != nullptr) queue.push(temp->right);
        std::cout << temp->value << ",";
    }
}

void Node::recursivePrint() {
    std::cout<<this->value<<",";
    if(this->left != nullptr) this->left->recursivePrint();
    if(this->right != nullptr) this->right->recursivePrint();
}

Node::Node(int *values, int amount) {
    if(amount > 0) {
        this->value = values[0];
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        for(int i = 1; i < amount; i++){
            this->insertValue(values[i]);
        }
    } else {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
}
