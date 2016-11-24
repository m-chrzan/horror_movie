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

int main()
{
    testMonsterConstructor();
}
