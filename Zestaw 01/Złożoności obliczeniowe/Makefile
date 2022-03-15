CFLAGS = -Wall -std=c++17 -pedantic
LDFLAGS = 
LDLIBS = 

.PHONY: all clean
all: ZadanieA_zlozonosc.x ZadanieB_zlozonosc.x ZadanieD_zlozonosc.x

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.cpp %.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

ZadanieA_zlozonosc.x: ZadanieA_zlozonosc.o
ZadanieA_zlozonosc.o: ZadanieA_zlozonosc.cpp ../SetSimple.hpp

ZadanieB_zlozonosc.x: ZadanieB_zlozonosc.o
ZadanieB_zlozonosc.o: ZadanieB_zlozonosc.cpp ../SetLinked.hpp ../LinkedSortedList.hpp

ZadanieD_zlozonosc.x: ZadanieD_zlozonosc.o
ZadanieD_zlozonosc.o: ZadanieD_zlozonosc.cpp ../DictionarySimple.hpp

clean:
	$(RM) *.[ox] *.exe *.exe.stackdump