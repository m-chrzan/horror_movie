#include <iostream>
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

void testGetStatus() {
    beginTest();

    SmallTown<Vampire<int>, unsigned, 0, 4, Teenager<int>, Adult<int>,
              Sheriff<int>>
        town1(Vampire<int>(3, 4), Teenager<int>(13, 12), Adult<int>(41, 21),
              Sheriff<int>(12, 23, 3));

    SmallTown<Zombie<double>, unsigned char, 42, 255, Teenager<float>,
              Sheriff<unsigned>, Adult<long>>
        town2(Zombie<double>(3.14, 4.13), Teenager<float>(0.03, 12.32),
              Sheriff<unsigned>(12, 23, 3), Adult<long>(41, 21));

    checkEqual(town1.getStatus(), std::make_tuple<std::string, int, size_t>("Vampire", 3, 3),
            "Initial town1 status correct.");

    checkEqual(town2.getStatus(), std::make_tuple<std::string, double, size_t>("Zombie", 3.14, 3),
            "Initial town2 status correct.");

    finishTest();
}

void testTick() {
    beginTest();

    SmallTown<Vampire<int>, unsigned, 0, 4, Teenager<int>, Adult<int>,
    Sheriff<int>>
    town1(Vampire<int>(3, 4), Teenager<int>(13, 12), Adult<int>(41, 21),
          Sheriff<int>(12, 23, 3));

    checkEqual(town1.getStatus(), std::make_tuple<std::string, int, size_t>("Vampire", 3, 3),
               "Initial town1 status correct.");

    town1.tick(1);

    checkEqual(town1.getStatus(), std::make_tuple<std::string, int, size_t>("Vampire", 3, 3),
               "town1 after tick(1) status correct.");

    town1.tick(1);

    checkEqual(town1.getStatus(), std::make_tuple<std::string, int, size_t>("Vampire", 0, 3),
               "town1 after tick(1) status correct.");

    std::cout << "Citizens should win:\n";
    town1.tick(1);

//     SmallTown<Zombie<double>, unsigned char, 42, 255, Teenager<float>,
//     Sheriff<unsigned>, Adult<long>>
//     town2(Zombie<double>(3.14, 4.13), Teenager<float>(0.03, 12.32),
//           Sheriff<unsigned>(12, 23, 3), Adult<long>(41, 21));
//
//     checkEqual(town2.getStatus(), std::make_tuple<std::string, double, size_t>("Zombie", 3.14, 3),
//                "Initial town2 status correct.");
//
//     town2.tick(1);
//     checkEqual(town2.getStatus(), std::make_tuple<std::string, double, size_t>("Zombie", 3.14, 3),
//                "town2 after tick(1) status correct.");
//
//     town2.tick(12);
//     checkEqual(town2.getStatus(), std::make_tuple<std::string, double, size_t>("Zombie", 3.14, 3),
//                "town2 after tick(12) status correct.");
//
//     town2.tick(34);
//     //0.14 is probably not represantable by double, need checkEqual with tolerance
//     checkEqual(town2.getStatus(), std::make_tuple<std::string, double, size_t>("Zombie", 0.14000000000000012, 2),
//                "town2 after tick(34) status correct.");
//
//     town2.tick(66);
//     checkEqual(town2.getStatus(), std::make_tuple<std::string, double, size_t>("Zombie", 0., 2),
//                "town2 after tick(66) status correct.");
//
//     std::cout << "Citizens should win:\n";
//     town2.tick(1);

    finishTest();
}

int main() {
    testConstructor();
    testGetStatus();
    testTick();
}
