#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
   typename T::iterator it = std::find(container.begin(), container.end(), value);
   if (it == container.end()) {
        throw::std::out_of_range("Value not found in container");
   } 
   return it;
}

#endif