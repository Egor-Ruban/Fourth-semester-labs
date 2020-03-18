//
// Created by Egor-Ruban on 10.03.2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include "BigInteger.h"
#include "Utils.h"

BigInteger::BigInteger(ConstructorTypes type, int availableCoefficients) {
    switch(type){
        case Default: //конструктор, создает один нулевой коэффициент
            availableCoefficients = 1;
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = 0;
            }
            break;
        case Empty: //конструктор, создает availableCoefficients нулевых коэффициентов
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = 0;
            }
            break;
        case Random: //конструктор, создает availableCoefficients случайных коэффициентов
            std::srand(unsigned(std::time(0)));
            coefficients = new BASE[availableCoefficients];
            for(int i = 0; i<availableCoefficients; i++){
                coefficients[i] = std::rand();
            }
            break;
    }
    this->availableCoefficients = availableCoefficients;
}

BigInteger::BigInteger(const BigInteger& object) { //конструктор копирования
    availableCoefficients = object.availableCoefficients;
    coefficients = new BASE[availableCoefficients];
    for(int i = 0; i<this->availableCoefficients; i++){
        coefficients[i] = object.coefficients[i];
    }
}

BigInteger::~BigInteger() { //деструктор
    if(coefficients != nullptr) {
        delete[](coefficients);
        coefficients = nullptr;
    }
}

std::ostream &operator<<(std::ostream &out, const BigInteger& object) { //вывод в hex`е
    bool isDeleteZero = true; //флаг, покеазывающий надо ли пропускать нули (в начале числа)
    for(int i = 0; i<object.availableCoefficients; i++){
        if((object.coefficients[i] != 0 && isDeleteZero) || !isDeleteZero) { //пустые коэффициенты пропускает
            for (int j = (BASE_SIZE) - 4; j >= 0; j -= 4) {
                unsigned char symbol = (object.coefficients[i] >> j) & 15; //вывожу посимвольно. можно покоэффициентно
                if((isDeleteZero && symbol != 0) || !isDeleteZero){         //но мне так спокойнее
                    out << hex[symbol];
                    isDeleteZero = false;
                }
            }
        }
    }
    if(isDeleteZero) out << 0; //если не вывелось ничего, то число - ноль
    return out;
}

std::istream &operator>>(std::istream &in, BigInteger& object) { //ввод в hex`е
    std::string rawHexInteger;
    std::cin>>rawHexInteger;
    int newCoefficientsAmount; //сколько коэффициентов нам необходимо для хранения такого числа
    if((rawHexInteger.size() * 4 % (BASE_SIZE)) == 0) {
        newCoefficientsAmount = (rawHexInteger.size() * 4) / (BASE_SIZE);
    } else {
        newCoefficientsAmount = ((rawHexInteger.size() * 4) / (BASE_SIZE)) + 1;
    }

    object = BigInteger(BigInteger::Empty, newCoefficientsAmount);
    int coefficientToWrite = object.availableCoefficients - 1; //итератор, показывает какой коэффициент в числе мы пишем
    unsigned int shift = 0; //показывает на сколько нам необходимо сдвигать символ
    for(int i = rawHexInteger.size() - 1; i >= 0; i--){
        if(shift == (BASE_SIZE)){ //если коэффициент заполнен (сдвигать некуда), то берем новый коэффициент
            shift = 0;
            coefficientToWrite--;
        }
        unsigned int newPart = hexToInteger(rawHexInteger[i]) << shift; //hex символ 4-мя битами в нужном месте
        object.coefficients[coefficientToWrite] |= newPart; //добавление символа в число
        shift+=4;
    }
    return in;
}

