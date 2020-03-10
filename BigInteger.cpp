//
// Created by compucter on 10.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BigInteger.h"

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

BigInteger::BigInteger(BigInteger& object) {
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
