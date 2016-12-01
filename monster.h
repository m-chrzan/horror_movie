#ifndef MONSTER_H_
#define MONSTER_H_

#include <cassert>
#include <type_traits>

#include "citizen.h"

enum class MonsterID {
    ZOMBIE, VAMPIRE, MUMMY
};

template<typename T, MonsterID ID>
class Monster {
    static_assert(std::is_arithmetic<T>::value,
                  "Monster parameter must be arithmetic.");
public:
    Monster(T const& health, T const& attackPower) : health_(health),
                                                     attackPower_(attackPower) {
        assert(health > 0);
        assert(attackPower > 0);
    }

    T getHealth() const { return health_; }
    T getAttackPower() const { return attackPower_; }

    void takeDamage(T const& damage) {
        health_ = damage > health_ ? 0 : health_ - damage;
    }

    using valueType = T;
private:
    T health_;
    T attackPower_;
};

template<typename T>
using Zombie = Monster<T, MonsterID::ZOMBIE>;

template<typename T>
using Vampire = Monster<T, MonsterID::VAMPIRE>;

template<typename T>
using Mummy = Monster<T, MonsterID::MUMMY>;

// Monster attacks any victim.
template<typename M, typename V>
void attack(const M& monster, V& victim) {
    victim.takeDamage(monster.getAttackPower());
}
// Specialization. Monster attacks a Sheriff.
template<typename M,
         typename V,
         typename = std::enable_if_t<std::is_same<V, Sheriff<typename V::valueType>>::value>>
void attack(M& monster, V& victim) {
    if (victim.getHealth() != 0)
        monster.takeDamage(victim.getAttackPower());
    victim.takeDamage(monster.getAttackPower());
}

#endif
