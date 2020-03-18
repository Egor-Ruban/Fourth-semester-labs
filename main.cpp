#include <iostream>
#include "BigInteger.h"

int main() {
    while(true) { //для дебага
        BigInteger bi = BigInteger(BigInteger::Random, 5);
        BigInteger bi2;
        std::cin >> bi;
        std::cout<<bi<<std::endl;
        //std::cin >> bi2;
        //std::cout<<bi2<<std::endl;
        //std::cout << bi.compare(bi2) << std::endl;
        //std::cout<<">"<<(bi > bi2)<<std::endl;
        //std::cout<<"<"<<(bi < bi2)<<std::endl;
        //std::cout<<">="<<(bi >= bi2)<<std::endl;
        //std::cout<<"<="<<(bi <= bi2)<<std::endl;
        //std::cout<<"=="<<(bi == bi2)<<std::endl;
        //std::cout<<"!="<<(bi != bi2)<<std::endl;
        //std::cout<<" + "<< (bi + bi2)<<std::endl;
        //bi+=bi2;
        //std::cout<<" += "<<bi<<std::endl;
        //std::cout<<" * "<<(bi * bi2)<<std::endl;
        //bi*=bi2;
        //std::cout<<" *= "<<(bi)<<std::endl;
        //std::cout<<" - "<< (bi - bi2)<<std::endl;
        std::cout<<" / "<<(bi / 2)<<std::endl;
    }
    return 0;
}
