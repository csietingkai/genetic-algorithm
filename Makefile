CPP=g++
CPPFLAGS=-g -pthread -std=c++11
LDFLAGS=-g

EXENAME=ga.exe
OBJS=main.o ga.o

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(CPP) $(LDFLAGS) -o $(EXENAME) $(OBJS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

ga.o: ga.cpp ga.h
	$(CPP) $(CPPFLAGS) -c ga.cpp

clean:
	rm -rf $(OBJS) $(EXENAME)

