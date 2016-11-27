#ifndef MONSTER_H_
#define MONSTER_H_

#include <type_traits>

#include "citizen.h"

template<typename T>
class Monster {
	static_assert(std::is_arithmetic<T>::value,
	              "Monster parameter must be arithmetic.");
public:
	Monster(T health, T attackPower) : health_(health),
	                                   attackPower_(attackPower) {}

	T getHealth() const {return health_;}
	T getAttackPower() const {return attackPower_;}

	void takeDamage(T damage)
	{
		health_ = damage > health_ ? 0 : health_ - damage;
	}

	using valueType = T;
private:
	T health_;
	T attackPower_;
};

template<typename T>
using Zombie = Monster<T>;

template<typename T>
using Vampire = Monster<T>;

template<typename T>
using Mummy = Monster<T>;


template<typename T, typename U>
void attack(const Monster<T>& monster, U& victim) {
	static_assert(std::is_same<U, Teenager<typename U::valueType>>::value ||
	              std::is_same<U, Adult<typename U::valueType>>::value,
	              "Victim must be a Citizen.");
	victim.takeDamage(monster.getAttackPower());
}

template<typename T, typename V>
void attack(Monster<T>& monster, Sheriff<V>& victim) {
	victim.takeDamage(monster.getAttackPower());
	monster.takeDamage(victim.getAttackPower());
}

#endif
