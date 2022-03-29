/**
  ******************************************************************************
  * @file    TypeModel.cpp
  * @author  Dmitriy Ermakov
  * @brief   Класс работы с таблицей type базы данных
  *          Этот класс организует общение слоя бизнес-логики с базой данных
  *
  @verbatim
  ==============================================================================
                    ##### Описание #####
  ==============================================================================
  [..] 
  () Чтение записей базы данных
  () Вставка записей в базу данных
  () Изменение записей в базе данных
  () Удаление записей из базы данных

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

#include "../inc/TypeModel.h"
#include "../inc/dbg.h"

#include <string>

/**
  * @brief      Конструктор
  * @param      none
  * @retval     none
  */
TypeModel::TypeModel(){

}

void TypeModel::select(){
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
  ok = stmt->execute("SELECT id, Name, ParentId FROM type ORDER BY id ASC");
  cout << "#\t stmt->execute('SELECT id, Name, ParentId FROM type ORDER BY id ASC') = ";
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
      cout << ", Name = '" << res->getString("Name") << "'" << endl;
      row++;
    }
  }
  return;
}