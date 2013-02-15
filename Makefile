EXE=bfgcv

all: $(EXE)

$(EXE): src/bfgcv
	make -C src/bfgcv
	cp src/bfgcv/bfgcv $(EXE)

clean: 
	make -C src/bfgcv clean
	rm -f $(EXE)

.PHONY: all, clean
