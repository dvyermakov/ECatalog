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

void DetailsModel::select(){
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
  ok = stmt->execute("SELECT detail.id AS detailId, detail.Component AS detailComponent, detail.Count AS detailCount, detail.Price AS detailPrice, detail.Place AS detailPlace, "
                        "component.Name AS componentName, component.Type AS componentType, component.Pack AS componentPack, "
                        "type.Name AS typeName, "
                        "place.Name AS placeName , "
                        "package.Name AS packageName "
                        "FROM detail "
                        "LEFT JOIN component ON (detail.Component = component.id) "
                        "LEFT JOIN type ON (component.Type = type.id) "
                        "LEFT JOIN place ON (detail.Place = place.id) "
                        "LEFT JOIN package ON (component.Pack = package.id) "
                        "WHERE (component.Name LIKE 'AT%');");
  cout << "#\t stmt->execute('SELECT id, Component, Count, Price, Place FROM detail ORDER BY id ASC') = ";
  cout << ok << endl;
  if (ok == true) {
    /* The first result is a result set */
    cout << "#\t\t Fetching results" << endl;
    /*
    NOTE: If stmt.getMoreResults() would be implemented already one
    would use a do { ... } while (stmt.getMoreResults()) loop
    */
    std::unique_ptr< sql::ResultSet > res(stmt->getResultSet());
    row = 0;    
    while (res->next()) {
      std::string tmpstr;
      int detailId = res->getInt("detailId");
      tmpstr = std::to_string(detailId); // !!! УБРАТЬ ЭТО ОТСЮДА !!!
      std::string typeName = res->getString("typeName");
      std::string componentName = res->getString("componentName");
      std::string packageName = res->getString("packageName");
      double detailPrice = res->getDouble("detailPrice");      
      tmpstr = std::to_string(detailPrice);
      double detailCount = res->getDouble("detailCount");
      tmpstr = std::to_string(detailCount);
      std::string placeName = res->getString("placeName");
      int detailPlace = res->getInt("detailPlace");      
      int componentType = res->getInt("componentType");      
      int componentPack = res->getInt("componentPack");      
      int detailComponent = res->getInt("detailComponent");      
      Place *place = new Place(detailPlace, placeName, 0);
      Type *type = new Type(componentType, typeName, 0);
      Package *pack = new Package(componentPack, packageName);
      Component *comp = new Component(detailComponent, componentName, *type, *pack);      
      Detail *det = new Detail(detailId, *comp, detailCount, detailPrice, *place);
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
  // for (int i = 0; i < Details.size(); ++i){
  for (auto detail : Details){
    std::vector<std::string> row;
    // row.push_back(std::to_string(Details[i]->getId())); // "Id"
    // row.push_back(Details[i]->getTypeName()); // "Тип"
    // row.push_back(Details[i]->getComponentName()); // "Название"
    // row.push_back(Details[i]->getPackageName()); // "Корпус"
    // row.push_back(std::to_string(Details[i]->getPrice())); // "Цена"
    // row.push_back(std::to_string(Details[i]->getCount())); // "Количество"
    // row.push_back(Details[i]->getPlaceName()); // "Место хранения"
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