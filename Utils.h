//
// Created by egor-Ruban on 10.03.2020.
//

#include <iostream>

char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

unsigned int hexToInteger(char digit){
    int newPart;
    if(digit>= '0' && digit <= '9'){
        newPart = digit - '0';
    } else if(digit >= 'a' && digit <= 'f'){
        newPart = digit - 'a' + 10;
    } else if(digit >= 'A' && digit <= 'F'){
        newPart = digit - 'A' + 10;
    } else {
        newPart = 0;
        std::cout<<"wrong digit: "<<(int) digit<<std::endl;
    }
    return newPart;
}