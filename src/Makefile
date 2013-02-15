LIBS=
CC=g++

SOURCES=main.cpp File.cpp Memory.cpp Parser.cpp Exception.cpp Interpreter.cpp
HEADERS=
OBJECTS=$(SOURCES:.cpp=.o)

all: bfgcv

bfgcv: $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@
	
clean:
	-rm -rf bfgcv *.o *~
