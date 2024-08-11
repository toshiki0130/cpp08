#include "MutantStack.hpp"
#include <iostream>
#include <list>

void test_orthodox_canonical_form()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(4);
    mstack.push(3);
    std::cout << mstack << std::endl;

    MutantStack<int> mstack2(mstack);
    std::cout << mstack2 << std::endl;
    MutantStack<int> mstack3;
    mstack3 = mstack2;
    std::cout << mstack3 << std::endl;
}

void test_subject()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void test_compare_with_list()
{
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    for (MutantStack<int>::iterator mit = mstack.begin(); mit < mstack.end(); mit++) {
        std::cout << *mit << std::endl;
    }
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); lit++) {
        std::cout << *lit << std::endl;
    }
}

int main()
{
    test_orthodox_canonical_form();
    test_subject();
    test_compare_with_list();
}