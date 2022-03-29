APPNAME = ECatalog

SRCS += main.cpp
SRCS += src/dbg.cpp
SRCS += src/TypeModel.cpp
SRCS += src/TypeController.cpp
SRCS += src/Type.cpp

INC += -I/usr/include/cppconn

LIBS += -L/usr/lib -lmysqlcppconn

all:
	g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

debug:
	g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME) -DDEBUG