int BigInteger::compare(const BigInteger &object) {
    int thisNumberSize = this->availableCoefficients - this->countEmptyPlaces(); //кол-во значащих коэффициентов
    int objectNumberSize = object.availableCoefficients - object.countEmptyPlaces(); //кол-во значащих коэффициентов

    if(thisNumberSize > objectNumberSize){
        return 1;
    }
    if(objectNumberSize > thisNumberSize) {
        return -1;
    }
    int firstCoefficient = this->countEmptyPlaces();
    int secondCoefficient = object.countEmptyPlaces();
    for(int i = firstCoefficient, j = secondCoefficient; i < this->availableCoefficients; i++, j++){ //покоэффициентное сравнение
        if(this->coefficients[i] > object.coefficients[j]) return 1;
        if(this->coefficients[i] < object.coefficients[j]) return -1;
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
    return this->compare(object) >= 0 ;
}

bool BigInteger::operator<=(const BigInteger &object) {
    return  this->compare(object) <= 0;
}

bool BigInteger::operator==(const BigInteger &object) {
    return this->compare(object) == 0;
}

bool BigInteger::operator!=(const BigInteger &object) {
    return this->compare(object) != 0;
}

BigInteger BigInteger::operator+(const BigInteger &object) { //некрасивое сложение
    BiggerThanBASE sumOfCoefficients = 0;
    int maxSize = std::max(object.availableCoefficients, this->availableCoefficients);
    int thisCurrent = this->availableCoefficients - 1; //индекс элемента в this
    int objectCurrent = object.availableCoefficients - 1; //индекс элемента в object
    int sumCurrent = maxSize; //индекс элемента в результате
    BigInteger sumResult = BigInteger(ConstructorTypes::Empty, maxSize + 1);
    while(std::min(thisCurrent,objectCurrent) >= 0){ //складываем, пока в наименьшем числе есть что складывать
        sumOfCoefficients += this->coefficients[thisCurrent] + object.coefficients[objectCurrent];
        sumResult.coefficients[sumCurrent] = sumOfCoefficients;
        sumOfCoefficients >>= BASE_SIZE; //сохраняет перенос
        thisCurrent--;
        objectCurrent--;
        sumCurrent--;
    }
    if(std::min(thisCurrent, objectCurrent) == thisCurrent){ //больше if`ов богу if`ов
        while(objectCurrent >= 0){ //складываем оставшуюся часть большего числа с переносом
            sumOfCoefficients += 0 + object.coefficients[objectCurrent];
            sumResult.coefficients[sumCurrent] = sumOfCoefficients;
            sumOfCoefficients = sumOfCoefficients >> BASE_SIZE;
            objectCurrent--;
            sumCurrent--;
        }
    } else {
        while(thisCurrent >= 0){   //складываем оставшуюся часть большего числа с переносом
            sumOfCoefficients += 0 + this->coefficients[thisCurrent];
            sumResult.coefficients[sumCurrent] = sumOfCoefficients;
            sumOfCoefficients = sumOfCoefficients >> BASE_SIZE;
            thisCurrent--;
            sumCurrent--;
        }
    }
    sumResult.coefficients[sumCurrent] = sumOfCoefficients; //если сумма оказалась больше начальных чисел, то вот
    return sumResult;
}

int BigInteger::countEmptyPlaces() const { //возвращает колличество нулей в начале
    int result = 0;
    for(int i = 0; i < availableCoefficients; i++){
        if(coefficients[i] == 0){
            result++;
        } else {
            break;
        }
    }
    return 0;
}

BigInteger BigInteger::operator+=(const BigInteger &object) {
    BigInteger sum = this->operator+(object);
    *this = sum;
    return *this;
}

BigInteger& BigInteger::operator=(const BigInteger &object) {
    if(this != &object) {
        this->availableCoefficients = object.availableCoefficients;
        this->coefficients = new BASE[this->availableCoefficients];
        for (int i = 0; i < availableCoefficients; i++) {
            this->coefficients[i] = object.coefficients[i];
        }
    }
    return *this;
}

BigInteger BigInteger::operator*(const BASE &secondFactor) {
    BigInteger result = BigInteger(Empty,availableCoefficients + 1);
    BiggerThanBASE residueKeeper = 0; //хранит перенос
    for(int i = result.availableCoefficients; i >= 0; i--){
        BASE firstFactor;
        if(i == 0) firstFactor = 0;
        else firstFactor = this->coefficients[i-1];
        residueKeeper += firstFactor * secondFactor;
        result.coefficients[i] = residueKeeper;
        residueKeeper>>=(BASE_SIZE);
    }
    return result;
}

BigInteger BigInteger::operator*(const BigInteger &object) {
    int indent = 0; //показывает, сколько нулей нужно добавить в конце числа
    BigInteger result;
    for(int i = object.availableCoefficients - 1; i >= 0; i--){
        result += (this->operator*(object.coefficients[i])).addIndent(indent); //умножение столбиком
        indent++;
    }
    return result;
}

BigInteger BigInteger::addIndent(int indentSize) { //создает новый объект, равный данному, но с добавленными в конец 0
    BigInteger result = BigInteger(Empty, this->availableCoefficients + indentSize);
    for(int i = 0; i < this->availableCoefficients; i++){
        result.coefficients[i] = this->coefficients[i];
    }
    return result;
}

BigInteger BigInteger::operator*=(const BASE &secondFactor) {
    BigInteger result = this->operator*(secondFactor);
    *this = result;
    return *this;
}

BigInteger BigInteger::operator*=(const BigInteger &object) {
    BigInteger result = this->operator*(object);
    *this = result;
    return *this;
}

BigInteger BigInteger::operator-(const BigInteger &object) {
    BigInteger biggerInteger; //необходимо на случай, если первое число будет меньше - оператор вернет модуль разности
    BigInteger lesserInteger; //аналогично
    if(*this >= object) {
        biggerInteger = *this;
        lesserInteger = object;
    }
    else {
        lesserInteger = *this;
        biggerInteger = object;
    }
    BigInteger result = BigInteger(Empty, biggerInteger.availableCoefficients);
    int difference = biggerInteger.availableCoefficients - lesserInteger.availableCoefficients; //необходимо для итератора
    int transfer = 0; //показывает, берем ли мы единичку в старшем разряде
    for(int iBigger = biggerInteger.availableCoefficients - 1; iBigger >= 0; iBigger--){
        BiggerThanBASE minuend = biggerInteger.coefficients[iBigger] - transfer; //уменьшаемое
        BiggerThanBASE subtrahend; //вычитаемое
        if(iBigger - difference < 0) subtrahend = 0; //если коэффициенты кончились, то ноль
        else subtrahend = lesserInteger.coefficients[iBigger - difference];

        if(minuend < subtrahend){
            result.coefficients[iBigger] = minuend + pow(2, BASE_SIZE) - subtrahend; //pow - заимствование у старшего
            transfer = 1;
        } else {
            result.coefficients[iBigger] = minuend - subtrahend;
            transfer = 0;
        }
    }
    return result;
}

BigInteger BigInteger::operator-=(const BigInteger &object) {
    BigInteger result = this->operator-(object);
    *this = result;
    return *this;
}

BigInteger BigInteger::operator/(const BASE &divider) {
    BigInteger result = BigInteger(Empty, this->availableCoefficients);
    int residue = 0;
    for(int i = 0; i < this->availableCoefficients; i++){
        BiggerThanBASE dividend = this->coefficients[i] + residue * BASE_SIZE;
        result.coefficients[i] = dividend / divider;
        residue = dividend % divider;
    }
    return result;
}


