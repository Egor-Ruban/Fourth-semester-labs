//
// Created by compucter on 10.03.2020.
//

#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H

typedef unsigned char BASE;
#define BASE_SIZE = 8 * sizeof(BASE)

class BigInteger {

    BASE* coefficients;
    int usedCoefficients;
    int availableCoefficients;


public:
    enum ConstructorTypes{
        Default,
        Empty,
        Random
    };

    BigInteger(ConstructorTypes type = Default, int availableCoefficients = 1);

    //todo конструктор 1 по умолчанию (создает число 0; lenMax = 1)
    //todo конструктор 2 с параметром (lenMax передаем через параметр, и все цифры числа заполняем нулями)
    //todo конструктор 3 с параметрами (lenMax передаем через параметр и цифры заполняем случайными числами)
    //todo конструктор копирования
    //todo деструктор
    //todo 16-ый ввод и вывод
    //todo функция сравнения 2-х БЧ и, с ее использованием,
    //todo операции: >,<,>=,<=,==,!=
    //todo operator +, operator +=
    //todo operator -, operator -=
    //todo operator * (BASE) // умножение на базу
    //todo operator *
    //todo operator / (BASE) // деление на базу
    //todo operator /, operator %
    //todo 10-ый ввод и вывод
};


#endif //BIGINTEGER_BIGINTEGER_H
