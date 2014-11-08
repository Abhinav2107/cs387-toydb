#PUBLICDIR= /usr0/cs564/public/project
SRC= buf.c hash.c pf.c raid.c
OBJ= buf.o hash.o pf.o raid.o
HDR = pftypes.h pf.h raid.h

pflayer.o: $(OBJ)
	ld -r -o pflayer.o $(OBJ)

tests: testhash testpf

testpf: testpf.o pflayer.o
	cc -o testpf testpf.o pflayer.o

testhash: testhash.o pflayer.o
	cc -o testhash testhash.o pflayer.o

$(OBJ): $(HDR)

testhash.o: $(HDR)

testpf.o: $(HDR)

lint: 
	lint $(SRC)

install: pflayer.o 

.PHONY: tests, lint, install
