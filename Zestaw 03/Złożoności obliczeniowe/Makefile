CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: ZadanieA_zlozonosc.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieA_zlozonosc.x: ZadanieA_zlozonosc.o
ZadanieA_zlozonosc.o: ZadanieA_zlozonosc.cpp ../PriorityQueue.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump