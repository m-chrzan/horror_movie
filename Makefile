CXX=clang
CXXFLAGS=-Wall -g -std=c++14 -lstdc++

SRCS=citizen_test.cc monsterTest.cc

.PHONY=clean

all: citizen_test monsterTest smalltown_test

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

clean:
	rm -rf *.o $(SRCS:.cc=)
