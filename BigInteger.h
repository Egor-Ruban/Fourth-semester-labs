//
// Created by Egor-Ruban on 10.03.2020.
//

#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H

typedef unsigned char BASE; //только char или short
typedef long long BiggerThanBASE;
#define BASE_SIZE 8 * sizeof(BASE)

class BigInteger {
public:
    BASE* coefficients; //массив коэффициентов
    int availableCoefficients; //сколько памяти выделено под них
    //размера значащих коэффициентов нет, так как все незначащие - нули, не влияют на результат операций

    int countEmptyPlaces() const; //считает нули в начале
    BigInteger addIndent(int indentSize); //добавляет нули в конец числа (для умножения)

public:
    enum ConstructorTypes{
        Default,
        Empty,
        Random,
        Digit
    };

    BigInteger(ConstructorTypes = Default, int = 1);
    BigInteger(const BigInteger&);
    ~BigInteger();

    friend std::ostream& operator<<(std::ostream&, const BigInteger&);
    friend std::istream& operator>>(std::istream&, BigInteger&);

    int compare(const BigInteger&)const ;
    bool operator>(const BigInteger&)const ;
    bool operator<(const BigInteger&)const ;
    bool operator>=(const BigInteger&)const ;
    bool operator<=(const BigInteger&)const ;
    bool operator==(const BigInteger&)const ;
    bool operator!=(const BigInteger&)const ;

    BigInteger& operator=(const BigInteger& object);

    BigInteger operator+(const BigInteger& object);
    BigInteger& operator+=(const BigInteger& object);

    BigInteger operator*(const BASE& secondFactor) const;
    BigInteger& operator*=(const BASE& secondFactor);
    BigInteger operator*(const BigInteger& object) const;
    BigInteger& operator*=(const BigInteger& object);

    BigInteger operator-(const BigInteger& object) const;
    BigInteger& operator-=(const BigInteger& object);

    BigInteger operator/(const BASE& divider) const;
    BigInteger& operator/=(const BASE& divider);
    BigInteger operator/(const BigInteger& divider) const;
    BigInteger& operator/=(const BigInteger& divider);

    BASE operator%(const BASE& divider) const;
    BigInteger operator%(const BigInteger& divider) const;

    std::string outputDecimal();
    static BigInteger inputDecimal(std::string decimalInput);
};


#endif //BIGINTEGER_BIGINTEGER_H
