CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: ZadanieA.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieA.x: ZadanieA.o
ZadanieA.o: ZadanieA.cpp ADTgraph.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump