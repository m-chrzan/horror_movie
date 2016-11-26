#ifndef SMALLTOWN_H_
#define SMALLTOWN_H_

#include "monster.h"
#include "citizen.h"
#include <tuple>

template <typename M, typename U, U start_time, U end_of_day, typename... C>
class SmallTown {
    static_assert(std::is_unsigned<U>::value,
                  "The time type must be unsigned.");
    static_assert(start_time <= end_of_day,
                  "Start time must be before end time.");
public:
    SmallTown(M monster, C... citizens) : monster_(monster),
                                          citizens_(citizens...) {}
private:
    U current_time = start_time;
    M monster_;
    std::tuple<C...> citizens_;
    size_t number_citizens = std::tuple_size<std::tuple<C...>>::value;
    size_t number_living_citizens = number_citizens;
};

#endif
