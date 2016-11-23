#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <cassert>
#include <type_traits>

template <typename T, int MIN_AGE, int MAX_AGE, bool CAN_FIGHT>
class Citizen {
public:
	Citizen(T const& health, T const& age) : health_(health), age_(age) {
		assert(age >= MIN_AGE && age <= MAX_AGE);
	}
	T getHealth() const { return health_; }
	T getAge() const { return age_; }
	void takeDamage(T damage) {
		health_ = std::max<T>(health_ - damage, 0);
	}
// 	template <typename T>
	typename std::enable_if<CAN_FIGHT, T>::type getAttackPower() { return 2*age_; }
private:
	T health_;
	T age_;
};

// template <typename T, int MIN_AGE, int MAX_AGE>
// class Citizen<T, MIN_AGE, MAX_AGE, true> :
//     public CitizenBase<T, MIN_AGE, MAX_AGE, true> {
// public:
//     Citizen(T const& health, T const& age, T const& attack_power) :
//         CitizenBase<T, MIN_AGE, MAX_AGE, true>(health, age),
//         attack_power_(attack_power) {}
//     T getAttackPower() { return attack_power_; }
// private:
//     T attack_power_;
// };

template <typename T>
using Teenager = Citizen<T, 11, 17, false>;

template <typename T>
using Adult = Citizen<T, 18, 100, false>;

template <typename T>
using Sheriff = Citizen<T, 18, 100, true>;

#endif
