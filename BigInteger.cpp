//
// Created by compucter on 10.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BigInteger.h"
#include "Utils.h"

BigInteger::BigInteger(ConstructorTypes type, int availableCoefficients) {
    switch(type){
        case Default:
            availableCoefficients = 1;
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = 0;
            }
            break;
        case Empty:
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = 0;
            }
            break;
        case Random:
            std::srand(unsigned(std::time(0)));
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = std::rand();
            }
            break;
    }
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
        bool isSkipZero = true;;
        for(int j = (BASE_SIZE) - 4 ; j >= 0; j -= 4){
            unsigned char symbol = (object.coefficients[i] >> j) & 15;
            if(!(symbol == 0 && isSkipZero)){
                out<<hex[symbol];
                isSkipZero = false;
            }
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, BigInteger& object) {
    std::string rawHexInteger;
    std::cin>>rawHexInteger;
    std::string hexInteger = cutUnusedSymbols(rawHexInteger);
    int newSymbolsAmount;
    int i = 0;
    if((hexInteger.size() * 4%(BASE_SIZE)) == 0) {
        newSymbolsAmount = (hexInteger.size() * 4)/(BASE_SIZE);
    } else {
        newSymbolsAmount = ((hexInteger.size() * 4)/(BASE_SIZE)) + 1;
    }

    object.usedCoefficients = newSymbolsAmount;
    object.availableCoefficients = newSymbolsAmount;
    object.coefficients = new BASE[newSymbolsAmount];

    int currentCoefficient = -1;
    int shift = (BASE_SIZE);
    for(char hexSymbol : hexInteger){
        if(shift == (BASE_SIZE)){
            currentCoefficient++;
            object.coefficients[currentCoefficient] = 0;
            shift = 0;
        }
        int newPart;
        newPart = hexToInteger(hexSymbol);
        object.coefficients[currentCoefficient] = (object.coefficients[currentCoefficient] << 4) | newPart;
        shift += 4;
    }
    return in;
}

int BigInteger::compare(const BigInteger &object) {
    if(this->usedCoefficients > object.usedCoefficients){
        return 1;
    }
    if(object.usedCoefficients > this->usedCoefficients){
        return -1;
    }
    for(int i = 0; i<object.usedCoefficients; i++){
        if(this->coefficients[i] > object.coefficients[i]) return 1;
        if(this->coefficients[i] < object.coefficients[i]) return -1;
    }
    return 0;
}

bool BigInteger::operator>(const BigInteger &object) {
    return this->compare(object) == 1;
}

bool BigInteger::operator<(const BigInteger &object) {
    return this->compare(object) == -1;
}

bool BigInteger::operator>=(const BigInteger &object) {
    return *this>object | *this==object;
}

bool BigInteger::operator<=(const BigInteger &object) {
    return  *this<object | *this==object;
}

bool BigInteger::operator==(const BigInteger &object) {
    return this->compare(object) == 0;
}

bool BigInteger::operator!=(const BigInteger &object) {
    return  *this>object | *this<object;
}


