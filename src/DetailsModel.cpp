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
      int tmpint;
      int detailId = res->getInt("detailId");
      tmpstr = std::to_string(detailId); // !!! УБРАТЬ ЭТО ОТСЮДА !!!
      tmpint = tmpstr.length();
      // if (MaximumLengths[0] < tmpint){
      //   MaximumLengths[0] = tmpint;
      // }
      std::string typeName = res->getString("typeName");
      tmpint = typeName.length();
      // std::cout << "typeName " << typeName << " typeName.length() " << typeName.length() << std::endl;
      // if (MaximumLengths[1] < tmpint){
      //   MaximumLengths[1] = tmpint;
      // }
      std::string componentName = res->getString("componentName");
      tmpint = componentName.length();
      // if (MaximumLengths[2] < tmpint){
      //   MaximumLengths[2] = tmpint;
      // }
      std::string packageName = res->getString("packageName");
      tmpint = packageName.length();
      // if (MaximumLengths[3] < tmpint){
      //   MaximumLengths[3] = tmpint;
      // }
      double detailPrice = res->getDouble("detailPrice");      
      tmpstr = std::to_string(detailPrice);
      tmpint = tmpstr.length();
      // if (MaximumLengths[4] < tmpint){
      //   MaximumLengths[4] = tmpint;
      // }
      double detailCount = res->getDouble("detailCount");
      tmpstr = std::to_string(detailCount);
      tmpint = tmpstr.length();
      // if (MaximumLengths[5] < tmpint){
      //   MaximumLengths[5] = tmpint;
      // }
      std::string placeName = res->getString("placeName");
      tmpint = placeName.length();
      // if (MaximumLengths[6] < tmpint){
      //   MaximumLengths[6] = tmpint;
      // }
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
      // cout << "#\t\t Row " << row << " - id = " << res->getInt("id");
      // cout << ", Component = '" << res->getInt("Component") << "'";
      // cout << ", Count = '" << res->getDouble("Count") << "'";
      // cout << ", Price = '" << res->getDouble("Price") << "'";
      // cout << ", Place = '" << res->getInt("Place") << "'" << endl;
      row++;
      delete place;
      delete type;
      delete pack;
      delete comp;
      
      // delete det;
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
  for (int i = 0; i < Details.size(); ++i){
    std::vector<std::string> row;
    row.push_back(std::to_string(Details[i]->getId())); // "Id"
    row.push_back(Details[i]->getTypeName()); // "Тип"
    row.push_back(Details[i]->getComponentName()); // "Название"
    row.push_back(Details[i]->getPackageName()); // "Корпус"
    row.push_back(std::to_string(Details[i]->getPrice())); // "Цена"
    row.push_back(std::to_string(Details[i]->getCount())); // "Количество"
    row.push_back(Details[i]->getPlaceName()); // "Место хранения"
    table.push_back(row);
  }
  return table;

}