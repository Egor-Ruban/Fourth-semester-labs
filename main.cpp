#include <iostream>
#include "BigInteger.h"

int main() {
    BigInteger bi = BigInteger(BigInteger::Random, 3);
    std::cout<<bi<<std::endl;
    return 0;
}
