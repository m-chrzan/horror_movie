CXX=clang
CXXFLAGS=-Wall -g -std=c++14 -lstdc++

SRCS=citizen_test.cc monsterTest.cc

.PHONY=clean

citizen_test: citizen_test.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

monsterTest: monsterTest.o testing.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.o $(SRCS:.cc=)
