CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: Dict.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieA.x: ZadanieA.o
ZadanieA.o: ZadanieA.cpp

ZadanieB.x: ZadanieB.o
ZadanieB.o: ZadanieB.cpp

ZadanieD.x: ZadanieD.o
ZadanieD.o: ZadanieD.cpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump