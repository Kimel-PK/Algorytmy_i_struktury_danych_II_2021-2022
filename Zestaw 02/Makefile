CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: ZadanieA.x ZadanieB.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieA.x: ZadanieA.o
ZadanieA.o: ZadanieA.cpp SetSimpleInt.hpp SetSimpleIntEven.hpp SetSimpleChar.hpp SetSimpleCharTuple.hpp

ZadanieB.x: ZadanieB.o
ZadanieB.o: ZadanieB.cpp SetHashed.hpp LinkedList.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump