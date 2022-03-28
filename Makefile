APPNAME = ECatalog

SRCS += main.cpp
SRCS += src/dbg.cpp
SRCS += src/TblType.cpp

all:
	g++ -Wall $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

debug:
	g++ -Wall $(SRCS) -o $(APPNAME) -DDEBUG