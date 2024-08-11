#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <iostream>
template <typename T>
class MutantStack : public std::stack<T> {
private:

public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator riterator; 
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_riterator;

    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& other);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    riterator rbegin();
    riterator rend();
    const_riterator rbegin() const;
    const_riterator rend() const;

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& mstack);

# include "MutantStack.tpp"

#endif