//
// Created by compucter on 10.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BigInteger.h"

char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

BigInteger::BigInteger(ConstructorTypes type, int availableCoefficients) {
    switch(type){
        case Default:
            availableCoefficients = 1;
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = 0;
                std::cout<<(int) coefficients[i];
            }
            break;
        case Empty:
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = 0;
                std::cout<<(int)coefficients[i]<<",";
            }
            break;
        case Random:
            std::srand(unsigned(std::time(0)));
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = std::rand();
                std::cout<<(int)coefficients[i]<<",";
            }
            break;
    }
    std::cout<<std::endl;
    this->availableCoefficients = availableCoefficients;
    this->usedCoefficients = availableCoefficients;
}

BigInteger::BigInteger(const BigInteger& object) {
    availableCoefficients = object.availableCoefficients;
    usedCoefficients = object.usedCoefficients;
    coefficients = new BASE[availableCoefficients];
    for(int i = 0; i<usedCoefficients; i++){
        coefficients[i] = object.coefficients[i];
    }
}

BigInteger::~BigInteger() {
    if(coefficients != nullptr) {
        delete[](coefficients);
        coefficients = nullptr;
    }
}

std::ostream &operator<<(std::ostream &out, const BigInteger& object) {
    for(int i = 0; i<object.usedCoefficients; i++){
        for(int j = BASE_SIZE - 4 ; j >= 0; j -= 4){
            unsigned char symbol = (object.coefficients[i] >> j) & 15;
            if(!(symbol == 0 && j == BASE_SIZE - 4)){
                out<<hex[symbol];
            }
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, const BigInteger& object) {
    return in;
}
