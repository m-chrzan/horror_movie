#ifndef SMALLTOWN_H_
#define SMALLTOWN_H_

#include <list>
#include <tuple>

#include "citizen.h"
#include "monster.h"

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
	constexpr static std::list<U> genFibs()
	{
		U first = 0, second = 1;
		while (first < start_time) {
			U tmp = first + second;
			first = second;
			second = tmp;
		}
		if (first > end_of_day)
			return std::list<U>();

		std::list<U> res({first});
		while (second <= end_of_day) {
			res.push_back(second);
			U tmp = first + second;
			first = second;
			second = tmp;
		}
		return res;
	}
	const std::list<U>& fibs() const
	{
		static std::list<U> generatedOnce(genFibs());
		return generatedOnce;
	}

    U current_time = start_time;
    M monster_;
    std::tuple<C...> citizens_;
    size_t number_citizens = std::tuple_size<std::tuple<C...>>::value;
    size_t number_living_citizens = number_citizens;
};

#endif
