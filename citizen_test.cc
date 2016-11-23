#include <cstdio>
#include "citizen.h"
int main()
{
	Teenager<int> teen1(123, 13);
	Sheriff<int> sheriff1(123, 42);
	printf("%d %d %d\n", teen1.getAge(), sheriff1.getAge(), sheriff1.getAttackPower());
}