/**
  ******************************************************************************
  * @file    Component.cpp
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

#include "../inc/Component.h"
#include "../inc/dbg.h"

#include <string>

/**
  * @brief      Конструктор по умолчанию
  * @param      
  * @retval     none
  */
Component::Component(){
  
}

/**
  * @brief      Конструктор
  * @param      _Id
  * @param      _Name
  * @param      _type
  * @param      _package
  * @retval     none
  */
Component::Component(uint _Id, std::string _Name, Type _type, Package _package){
  Id = _Id;
  Name = _Name;
  type = _type;
  package = _package;
}

/**
  * @brief      Перегруженный оператор присваивания
  * @param      &rhs
  * @retval     Component&
  */
Component& Component::operator=(const Component &rhs){
  Id = rhs.Id;
  Name = rhs.Name;
  type = rhs.type;
  package = rhs.package;
  return *this;
}

/**
  * @brief      Деструктор
  * @param      
  * @retval     none
  */
Component::~Component(){
  
}

std::string Component::getName(){
  return Name;
}

std::string Component::getTypeName(){
  return type.getName();
}

std::string Component::getPackageName(){
  return package.getName();
}
