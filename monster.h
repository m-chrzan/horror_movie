#ifndef MONSTER_H_
#define MONSTER_H_

#include <type_traits>

template<typename T,
         typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class Monster {
public:
	Monster(T health, T attackPower) : health_(health),
	                                   attackPower_(attackPower) {}

private:
	T health_, attackPower_;
};

#endif
