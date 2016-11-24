#include "citizen.h"
#include "monster.h"
#include "testing.h"

void testMonsterConstructor() {
    beginTest();

    Zombie<int> z(100, 2);
    checkEqual(z.getHealth(), 100, "Int health set correctly.");
    checkEqual(z.getAttackPower(), 2, "Int power set correctly.");

    Mummy<double> m(50.42, 12.0);
    checkEqual(m.getHealth(), 50.42, "Double health set correctly.");
    checkEqual(m.getAttackPower(), 12.0, "Double power set correctly.");

    Vampire<char> v(13, 12);
    checkEqual<char>(v.getHealth(), 13, "Char health set correctly.");
    checkEqual<char>(v.getAttackPower(), 12, "Char power set correctly.");

    finishTest();
}

void testTakeDamage() {
    beginTest();

    Zombie<int> z(100, 2);
    z.takeDamage(50);
    checkEqual(z.getHealth(), 50, "Int damage taken.");

    Mummy<double> m(50.42, 12.0);
    m.takeDamage(5.42);
    checkEqual(m.getHealth(), 45.0, "Double damage taken.");
    m.takeDamage(45.0);
    checkEqual(m.getHealth(), 0.0, "Double damage taken again.");
    m.takeDamage(13.34);
    checkEqual(m.getHealth(), 0.0, "Double health doesn't go below 0.");

    Vampire<char> v(13, 12);
    v.takeDamage(10);
    checkEqual<char>(v.getHealth(), 3, "Char damage taken.");
    v.takeDamage(10);
    checkEqual<char>(v.getHealth(), 0, "Char health doesn't go below 0.");

    finishTest();
}

int main()
{
    testMonsterConstructor();
    testTakeDamage();
}
