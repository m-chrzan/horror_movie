CXX=clang
CXXFLAGS=-Wall -g -std=c++14 -lstdc++

.PHONY=clean

%.o: 
	$(CXX) $(CXXFLAGS) -c -o $@ $(@:.o=.cc)

clean:
	rm -rf *.o
