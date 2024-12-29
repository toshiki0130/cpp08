#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

#include "easyfind.hpp"

int main()
{
    {
        std::vector<int> vc;
        for (int i=0; i<10; i++) {
            vc.push_back(i);
        }

        try {
            std::vector<int>::iterator it = easyfind(vc, 3);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
        try {
            std::vector<int>::iterator it = easyfind(vc, 11);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::list<int> ls;
        for (int i=0; i<10; i++) {
            ls.push_back(i);
        }

        try {
            std::list<int>::iterator it = easyfind(ls, 3);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
        try {
            std::list<int>::iterator it = easyfind(ls, 11);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
    }
    {
        // constの場合
        std::vector<int> vc;
        for (int i=0; i<10; i++) {
            vc.push_back(i);
        }
        const std::vector<int> &c_vc = vc;
        try {
            std::vector<int>::const_iterator it = easyfind(c_vc, 3);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
        try {
            std::vector<int>::const_iterator it = easyfind(c_vc, 11);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::list<int> ls;
        for (int i=0; i<10; i++) {
            ls.push_back(i);
        }
        const std::list<int> &c_ls = ls; 
        try {
            std::list<int>::const_iterator it = easyfind(c_ls, 3);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
        try {
            std::list<int>::const_iterator it = easyfind(c_ls, 11);
            std::cout << "it: " << *it << std::endl;
        } catch (const std::exception& e){ 
            std::cout << e.what() << std::endl;
        }
    }
}