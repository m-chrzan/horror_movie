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

    std::cout << "Town 1" << std::endl;
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

//     std::cout << "Town 2" << std::endl;
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

    std::cout << "Town 3" << std::endl;
    SmallTown<Mummy<double>, unsigned long, 20, 21, Sheriff<int>> town3(
        Mummy<double>(42.0, 5.5), Sheriff<int>(10, 100, 22)
    );

    town3.tick(1);
    checkEqual(town3.getStatus(), std::make_tuple<std::string, double, size_t>(
                "Mummy", 42.0, 1), "Status ok at t = 21");
    town3.tick(1);
    checkEqual(town3.getStatus(), std::make_tuple<std::string, double, size_t>(
                "Mummy", 20.0, 1), "Status ok at t = 0");
    town3.tick(4);
    checkEqual(town3.getStatus(), std::make_tuple<std::string, double, size_t>(
                "Mummy", 20.0, 1), "Status ok at t = 4");
    town3.tick(1);
    checkEqual(town3.getStatus(), std::make_tuple<std::string, double, size_t>(
                "Mummy", 20.0, 1), "Status ok at t = 5");
    town3.tick(1);
    checkEqual(town3.getStatus(), std::make_tuple<std::string, double, size_t>(
                "Mummy", 0.0, 0), "Status ok at t = 6");
    std::cout << "Should be a draw:" << std::endl;
    town3.tick(1);
    checkEqual(town3.getStatus(), std::make_tuple<std::string, double, size_t>(
                "Mummy", 0.0, 0), "Status ok at t = 7");

    std::cout << "Town 4" << std::endl;
    SmallTown<Zombie<int>, size_t, 1, 5, Teenager<int>, Teenager<float>,
        Teenager<char>>
    town4(
            Zombie<int>(1, 1), Teenager<int>(1, 13),
            Teenager<float>(1.5, 15.0), Teenager<char>(3, 17)
    );

    checkEqual(town4.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 3), "Status ok at t = 1");
    town4.tick(1);
    checkEqual(town4.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 2), "Status ok at t = 2");
    town4.tick(1);
    checkEqual(town4.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 1), "Status ok at t = 3");
    town4.tick(1);
    checkEqual(town4.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 0), "Status ok at t = 4");
    std::cout << "Monster should win:" << std::endl;
    town4.tick(1);
    checkEqual(town4.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 0), "Status ok at t = 5");

    std::cout << "Town 5" << std::endl;
    SmallTown<Zombie<int>, size_t, 8, 21, Sheriff<float>, Teenager<long>>
    town5(
            Zombie<int>(10, 5), Sheriff<float>(4.9, 20.8, 9.9),
            Teenager<long>(15, 15)
    );
    checkEqual(town5.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 10, 2), "Status ok at t = 8");
    town5.tick(5);
    checkEqual(town5.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 1), "Status ok at t = 13");
    town5.tick(8);
    checkEqual(town5.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 1), "Status ok at t = 21");
    town5.tick(1);
    checkEqual(town5.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 0), "Status ok at t = 0");
    std::cout << "Monster should win:" << std::endl;
    town5.tick(1);
    checkEqual(town5.getStatus(), std::make_tuple<std::string, int, size_t>(
                "Zombie", 1, 0), "Status ok at t = 1");

    finishTest();
}

int main() {
    testConstructor();
    testGetStatus();
    testTick();
}
