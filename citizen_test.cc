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

void testTeenagerTakeDamage() {
    beginTest();

    Teenager<int> teen1(42, 13);
    teen1.takeDamage(18);
    checkEqual(teen1.getHealth(), 24, "Int damage taken.");

    teen1.takeDamage(25);
    checkEqual(teen1.getHealth(), 0, "Int health doesn't go below 0.");

    Teenager<double> teen2(100.0, 14.0);
    teen2.takeDamage(50.5);
    checkEqual(teen2.getHealth(), 49.5, "Double damage taken.");
    teen2.takeDamage(49.5);
    checkEqual(teen2.getHealth(), 0.0, "Double damage taken again.");
    teen2.takeDamage(50.0);
    checkEqual(teen2.getHealth(), 0.0, "Double health doesn't go below 0.");

    Teenager<unsigned> teen3(100, 14);
    unsigned alot = 1000, zero = 0;
    teen3.takeDamage(alot);
    checkEqual(teen3.getHealth(), zero, "Unsigned health overflow.");

    finishTest();
}

void testAdultTakeDamage() {
    beginTest();

    Adult<int> adult1(42, 42);
    adult1.takeDamage(18);
    checkEqual(adult1.getHealth(), 24, "Damage taken.");

    adult1.takeDamage(25);
    checkEqual(adult1.getHealth(), 0, "Health doesn't go below 0.");

    Adult<double> adult2(100.0, 23.9);
    adult2.takeDamage(50.5);
    checkEqual(adult2.getHealth(), 49.5, "Double damage taken.");
    adult2.takeDamage(49.5);
    checkEqual(adult2.getHealth(), 0.0, "Double damage taken again.");
    adult2.takeDamage(50.0);
    checkEqual(adult2.getHealth(), 0.0, "Double health doesn't go below 0.");

    finishTest();
}

void testSheriffTakeDamage() {
    beginTest();

    Sheriff<int> sheriff1(42, 42, 124);
    sheriff1.takeDamage(18);
    checkEqual(sheriff1.getHealth(), 24, "Damage taken.");

    sheriff1.takeDamage(25);
    checkEqual(sheriff1.getHealth(), 0, "Health doesn't go below 0.");

    Sheriff<double> sheriff2(100.0, 23.9, 3.14);
    sheriff2.takeDamage(50.5);
    checkEqual(sheriff2.getHealth(), 49.5, "Double damage taken.");
    sheriff2.takeDamage(49.5);
    checkEqual(sheriff2.getHealth(), 0.0, "Double damage taken again.");
    sheriff2.takeDamage(50.0);
    checkEqual(sheriff2.getHealth(), 0.0, "Double health doesn't go below 0.");

    finishTest();
}

int main() {
    testTeenagerConstructor();
    testAdultConstructor();
    testSheriffConstructor();
    testTeenagerTakeDamage();
    testAdultTakeDamage();
    testSheriffTakeDamage();

    return 0;
}
