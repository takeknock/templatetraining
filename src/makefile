CC = g++
OBJ = DualTest.o main.o
LNK = -lcppunit
OUTFILENAME = a.out

all:main $(OUTFILENAME) 

main: $(OBJ)
	$(CC) -o $(OBJ) -lcppunit 

$(OUTFILENAME): *.cpp
	$(CC) -o $@ $^ -lcppunit


clean:
	-rm $(OBJ) $(OUTFILENAME)
