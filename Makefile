APPNAME = ECatalog

SRCS += main.cpp
SRCS += src/dbg.cpp
SRCS += src/Model.cpp
SRCS += src/Type.cpp
SRCS += src/Place.cpp
SRCS += src/Package.cpp
SRCS += src/Component.cpp
SRCS += src/Detail.cpp


INC += -I/usr/include/cppconn

LIBS += -L/usr/lib -lmysqlcppconn

all:
	g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

debug:
	g++ -Wall $(SRCS) $(INC) $(LIBS) -o $(APPNAME) -DDEBUG