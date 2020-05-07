//
// Created by compucter on 08.04.2020.
//

#include <iostream>
#include "Tree.h"

Node *Tree::findValue(int value) {
    if(root == nullptr) return nullptr;
    return root->findValue(value);
}

void Tree::insertValue(int value) {
    if(root == nullptr) root = new Node(value);
    else root->insertValue(value);
}

void Tree::deleteNode(Node *&object) {
    if(root == object){
        if(root->left == nullptr && root->right == nullptr){
            delete(root);
            root = nullptr;
        } else if(root->left == nullptr && root->right != nullptr){
            root = root->right;
            root->parent = nullptr;
            object->left = nullptr;
            object->right = nullptr;
            delete (object);
        } else if(root->left != nullptr && root->right == nullptr){
            root = root->left;
            root->parent = nullptr;
            object->left = nullptr;
            object->right = nullptr;
            delete (object);
        } else {
            Node *temp = object->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            temp->left = object->left;
            if(object->right == temp) temp->right = nullptr;
            else temp->right = object->right;
            object->right->parent = temp;
            if (temp->parent->left == temp) temp->parent->left = nullptr;
            else temp->parent->right = nullptr;
            temp->parent = nullptr;
            temp->right = object->right;
            object->left = nullptr;
            object->right = nullptr;
            root = temp;
            delete (object);
        }
    } else {
        root->deleteNode(object);
    }
}

void Tree::findAndDelete(int value) {
    root->findAndDelete(value);
}

int Tree::getMinValue() {//нет обработки на пустое дерево, потому, что понятия не имею, что делать с пустым деревом
    return root->getMinValue();
}

int Tree::getMaxValue() {
    return root->getMaxValue();
}

void Tree::printByLayers() {
    if(root == nullptr) std::cout<<std::endl;
    else root->printByLayers();
}

void Tree::recursivePrint() {
    if(root == nullptr) std::cout<<std::endl;
    else root->recursivePrint();
}

Node *Tree::findParentByValue(int value) {
    if(root == nullptr) return nullptr;
    else return root->findParentByValue(value);
}

int Tree::getHeight() {
    if(root == nullptr) return 0;
    return root->getHeight();
}

bool Tree::isBalanced() {
    if(root == nullptr) return true;
    return root->isBalanced();
}

Tree::Tree(int valueOfRoot) {
    root = new Node(valueOfRoot, nullptr);
}

Tree::Tree(int *values, int amount) {
    if(amount == 0){
        root = nullptr; //пустое дерево, уху
    } else {
        root = new Node(values, amount);
    }
}

Tree::Tree(Tree &object) {
    if(object.root == nullptr) root = nullptr;
    else root = new Node(*object.root);
}

Tree::~Tree() {
    if(root != nullptr) delete(root);
}

Tree &Tree::operator=(const Tree &object) {
    if (this != &object){
        delete(root);
        this->root = new Node(*object.root);
    }
}
