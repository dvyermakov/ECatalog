APPNAME = ECatalog

SRCS += main.cpp
SRCS += src/dbg.cpp
SRCS += src/Observable.cpp
SRCS += src/DetailsModel.cpp
SRCS += src/DetailsConsoleView.cpp
SRCS += src/DetailsController.cpp
SRCS += src/Type.cpp
SRCS += src/Place.cpp
SRCS += src/Package.cpp
SRCS += src/Component.cpp
SRCS += src/Detail.cpp
SRCS += src/functions.cpp


INC += -I/usr/include/mysql-cppconn-8/jdbc

LIBS += -L/usr/lib -lmysqlcppconn

all:
	clear ; g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME)

clean:
	clear ; rm -f $(APPNAME)

debug:
	clear ; g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME) -DDEBUG