// main.cpp
#include <iostream>
#include <vector>
#include "Span.hpp"

void test_orthodox_canonical()
{
    Span sp1 = Span(3);
    sp1.addNumber(1);
    sp1.addNumber(2);
    sp1.addNumber(3);
    Span sp2 = Span(sp1);
    Span sp3;
    sp3 = sp1; 
}

void test_add_number()
{
    try{
        Span sp5 = Span(5);
        sp5.addNumber(1);
        std::cout << sp5;
        sp5.addNumber(2);
        std::cout << sp5;
        sp5.addNumber(3);
        std::cout << sp5;
        sp5.addNumber(4);
        std::cout << sp5;
        sp5.addNumber(5);
        std::cout << sp5;
        sp5.addNumber(6);
        std::cout << sp5;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    {
        try {
            Span large_span = Span(1000);
            std::vector<int> large_numbers;
            for (int i=0; i < 1000; i++)
                large_numbers.push_back(i);
            large_span.addNumber(large_numbers.begin(), large_numbers.end());

            large_span.addNumber(1000);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }

    }
}

void test_from_gpt()
{
    try {
        Span sp = Span(10000);
        
        // 単一の数字を追加
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // イテレータを使って複数の数字を追加
        std::vector<int> additional_numbers;
        additional_numbers.push_back(2);
        additional_numbers.push_back(8);
        additional_numbers.push_back(1);
        additional_numbers.push_back(15);
        additional_numbers.push_back(5);
        sp.addNumber(additional_numbers.begin(), additional_numbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // 大量の数字を追加してテスト
        Span large_span(10000);
        std::vector<int> large_numbers;
        for (int i = 0; i < 10000; ++i) {
            large_numbers.push_back(i);
        }
        large_span.addNumber(large_numbers.begin(), large_numbers.end());

        std::cout << "Shortest span in large_span: " << large_span.shortestSpan() << std::endl;
        std::cout << "Longest span in large_span: " << large_span.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void test_from_subject()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main() {
    
    test_orthodox_canonical();
    test_add_number(); 
    test_from_gpt();
    test_from_subject();
    return 0;
}
