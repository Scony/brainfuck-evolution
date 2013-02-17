LIBS=
CC=g++

SOURCES=main.cpp Evolution.cpp Interpreter.cpp Memory.cpp IndividualFactory.cpp KindFactory.cpp Rsx.cpp Sx.cpp Pmx.cpp Individual.cpp Utils.cpp Exception.cpp
HEADERS=
OBJECTS=$(SOURCES:.cpp=.o)

all: bfevo.out

bfevo.out: $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@
	
clean:
	-rm -rf bfevo.out *.o *~
