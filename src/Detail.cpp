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
  * @brief      Конструктор
  * @param      id
  * @param      componentId
  * @param      count
  * @param      price
  * @param      placeId
  * @retval     none
  */
Detail::Detail(int id, int componentId, float count, float price, int placeId){
  Id = id;
  ComponentId = componentId;
  Count = count;
  Price = price;
  PlaceId = placeId;
}

