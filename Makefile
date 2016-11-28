CXX=clang
CXXFLAGS=-Wall -g -std=c++14 -lstdc++

SRCS=citizen_test.cc monsterTest.cc smalltown_test.cc horror_example.cc

.PHONY=clean

all: $(SRCS:.cc=)

run_tests: citizen_test monsterTest smalltown_test
	./citizen_test
	./monsterTest
	./smalltown_test

citizen_test: citizen_test.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

monsterTest: monsterTest.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

smalltown_test: smalltown_test.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

citizen_test.o: citizen.h

monsterTest.o: monster.h citizen.h

smalltown_test.o: smalltown.h monster.h citizen.h

horror_example:
	$(CXX) $(CXXFLAGS) -o $@ horror_example.cc

clean:
	$(RM) *.o $(SRCS:.cc=)
