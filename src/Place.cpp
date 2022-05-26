/**
  ******************************************************************************
  * @file    Place.cpp
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

#include "../inc/Place.h"
#include "../inc/dbg.h"

#include <string>

/**
  * @brief      Конструктор по умолчанию
  * @param      
  * @retval     none
  */
Place::Place(){
  
}

/**
  * @brief      Конструктор
  * @param      _Id
  * @param      _Name
  * @param      _ParentId
  * @retval     none
  */
Place::Place(uint _Id, std::string _Name, uint _ParentId){
  Id = _Id;
  Name = _Name;
  ParentId = _ParentId;
}

/**
  * @brief      Перегруженный оператор присваивания
  * @param      &rhs
  * @retval     Place&
  */
Place& Place::operator=(const Place &rhs){
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
Place::~Place(){
  
}

void Place::PrintPlace(){
  std::cout << Name << "\t";
}

/**
  * @brief      Возрат значения
  * @param      none
  * @retval     std::string
  */
std::string Place::getName(){
  return Name;
}
