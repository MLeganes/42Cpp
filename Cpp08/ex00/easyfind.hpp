
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int arg)
{
	typename T::iterator iter = find(container.begin(), container.end(), arg);
	if (container.end() == iter)
		throw std::invalid_argument("error: easyfind: argument no found in the container");
		//throw std::invalid_argument("error: easyfind: " + std::to_string(arg) + " no found in the container");
	return iter;
}

#endif