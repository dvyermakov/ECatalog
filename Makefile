APPNAME = ECatalog

SRCS += main.cpp
SRCS += src/dbg.cpp
SRCS += src/TblType.cpp
SRCS += src/Type.cpp
SRCS += src/Database.cpp

INC += -I/usr/include/cppconn

LIBS += -L/usr/lib -lmysqlcppconn

all:
	g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

debug:
	g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME) -DDEBUG