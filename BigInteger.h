//
// Created by compucter on 10.03.2020.
//

#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H

typedef unsigned char BASE;
typedef unsigned long long BiggerThanBASE;
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

    int compare(const BigInteger&);
    int countEmptyPlaces() const;
    BigInteger addIndent(int indentSize);
    bool operator>(const BigInteger&);
    bool operator<(const BigInteger&);
    bool operator>=(const BigInteger&);
    bool operator<=(const BigInteger&);
    bool operator==(const BigInteger&);
    bool operator!=(const BigInteger&);

    BigInteger& operator=(const BigInteger& object);

    BigInteger operator+(const BigInteger& object);
    BigInteger operator+=(const BigInteger& object);

    BigInteger operator*(const BASE& secondFactor);
    BigInteger operator*(const BigInteger& object);
    //todo operator -, operator -=
    //todo operator *
    //todo operator / (BASE) // деление на базу
    //todo operator /, operator %
    //todo 10-ый ввод и вывод
    //todo добавить выведение нуля
};


#endif //BIGINTEGER_BIGINTEGER_H
