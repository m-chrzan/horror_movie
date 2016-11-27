#include <tuple>

#include "smalltown.h"
#include "testing.h"

void testConstructor() {
    beginTest();

    SmallTown<Vampire<int>, unsigned, 0, 4, Teenager<int>, Adult<int>,
              Sheriff<int>>
        town1(Vampire<int>(3, 4), Teenager<int>(13, 12), Adult<int>(41, 21),
              Sheriff<int>(12, 23, 3));

    SmallTown<Vampire<double>, unsigned char, 42, 255, Teenager<float>,
              Sheriff<unsigned>, Adult<long>>
        town2(Vampire<double>(3.14, 4.13), Teenager<float>(0.03, 12.32),
              Sheriff<unsigned>(12, 23, 3), Adult<long>(41, 21));

    finishTest();
}


int main() {
    testConstructor();
}
