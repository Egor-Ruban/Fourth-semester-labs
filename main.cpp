#include <iostream>
#include "BigInteger.h"

int main() {
    BigInteger bi = BigInteger(BigInteger::Random, 1);
    std::cin>>bi;
    std::cout<<bi<<std::endl;
    return 0;
}
