/**
  ******************************************************************************
  * @file    Model.cpp
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

#include "../inc/Model.h"
#include "../inc/dbg.h"

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
Model::Model(){
  
}

/**
  * @brief      Деструктор
  * @param      
  * @retval     none
  */
Model::~Model(){
  
}

/**
  * @brief      Получить все детали
  * @param      
  * @retval     none
  */
void Model::getAllDetails(){
  
}

/**
  * @brief      Вывести все детали на экран
  * @param      
  * @retval     none
  */
void Model::printDetails(){

}

void Model::select(){
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
  ok = stmt->execute("SELECT id, Component, Count, Price, Place FROM detail ORDER BY id ASC");
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
      cout << "#\t\t Row " << row << " - id = " << res->getInt("id");
      cout << ", Component = '" << res->getInt("Component") << "'";
      cout << ", Count = '" << res->getDouble("Count") << "'";
      cout << ", Price = '" << res->getDouble("Price") << "'";
      cout << ", Place = '" << res->getInt("Place") << "'" << endl;
      row++;
    }
  }
  return;
}