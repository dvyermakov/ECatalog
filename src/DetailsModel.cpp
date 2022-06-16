/**
  ******************************************************************************
  * @file    DetailsModel.cpp
  * @author  Dmitriy Ermakov
  * @brief   Модель базы данных
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

#include "../inc/DetailsModel.h"
#include "../inc/dbg.h"
#include "../inc/Place.h"
#include "../inc/Type.h"
#include "../inc/Package.h"
#include "../inc/Component.h"


#include <string>

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#define EXAMPLE_HOST "localhost"
#define EXAMPLE_USER "dmitriy"
#define EXAMPLE_PASS "R3h7sow1."
#define EXAMPLE_DB "ECatalog"
using namespace std;

/**
  * @brief      Конструктор
  * @param      
  * @retval     none
  */
DetailsModel::DetailsModel(){
  
}

/**
  * @brief      Деструктор
  * @param      
  * @retval     none
  */
DetailsModel::~DetailsModel(){
  
}

void DetailsModel::clearModel(){
  if (Details.size() > 0){
    Details.clear();
  }
}

void DetailsModel::clearStatement(){
  if (Statement.size() > 0){
    Statement.clear();
  }
}

void DetailsModel::prepareStatement(const std::string &nameLike){
  this->clearStatement();
  Statement = "SELECT detail.id AS detailId, detail.Component AS detailComponent, detail.Count AS detailCount, detail.Price AS detailPrice, detail.Place AS detailPlace, "
                        "component.Name AS componentName, component.Type AS componentType, component.Pack AS componentPack, "
                        "type.Name AS typeName, "
                        "place.Name AS placeName , "
                        "package.Name AS packageName "
                        "FROM detail "
                        "LEFT JOIN component ON (detail.Component = component.id) "
                        "LEFT JOIN type ON (component.Type = type.id) "
                        "LEFT JOIN place ON (detail.Place = place.id) "
                        "LEFT JOIN package ON (component.Pack = package.id)";
  if (nameLike.length() > 0){
    Statement += " WHERE (component.Name LIKE '";
    Statement += nameLike;
    Statement += "%')";
  }
  Statement += ";";
  
                        
}

void DetailsModel::select(const std::string &nameLike){
  const string url=EXAMPLE_HOST;
  const string user=EXAMPLE_USER;
  const string pass=EXAMPLE_PASS;
  const string database=EXAMPLE_DB;
  size_t row;
  bool ok;
  /* Using the Driver to create a connection */
  sql::Driver* driver = get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  /* Creating a "simple" statement - "simple" = not a prepared statement */
  std::unique_ptr< sql::Statement > stmt(con->createStatement());
  this->prepareStatement(nameLike);

  ok = stmt->execute(Statement);
  if (ok == true) {
    this->clearModel();
    std::unique_ptr< sql::ResultSet > res(stmt->getResultSet());
    row = 0;    
    while (res->next()) {
      Place *place = new Place(res->getInt("detailPlace"), 
                              res->getString("placeName"), 0);
      Type *type = new Type(res->getInt("componentType"), 
                            res->getString("typeName"), 0);
      Package *pack = new Package(res->getInt("componentPack"), 
                                  res->getString("packageName"));
      Component *comp = new Component(res->getInt("detailComponent"), 
                                      res->getString("componentName"), *type, *pack);      
      Detail *det = new Detail(res->getInt("detailId"), 
                              *comp, 
                              res->getDouble("detailCount"), 
                              res->getDouble("detailPrice"), *place);
      Details.push_back(det);
      row++;
      delete place;
      delete type;
      delete pack;
      delete comp;
    }
  }
  notifyUpdate(); 
  return;
}

std::vector<std::string> DetailsModel::getCaptions(){
  return Captions;
}

std::vector<std::vector<std::string>> DetailsModel::getTable(){
  std::vector<std::vector<std::string>> table;  
  for (auto detail : Details){
    std::vector<std::string> row;
    row.push_back(std::to_string(detail->getId())); // "Id"
    row.push_back(detail->getTypeName()); // "Тип"
    row.push_back(detail->getComponentName()); // "Название"
    row.push_back(detail->getPackageName()); // "Корпус"
    row.push_back(std::to_string(detail->getPrice())); // "Цена"
    row.push_back(std::to_string(detail->getCount())); // "Количество"
    row.push_back(detail->getPlaceName()); // "Место хранения"
    table.push_back(row);
  }
  return table;
}