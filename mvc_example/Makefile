APPNAME = MVCExample

SRCS += main.cpp
SRCS += TemperatureModel.cpp
SRCS += Observable.cpp
SRCS += ConsoleView.cpp
SRCS += Controller.cpp


all:
	g++ -Wall $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

debug:
	g++ -Wall $(SRCS) -o $(APPNAME) -DDEBUG