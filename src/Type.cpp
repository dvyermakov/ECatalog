/**
  ******************************************************************************
  * @file    Type.cpp
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

#include "../inc/Type.h"
#include "../inc/dbg.h"

#include <string>

/**
  * @brief      Конструктор по умолчанию
  * @param      
  * @retval     none
  */
Type::Type(){
  
}

/**
  * @brief      Конструктор
  * @param      _Id
  * @param      _Name
  * @param      _ParentId
  * @retval     none
  */
Type::Type(uint _Id, std::string _Name, uint _ParentId){
  Id = _Id;
  Name = _Name;
  ParentId = _ParentId;
}

/**
  * @brief      Перегруженный оператор присваивания
  * @param      &rhs
  * @retval     Type&
  */
Type& Type::operator=(const Type &rhs){
  Id = rhs.Id;
  Name = rhs.Name;
  ParentId = rhs.ParentId;
  return *this;
}

/**
  * @brief      Деструктор
  * @param      
  * @retval     none
  */
Type::~Type(){
  
}

