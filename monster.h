#ifndef MONSTER_H_
#define MONSTER_H_

#include <type_traits>

#include "citizen.h"

template<typename T,
         typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class Monster {
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
void attack(Monster<T> monster, U victim) {}

#endif
