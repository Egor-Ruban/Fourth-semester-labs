#include <iostream>
#include "BigInteger.h"

int main() {
    BigInteger bi = BigInteger(BigInteger::Random, 1);
    BigInteger bi2;
    while(true) {
        std::cin >> bi;
        std::cout<<bi<<std::endl;
        std::cin >> bi2;
        std::cout<<bi2<<std::endl;
        std::cout << bi.compare(bi2) << std::endl;
        std::cout<<">"<<(bi > bi2)<<std::endl;
        std::cout<<"<"<<(bi < bi2)<<std::endl;
        std::cout<<">="<<(bi >= bi2)<<std::endl;
        std::cout<<"<="<<(bi <= bi2)<<std::endl;
        std::cout<<"=="<<(bi == bi2)<<std::endl;
        std::cout<<"!="<<(bi != bi2)<<std::endl;
        std::cout<<" + "<< (bi + bi2)<<std::endl;

    }
    return 0;
}
