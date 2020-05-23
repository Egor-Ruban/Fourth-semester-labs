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
    //плохой конструктор. есть просто потому, что я на него потратил времени больше, чем на все остальное вместе взятое
    this->parent = parent;
    //создание value, исходя из ограничений
    if(notLessThan == notMoreThan){
        value = notLessThan;
    } else {
        this->value = notLessThan + rand()%(int)(notMoreThan - notLessThan);
    }
    //дял первого используются более жесткие ограничения, чтоб случайно не сгенерировалось значение, близкое к краю
    if(isFirstIt) this->value = 2*notLessThan + rand()%(int)(notMoreThan/2 - 2*notLessThan);
    //создает левого и правого потомка, если надо
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

//поле value удаляется аатоматически, но нужно вызвать удаление для всех потомков
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
    this->value = object.value;
    if(object.left != nullptr) {
        this->left = new Node(*object.left);
        this->left->parent = this;
    } else {
        this->left = nullptr;
    }
    if(object.right != nullptr) {
        this->right = new Node(*object.right);
        this->right->parent = this;
    } else {
        this->right = nullptr;
    }
}

Node &Node::operator=(const Node &object) {
    if (this != &object) {
        delete(this->left);
        delete(this->right);
        this->value = object.value;
        if (object.left != nullptr) {
            this->left = new Node(*object.left);
            this->left->parent = this;
        } else {
            this->left = nullptr;
        }
        if (object.right != nullptr) {
            this->right = new Node(*object.right);
            this->right->parent = this;
        } else {
            this->right = nullptr;
        }
    }
    return *this;
}

//рекурсивно ищет в поддеревьях нужное значение. если не находит - возвращает nullptr
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
    //если значение существует, то ничего не делает, иначе рекурсивно ищет в поддеревьях место для значения
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

//по алгоритму из лекции
//если нет потомков, то просто удаляет
//если один потомок, то сдвигает его повыше
//если два потомка, то немного перестраивает их
void Node::deleteNode(Node *&object) {
    if(object->parent != nullptr) {
        if (object->left == nullptr && object->right == nullptr) {
            if (object->parent->left == object) object->parent->left = nullptr;
            else object->parent->right = nullptr;
            delete (object);
        } else if (object->left != nullptr && object->right == nullptr) {
            if (object->parent->left == object) object->parent->left = object->left;
            else object->parent->right = object->left;
            object->left->parent = object->parent;
            object->left = nullptr;
            delete (object);
        } else if (object->left == nullptr && object->right != nullptr) {
            if (object->parent->left == object) object->parent->left = object->right;
            else object->parent->right = object->right;
            object->right->parent = object->parent;
            object->right = nullptr;
            delete (object);
        } else if (object->left != nullptr && object->right != nullptr) {
            Node *temp = object->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            temp->left = object->left; //перенос левого поддерева удаляемого узла
            temp->left->parent = temp;

            if(object->right != temp){
                object -> right -> parent = temp;
                temp->parent->left = temp->right;
                if(temp->right != nullptr) temp->right->parent = temp->parent;
                temp->right = object->right; // перенос правого поддерева удаляемого узла
            }

            temp->parent = object->parent;
            if (object->parent->left == object) object->parent->left = temp;
            else object->parent->right = temp;
            object->left = nullptr;
            object->right = nullptr;
            delete (object);
        }
    }
}

//идем налево до края и возвращаем крайнее левое значение
int Node::getMinValue() {
    if(this->left == nullptr) return this->value;
    else {
        Node* temp = this->left;
        while(temp->left != nullptr) temp = temp->left;
        return temp->value;
    }
}

//идем направо до края и возвращаем крайнее правое значение
int Node::getMaxValue() {
    if(this->right == nullptr) return this->value;
    else {
        Node* temp = this->right;
        while(temp->right != nullptr) temp = temp->right;
        return temp->value;
    }
}

//доабвляем корень в очередь. Доставая из очереди выводим значение и добавляем в очередь потомков
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

//выводим - идем в левое поддерево - идем в правое поддерево
void Node::recursivePrint() {
    if(this->left != nullptr) this->left->recursivePrint();
    if(this->right != nullptr) this->right->recursivePrint();
    std::cout<<this->value<<",";
}

//значение корня устанавливаем сами, а дальше вызываем функцию добавления значения
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

void Node::findAndDelete(int value) {
    Node* temp = this->findValue(value);
    this->deleteNode(temp);
}

int Node::getHeight() {
    int heightToLeft = 0;
    int heightToRight = 0;
    if(this->left != nullptr) heightToLeft = this->left->getHeight();
    if(this->right != nullptr) heightToRight = this->right->getHeight();
    if(heightToLeft > heightToRight) return heightToLeft + 1;
    return heightToRight + 1;
}

bool Node::isBalanced() {
    std::queue<Node*> queue;
    queue.push(this);
    while(!queue.empty()){
        Node* temp = queue.front();
        queue.pop();
        if(temp->left != nullptr) queue.push(temp->left);
        if(temp->right != nullptr) queue.push(temp->right);
        int heightToLeft = 0;
        int heightToRight = 0;
        if(temp->left != nullptr) heightToLeft = temp->left->getHeight();
        if(temp->right != nullptr) heightToRight = temp->right->getHeight();
        if(abs(heightToLeft - heightToRight) > 1) return false;
    }
    return true;
}

Node *Node::findParentByValue(int value) {
    Node* tempValue = this;
    Node* tempParent = this;// за счет этого оно в качестве родителя корня вернет корень
    while(true){ //рано или поздно что-то вернет
        if(tempValue == nullptr) return nullptr; //если не нашел значение - nullptr
        if(value > tempValue->value){
            tempParent = tempValue;
            tempValue = tempValue->right;
        } else if(value < tempValue->value) {
            tempParent = tempValue;
            tempValue = tempValue->left;
        } else return tempParent;
    }
}
