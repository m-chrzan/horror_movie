#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <type_traits>
#include <cassert>

template<typename T, int MIN_AGE, int MAX_AGE, bool CAN_FIGHT>
class Citizen {
    static_assert(std::is_arithmetic<T>::value,
                  "Citizen parameter must be arithmetic.");
public:
    template<const bool can_fight = CAN_FIGHT,
             typename = std::enable_if_t<!can_fight>>
    Citizen(T const& health, T const& age) : health_(health), age_(age) {
        assert(age >= MIN_AGE && age <= MAX_AGE);
        assert(health > 0);
    }
    template<const bool can_fight = CAN_FIGHT,
             typename = std::enable_if_t<can_fight>>
    Citizen(T const& health, T const& age, T const& attackPower) :
        health_(health), age_(age), attackPower_(attackPower) {
        assert(age >= MIN_AGE && age <= MAX_AGE);
        assert(health > 0);
        assert(attackPower > 0);
    }

    T getHealth() const { return health_; }
    T getAge() const { return age_; }
    template<const bool can_fight = CAN_FIGHT,
             typename = std::enable_if_t<can_fight>>
    T getAttackPower() const { return attackPower_; }

    void takeDamage(T const& damage) {
        health_ = damage > health_ ? 0 : health_ - damage;
    }

    using valueType = T;
private:
    T health_;
    T age_;
    T attackPower_;
};

template<typename T>
using Teenager = Citizen<T, 11, 17, false>;

template<typename T>
using Adult = Citizen<T, 18, 100, false>;

template<typename T>
using Sheriff = Citizen<T, 18, 100, true>;

#endif
