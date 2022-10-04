#ifndef EASYFIND_HPP
#   define EASYFIND_HPP

#   include <iostream>
#   include <string>
#   include <vector>
#   include <algorithm>
#   include <exception>

template <typename T>
typename T::iterator easyfind(T &type, int i) {
    return (find (type.begin(), type.end(), i));
}

#endif