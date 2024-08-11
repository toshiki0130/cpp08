#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template <typename T>
class MutantStack : public std::stack<int> {
private:

public:
    using iterator = typename std::stack<T>::container_type::iterator;
    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& other);

    iterator begin();
    iterator end();
    

};

# include "MutantStack.tpp"

#endif