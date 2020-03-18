#include <iostream>
#include "BigInteger.h"

int main() {
    int position = 1;
    while(true) { //для дебага
        BigInteger bi = BigInteger(BigInteger::Random, 5);
        BigInteger bi2;
        std::cin >> bi;
        //std::cout<<bi<<std::endl;
        std::cin >> bi2;
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
        //std::cout<<" / "<<(bi / 0xa)<<std::endl;
        //std::cout<<" % "<<(int)(bi % 0xf)<<std::endl;
        //bi-=bi2;
        //std::string str = ;
        std::cout << "dec Out " << bi.outputDecimal() << std::endl;
        //std::cout << "dec In " << BigInteger::inputDecimal("383") << std::endl;
        //BigInteger bi3 = BigInteger(BigInteger::Empty);
        //std::cout<<bi3<<std::endl;
        //bi3.coefficients[0] = '4' - '0';
        //std::cout<<bi3<<std::endl;
        //BigInteger bi4 = bi3 * position;
        //std::cout<<bi4<<std::endl;
        //position *= 0xa;
    }
    return 0;
}
