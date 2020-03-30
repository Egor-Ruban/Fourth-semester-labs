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
        //std::cout <<"compare "<< bi.compare(bi2) << std::endl;
        //std::cout<<">"<<(bi > bi2)<<std::endl;
        //std::cout<<"<"<<(bi < bi2)<<std::endl;
        //std::cout<<">="<<(bi >= bi2)<<std::endl;
        //std::cout<<"<="<<(bi <= bi2)<<std::endl;
        //std::cout<<"=="<<(bi == bi2)<<std::endl;
        //std::cout<<"!="<<(bi != bi2)<<std::endl;
        //std::cout<<" + "<< bi + bi2<<std::endl;
        //bi+=bi2;
        //std::cout<<" += "<<bi<<std::endl;
        //std::cout<<" * "<<(bi * bi2)<<std::endl;
        //bi*=bi2;
        //std::cout<<" *= "<<(bi)<<std::endl;
        std::cout<<" - "<< (bi - bi2)<<std::endl;
        std::cout<<" / "<<(bi / 0xf)<<std::endl;
        std::cout<<" % "<<(int)(bi % 0xf)<<std::endl;
        //bi-=bi2;
        //std::string str = bi.outputDecimal();
        //std::cout << "dec Out " << str << std::endl;
        //std::cout << "dec In " << BigInteger::inputDecimal(str) << std::endl;
        //std::cout<<" / "<<(bi / bi2)<<std::endl;
        //std::cout<<" % "<<(bi % bi2)<<std::endl;
        bi/=bi2;
        std::cout<<" /= "<<(bi)<<std::endl;
    }
    return 0;
}
