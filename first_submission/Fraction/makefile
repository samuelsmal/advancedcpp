# Needs GNU Make
CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11 -Wall
LDFLAGS=-g
LDLIBS=

#SRCS=main.cpp fraction.cpp test.cpp

SRCS=main.cpp fraction.cpp util.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all : fraction

fraction : $(OBJS)
	$(CXX) $(CPPFLAGS) -o fraction $(OBJS) $(LDLIBS)
	./fraction

depend : .depend

.depend : $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) ~ .dependfraction

include .depend