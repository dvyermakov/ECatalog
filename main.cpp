#include <iostream>
#include <string>

#include <stdlib.h>
#include <sstream>
#include <stdexcept>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "inc/dbg.h"


int main(int argc, char *argv[]){
  sql::Driver* driver = get_driver_instance();
  return 0;
}