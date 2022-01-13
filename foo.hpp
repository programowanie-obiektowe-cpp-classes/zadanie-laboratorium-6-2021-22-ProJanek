#pragma once

#include "Human.hpp"
#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > ret_v(people.size());
    std::for_each(begin(people), end(people), [](Human& person) { person.birthday(); });
    std::transform(begin(people), end(people), rbegin(ret_v), [](Human& person) {
        return person.isMonster() ? 'n' : 'y';
    });
    return ret_v;
}
