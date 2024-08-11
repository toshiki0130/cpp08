#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <iostream>
# include "MutantStack.hpp"

// orthodox canonical form
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

// member functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

// reverse_iterator
template <typename T>
typename MutantStack<T>::riterator MutantStack<T>::rbegin()
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::riterator MutantStack<T>::rend()
{
    return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_riterator MutantStack<T>::rbegin() const
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_riterator MutantStack<T>::rend() const
{
    return std::stack<T>::c.rend();
}
#endif

// ostream
template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& mstack)
{
    typename MutantStack<T>::const_iterator it;
    for (it = mstack.begin(); it != mstack.end(); it++) {
        if (it != mstack.begin()) {
            os << ",";
        }
        os << *it;
    }
    return os;
}