#include <iostream>
#include "../include/dbg.h"

void dbgMessage(std::string _message){
    std::cout << _message << std::endl;
}

void dbgValue(std::string _name, int _value){
    std::cout << "Int " << _name << " = " << _value << std::endl;
}

void dbgValue(std::string _name, std::string _value){
    std::cout << "String " << _name << " = " << _value << std::endl;
}

void dbgValue(std::string _name, double _value){
    std::cout << "Double " << _name << " = " << _value << std::endl;
}

void dbgValue(std::string _name, bool _value){
    std::string str;
    _value ? str = "true" : str = "false";
    std::cout << "Bool " << _name << " = " << str << std::endl;
}