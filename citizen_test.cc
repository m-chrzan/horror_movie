#include "testing.h"
#include "citizen.h"

#include <vector>

void testTeenagerConstructor() {
    beginTest();

    Teenager<int> teen1(123, 13);
    checkEqual(teen1.getHealth(), 123, "Int health set correctly.");
    checkEqual(teen1.getAge(), 13, "Int age set correctly.");

    Teenager<double> teen2(42, 11);
    checkEqual(teen2.getHealth(), 42.0, "Double health set correctly.");
    checkEqual(teen2.getAge(), 11.0, "Double age set correctly.");

    Teenager<char> teen3(42, 17);
    checkEqual<char>(teen3.getHealth(), 42, "Char health set correctly.");
    checkEqual<char>(teen3.getAge(), 17, "Char age set correctly.");

    finishTest();
}

void testAdultConstructor() {
    beginTest();

    Adult<int> adult1(123, 42);
    checkEqual(adult1.getHealth(), 123, "Int health set correctly.");
    checkEqual(adult1.getAge(), 42, "Int age set correctly.");

    Adult<double> adult2(42.0, 18.0);
    checkEqual(adult2.getHealth(), 42.0, "Double health set correctly.");
    checkEqual(adult2.getAge(), 18.0, "Double age set correctly.");

    Adult<char> adult3(42, 100);
    checkEqual<char>(adult3.getHealth(), 42, "Char health set correctly.");
    checkEqual<char>(adult3.getAge(), 100, "Char age set correctly.");

    finishTest();
}

void testSheriffConstructor() {
    beginTest();

    Sheriff<int> sheriff1(123, 42, 15);
    checkEqual(sheriff1.getHealth(), 123, "Int health set correctly.");
    checkEqual(sheriff1.getAge(), 42, "Int age set correctly.");
    checkEqual(sheriff1.getAttackPower(), 15, "Int power set correctly.");

    Sheriff<double> sheriff2(42.0, 18.0, 34.3);
    checkEqual(sheriff2.getHealth(), 42.0, "Double health set correctly.");
    checkEqual(sheriff2.getAge(), 18.0, "Double age set correctly.");
    checkEqual(sheriff2.getAttackPower(), 34.3, "Double power set correctly.");

    Sheriff<char> sheriff3(42, 100, 31);
    checkEqual<char>(sheriff3.getHealth(), 42, "Char health set correctly.");
    checkEqual<char>(sheriff3.getAge(), 100, "Char age set correctly.");
    checkEqual<char>(sheriff3.getAttackPower(), 31, "Char power set correctly.");

    finishTest();
}

int main() {
    testTeenagerConstructor();
    testAdultConstructor();
    testSheriffConstructor();

    return 0;
}
