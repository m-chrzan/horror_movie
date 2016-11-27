#ifndef SMALLTOWN_H_
#define SMALLTOWN_H_

#include "monster.h"
#include "citizen.h"
#include <string>
#include <tuple>
#include <type_traits>

template <typename M, typename U, U start_time, U end_of_day, typename... C>
class SmallTown {
    static_assert(std::is_unsigned<U>::value,
                  "The time type must be unsigned.");
    static_assert(start_time <= end_of_day,
                  "Start time must be before end time.");
public:
    SmallTown(M monster, C... citizens) : monster_(monster),
                                          citizens_(citizens...) {}
    std::tuple<std::string, typename M::valueType, size_t> getStatus() {
        return std::make_tuple(getMonsterName(monster_), monster_.getHealth(),
                               number_living_citizens);
    }
private:
    U current_time = start_time;
    M monster_;
    std::tuple<C...> citizens_;
    size_t number_citizens = std::tuple_size<std::tuple<C...>>::value;
    size_t number_living_citizens = number_citizens;
    template<typename T, int ID>
    static std::string getMonsterName(Monster<T, ID> const &m) {
        return "Monster";
    }
    template<typename T>
    static std::string getMonsterName(Monster<T, 1> const &m) {
        return "Zombie";
    }
    template<typename T>
    static std::string getMonsterName(Monster<T, 2> const &m) {
        return "Vampire";
    }
    template<typename T>
    static std::string getMonsterName(Monster<T, 3> const &m) {
        return "Mummy";
    }
};

#endif
