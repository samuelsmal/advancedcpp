# Needs GNU Make
CPP=g++
RM=rm -f
CPPFLAGS=-g -std=c++11 -Wall -Weffc++ -pedantic -o
LDFLAGS=-g
LDLIBS=

SRCS=main.cpp pvector.h RPN.cpp

all : rpn-pvector

rpn-pvector : main.o pvector.o rpn.o
	$(CPP) $(LDFLAGS) -o rpn-pvector main.o pvector.o rpn.o

main.o : main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp
	
pvector.o : pvector.h
	$(CPP) $(CPPFLAGS) -c pvector.o
	
rpn.o : RPN.cpp RPN.h pvector.h
	$(CPP) $(CPPFLAGS) -c RPN.cpp

clean:
	$(RM) $(OBJS)
