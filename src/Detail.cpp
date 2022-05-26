/**
  ******************************************************************************
  * @file    Detail.cpp
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

#include "../inc/Detail.h"
#include "../inc/dbg.h"

#include <string>

/**
  * @brief      Конструктор по умолчанию
  * @param      
  * @retval     none
  */
Detail::Detail(){
  
}

/**
  * @brief      Конструктор
  * @param      _Id
  * @param      _component
  * @param      _Count
  * @param      _Price
  * @param      _place
  * @retval     none
  */
Detail::Detail (uint _Id, Component _component, double _Count, double _Price, Place _place){
  Id = _Id;
  component = _component;
  Count = _Count;
  Price = _Price;
  place = _place;
}

/**
  * @brief      Деструктор
  * @param      
  * @retval     none
  */
Detail::~Detail(){
  
}

int Detail::getId(){
  return Id;
}

std::string Detail::getTypeName(){
  return component.getTypeName();
}

std::string Detail::getComponentName(){
  return component.getName();
}

std::string Detail::getPackageName(){
  return component.getPackageName();
}

double Detail::getCount(){
  return Count;
}

double Detail::getPrice(){
  return Price;
}

std::string Detail::getPlaceName(){
  return place.getName();
}