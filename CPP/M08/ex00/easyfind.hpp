#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <list>
# include <vector>
# include <iostream>
# include <algorithm>

template <typename T>
void easyfind(T &container, int n)
{
    typename    T::const_iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
    {
        std::cout << "Value exists." << std::endl;
    }
    else
    {
        std::cout << "Value doesn't exist in the container." << std::endl;
    }
}

#endif