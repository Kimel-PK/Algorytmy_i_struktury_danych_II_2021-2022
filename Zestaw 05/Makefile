CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: ZadanieB.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieB.x: ZadanieB.o
ZadanieB.o: ZadanieB.cpp ADTgraph.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump