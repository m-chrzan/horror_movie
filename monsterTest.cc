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

    Vampire<unsigned> v2(100, 14);
    unsigned alot = 1000, zero = 0;
    v2.takeDamage(alot);
    checkEqual(v2.getHealth(), zero, "Unsigned health overflow.");

    finishTest();
}

void testAttack() {
    beginTest();

    Zombie<int> z(100, 20);
    Teenager<int> t(42, 15);
    attack(z, t);
    checkEqual(t.getHealth(), 22, "Teenager has taken damage.");
    checkEqual(z.getHealth(), 100, "Zombie has not taken damage.");
    attack(z, t);
    attack(z, t);
    checkEqual<int>(t.getHealth(), 0, "Teenager down to 0 health.");

    Mummy<double> m(4.2, 0.5);
    Adult<double> a(2.1, 18.1);
    attack(m, a);
    checkEqual(a.getHealth(), 1.6, "Adult has taken damage.");
    checkEqual(m.getHealth(), 4.2, "Mummy has not taken damage.");
    attack(m, a);
    attack(m, a);
    attack(m, a);
    attack(m, a);
    checkEqual(a.getHealth(), 0.0, "Adult down to 0 health.");

    Vampire<char> v(15, 4);
    Sheriff<char> s(9, 99, 8);
    attack(v, s);
    checkEqual<char>(s.getHealth(), 5, "Sheriff has taken damage.");
    checkEqual<char>(v.getHealth(), 7, "Vampire has taken damage.");
    attack(v, s);
    checkEqual<char>(s.getHealth(), 1, "Sheriff has taken damage.");
    checkEqual<char>(v.getHealth(), 0, "Vampire down to 0 health.");

    Vampire<char> v2(10, 2);
    attack(v2, s);
    checkEqual<char>(s.getHealth(), 0, "Sheriff down to 0 health.");

    finishTest();
}

int main()
{
    testMonsterConstructor();
    testTakeDamage();
    testAttack();
}
