#include "citizen.h"
#include "monster.h"

int main()
{
	Zombie<int> z1(100, 2);
	Mummy<double> m1(100., 1.);
	Vampire<unsigned char> v1(100, 5);

	Teenager<int> teen1(123, 13);
	attack(z1, teen1);
}
