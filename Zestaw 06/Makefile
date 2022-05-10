CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: ZadanieA.x ZadanieB.x ZadanieC.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieA.x: ZadanieA.o
ZadanieA.o: ZadanieA.cpp ADTgraph.hpp

ZadanieB.x: ZadanieB.o
ZadanieB.o: ZadanieB.cpp

ZadanieC.x: ZadanieC.o
ZadanieC.o: ZadanieC.cpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump