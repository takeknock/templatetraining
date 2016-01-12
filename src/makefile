#CC = g++
#OBJ = $(wildcard *.o) 
#LNK = -lcppunit
#OUTFILENAME = a.out
#
#all:main $(OUTFILENAME) 
#
#main: $(OBJ)
#	$(CC) -o $(OBJ) -lcppunit 
#
#$(OUTFILENAME): *.cpp
#	$(CC) -o $@ $^ -lcppunit
#
#
#clean:
#	-rm $(OBJ) $(OUTFILENAME)
CC = g++
impl = $(wildcard *.cpp)
LNK = -lcppunit
OUTFILENAME = a.out

$(OUTFILENAME): $(impl)
	$(CC) $^ $(LNK)	

clean:
	-rm $(OUTFILENAME)
