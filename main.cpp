#include <iostream>
#include "BigInteger.h"

int main() {
    BigInteger bi = BigInteger(BigInteger::Random, 1);
    std::cout<<bi<<std::endl;
    return 0;
}
