#CC = g++
OBJ = $(wildcard *.o) 
TESTOBJ = $(wildcard $(SRC)/*.o) 

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
testimpl = $(wildcard TemplateTrainingTest/*.cpp)
LNK = -lcppunit
OUTFILENAME = a.out

$(OUTFILENAME): $(impl) $(testimpl)
	$(CC) $^ $(LNK)	

clean:
	-rm $(OUTFILENAME)

test:
	./a.out

subsystem:
	$(MAKE) -C TemplateTrainingTest
