LIBS=
CC=g++

SOURCES=main.cpp Memory.cpp IndividualFactory.cpp KindFactory.cpp Individual.cpp Utils.cpp Exception.cpp
HEADERS=
OBJECTS=$(SOURCES:.cpp=.o)

all: bfevo.out

bfevo.out: $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@
	
clean:
	-rm -rf bfevo.out *.o *~
