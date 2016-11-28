#ifndef MONSTER_H_
#define MONSTER_H_

#include <type_traits>

#include "citizen.h"

template<typename T, int ID>
class Monster {
    static_assert(std::is_arithmetic<T>::value,
                  "Monster parameter must be arithmetic.");
public:
    Monster(T health, T attackPower) : health_(health),
                                       attackPower_(attackPower) {}

    T getHealth() const { return health_; }
    T getAttackPower() const { return attackPower_; }

    void takeDamage(T damage) {
        health_ = damage > health_ ? 0 : health_ - damage;
    }

    using valueType = T;
private:
    T health_;
    T attackPower_;
};

template<typename T>
using Zombie = Monster<T, 1>;

template<typename T>
using Vampire = Monster<T, 2>;

template<typename T>
using Mummy = Monster<T, 3>;

template<typename M, typename V>
void attack(const M& monster, V& victim) {
    victim.takeDamage(monster.getAttackPower());
}

template<typename M, typename T>
void attack(M& monster, Sheriff<T>& victim) {
    victim.takeDamage(monster.getAttackPower());
    monster.takeDamage(victim.getAttackPower());
}

#endif
