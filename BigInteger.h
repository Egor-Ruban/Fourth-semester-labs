//
// Created by compucter on 10.03.2020.
//

#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H

typedef int BASE;
#define BASE_SIZE 8 * sizeof(BASE)

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

    BigInteger(ConstructorTypes = Default, int = 1);
    BigInteger(const BigInteger&);
    ~BigInteger();

    friend std::ostream& operator<<(std::ostream&, const BigInteger&);
    friend std::istream& operator>>(std::istream&, BigInteger&);
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
