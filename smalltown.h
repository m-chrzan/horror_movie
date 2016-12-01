#ifndef SMALLTOWN_H_
#define SMALLTOWN_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>

#include "citizen.h"
#include "monster.h"

// If we have generated FN numbers, return the contents of V as a std::array.
template<typename U, size_t FN, U FIB_LAST, U FIB_CURR, U ...V>
constexpr typename std::enable_if_t<FN == sizeof...(V),
std::array<U, FN>> generateFibonacciNumbers() {
    return std::array<U, FN>{{V...}};
}
// If we haven't generated FN numbers yet, add the next to the V parameter pack.
template<typename U, size_t FN, U FIB_LAST, U FIB_CURR, U ...V>
constexpr typename std::enable_if_t<FN != sizeof...(V),
std::array<U, FN>> generateFibonacciNumbers() {
    return generateFibonacciNumbers<U, FN,
                                    FIB_CURR, static_cast<U>(FIB_LAST + FIB_CURR),
                                    V..., FIB_LAST>();
}

template<typename M, typename U, U START_TIME, U END_OF_DAY, typename... C>
class SmallTown {
    static_assert(std::is_integral<U>::value,
                  "The time type must be integral.");
    static_assert(START_TIME >= 0, "Start time must be non-negative.");
    static_assert(START_TIME <= END_OF_DAY,
                  "Start time must be before end time.");
public:
    SmallTown(M const& monster, C const &... citizens) : monster_(monster),
                                          citizens_(citizens...) {}

    std::tuple<std::string, typename M::valueType, size_t> getStatus() const {
        return std::make_tuple(getMonsterName(monster_),
                               monster_.getHealth(),
                               numberLivingCitizens_);
    }

    void tick(U const& timestep) {
        if (monster_.getHealth() == 0) {
            if (numberLivingCitizens_ == 0)
                std::cout << "DRAW\n";
            else
                std::cout << "CITIZENS WON\n";
            return;
        } else if (numberLivingCitizens_ == 0) {
            std::cout << "MONSTER WON\n";
            return;
        }

        if (std::binary_search(fibs().begin(), fibs().end(), currentTime_))
            attackAll();

        currentTime_ += timestep;
        currentTime_ %= END_OF_DAY + 1;
    }
private:
    U currentTime_ = START_TIME;
    M monster_;
    std::tuple<C...> citizens_;

    size_t numberCitizens_ = std::tuple_size<std::tuple<C...>>::value;
    size_t numberLivingCitizens_ = numberCitizens_;

    template<typename T, MonsterID ID>
    static std::string getMonsterName(Monster<T, ID> const &m) {
        return "Monster";
    }
    template<typename T>
    static std::string getMonsterName(Monster<T, MonsterID::ZOMBIE> const &m) {
        return "Zombie";
    }
    template<typename T>
    static std::string getMonsterName(Monster<T, MonsterID::VAMPIRE> const &m) {
        return "Vampire";
    }
    template<typename T>
    static std::string getMonsterName(Monster<T, MonsterID::MUMMY> const &m) {
        return "Mummy";
    }

    template<size_t I = 0>
    inline typename std::enable_if_t<I == sizeof...(C)> attackAll() {}
    template<size_t I = 0>
    inline typename std::enable_if_t<I < sizeof...(C)> attackAll() {
        bool wasAlive = std::get<I>(citizens_).getHealth() != 0;
        attack(monster_, std::get<I>(citizens_));
        if (wasAlive && std::get<I>(citizens_).getHealth() == 0)
            --numberLivingCitizens_;
        attackAll<I + 1>();
    }

    // Recursively count how many Fibonacci numbers are <= END_OF_DAY.
    constexpr static size_t numberOfFibs(size_t f, size_t s, size_t r) {
        return (s > END_OF_DAY) || (s < f) ? r : numberOfFibs(s, f + s, r + 1);
    }
    constexpr static size_t numberOfFibs() {
        return numberOfFibs(0, 1, 1);
    }

    static const std::array<U, numberOfFibs()>& fibs() {
        static std::array<U, numberOfFibs()>
            fibonacciNumbers(generateFibonacciNumbers<U, numberOfFibs(), 1, 2>());
        return fibonacciNumbers;
    }
};

#endif
