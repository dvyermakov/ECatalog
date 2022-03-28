#ifndef DBG_H
#define DBG_H

#include <iostream>
#include <string>

// Вывод отладочных сообщений

#ifdef DEBUG
    // Вывод места вызова и строки
    #define DBG(_message)               std::cout << "File: " << __FILE__ << " line: " << __LINE__ << " function: " << __func__ << " - " << _message << std::endl

    // Вывод сообщения
    #define DBGMESSAGE(_message)        dbgMessage(_message)

    // Вывод значения переменной типа int ("Int $name = $value")
    #define DBGVALUE(_name, _value)     dbgValue(_name, _value)    
    
#else
    #define DBG(s)
    #define DBGVALUE(_name, _value)
    #define DBGMESSAGE(_message)
#endif

// Вывод строки
void dbgMessage(std::string _message);

// Вывод значения переменной
void dbgValue(std::string _name, int _value); // для int
void dbgValue(std::string _name, std::string _value); // для string
void dbgValue(std::string _name, double _value); // для double
void dbgValue(std::string _name, bool _value); // для bool

#endif