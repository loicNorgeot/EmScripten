#include "myLib.h"

myClass::myClass(std::string m){
    message = m;
}

void myClass::speak(){
    std::cout << "message" << std::endl;
}
