/**
  ******************************************************************************
  * @file    dbg.cpp
  * @author  Dmitriy Ermakov
  * @brief   Функции для организации вывода отладочных сообщений
  @verbatim
  ==============================================================================
                    ##### Описание #####
  ==============================================================================
  [..] 
  

  ==============================================================================
                     ##### Как использовать #####
  ==============================================================================  
  [..]
  
  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) .
  * All rights reserved.</center></h2>
  *
  *
  ******************************************************************************
  */ 

#include <iostream>
#include "../inc/dbg.h"

/**
  * @brief      Функция для вывода отладочного сообщения
  * @param      _message сообщение, которое будет выведено
  * @retval     none
  */
void dbgMessage(std::string _message){
  std::cout << _message << std::endl;
}

/**
  * @brief      Функция для отладочного вывода значения переменной типа int
  * @param      _name название переменной
  * @param      _value значение переменной
  * @retval     none
  */
void dbgValue(std::string _name, int _value){
  std::cout << "Int " << _name << " = " << _value << std::endl;
}

/**
  * @brief      Функция для отладочного вывода значения строки
  * @param      _name название переменной
  * @param      _value значение переменной
  * @retval     none
  */
void dbgValue(std::string _name, std::string _value){
  std::cout << "String " << _name << " = " << _value << std::endl;
}

/**
  * @brief      Функция для отладочного вывода значения переменной типа double
  * @param      _name название переменной
  * @param      _value значение переменной
  * @retval     none
  */
void dbgValue(std::string _name, double _value){
  std::cout << "Double " << _name << " = " << _value << std::endl;
}

/**
  * @brief      Функция для отладочного вывода значения переменной типа bool
  * @param      _name название переменной
  * @param      _value значение переменной
  * @retval     none
  */
void dbgValue(std::string _name, bool _value){
  std::string str;
  _value ? str = "true" : str = "false";
  std::cout << "Bool " << _name << " = " << str << std::endl;
}