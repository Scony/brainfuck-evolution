EXE=bfevo.out

all: $(EXE)

$(EXE): src/bfevo.out
	make -C src/
	cp src/bfevo.out $(EXE)

clean: 
	make -C src/ clean
	rm -f $(EXE)

.PHONY: all, clean
