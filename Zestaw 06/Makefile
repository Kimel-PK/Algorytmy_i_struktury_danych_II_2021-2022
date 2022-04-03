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

ZadanieC_bruteforce.x: ZadanieC_bruteforce.o
ZadanieC_bruteforce.o: ZadanieC_bruteforce.cpp

ZadanieC_Warnsdorff.x: ZadanieC_Warnsdorff.o
ZadanieC_Warnsdorff.o: ZadanieC_Warnsdorff.cpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump