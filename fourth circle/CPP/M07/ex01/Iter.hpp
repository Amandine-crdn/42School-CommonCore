#ifndef ITER_HPP
#   define ITER_HPP

#   include <iostream>
#   include <iomanip>

template<typename T>
void display(T const &value)
{
	std::cout << value << " " << std::endl;
}

template <typename T>
void iter(T *x, int len, void (*f)(const T&)) 
{
    for (int i = 0; i < len; i++)
    (*f)(x[i]);
}

#endif