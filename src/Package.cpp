/**
  ******************************************************************************
  * @file    Package.cpp
  * @author  Dmitriy Ermakov
  * @brief   
  *          
  *
  @verbatim
  ==============================================================================
                    ##### Описание #####
  ==============================================================================
  [..] 
  () 

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

#include "../inc/Package.h"
#include "../inc/dbg.h"

#include <string>

/**
  * @brief      Конструктор по умолчанию
  * @param      
  * @retval     none
  */
Package::Package(){
  
}

/**
  * @brief      Конструктор
  * @param      _Id
  * @param      _Name
  * @retval     none
  */
Package::Package(uint _Id, std::string _Name){
  Id = _Id;
  Name = _Name;
}

/**
  * @brief      Перегруженный оператор присваивания
  * @param      &rhs
  * @retval     Package&
  */
Package& Package::operator=(const Package &rhs){
  Id = rhs.Id;
  Name = rhs.Name;
  return *this;
}

/**
  * @brief      Деструктор
  * @param      
  * @retval     none
  */
Package::~Package(){
  
}

void Package::PrintPackage(){
  std::cout << Name << "\t";
}

std::string Package::getName(){
  return Name;
}