#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <algorithm>
#include <cassert>

template <typename T, int MIN_AGE, int MAX_AGE, bool CAN_FIGHT>
class Citizen {
    static_assert(std::is_arithmetic<T>::value,
                  "Citizen parameter must be arithmetic.");
public:
    template <const bool fight = CAN_FIGHT, typename = std::enable_if_t<!fight>>
    Citizen(T const& health, T const& age) : health_(health), age_(age) {
        assert(age >= MIN_AGE && age <= MAX_AGE);
    }
    template <const bool fight = CAN_FIGHT, typename = std::enable_if_t<fight>>
    Citizen(T const& health, T const& age, T const& attack_power) :
        health_(health), age_(age), attack_power_(attack_power) {}
    T getHealth() const { return health_; }
    T getAge() const { return age_; }
    void takeDamage(T damage) {
        health_ = std::max<T>(health_ - damage, 0);
    }
    template <const bool fight = CAN_FIGHT, typename = std::enable_if_t<fight>>
    T getAttackPower() const { return attack_power_; }
    using valueType = T;
protected:
    T health_;
    T age_;
    T attack_power_;
};

template <typename T>
using Teenager = Citizen<T, 11, 17, false>;

template <typename T>
using Adult = Citizen<T, 18, 100, false>;

template <typename T>
using Sheriff = Citizen<T, 18, 100, true>;

#endif
