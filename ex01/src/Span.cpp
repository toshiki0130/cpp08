#include "Span.hpp"
#include <algorithm>

Span::Span() : _max_size(0)
{}

Span::Span(unsigned int n) : _max_size(n)
{}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other) {
        _max_size = other._max_size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}


// member functions
void Span::addNumber(int n)
{
    if (_numbers.size() >= _max_size)
        throw SpanFullException();
    _numbers.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_numbers.size() + std::distance(begin, end) > _max_size)
        throw SpanFullException();
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw SpanNotFoundException();
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (unsigned int i=2; i < _numbers.size(); i++) {
        if (tmp[i] - tmp[i-1] < shortest)
            shortest = tmp[i] - tmp[i-1];
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw SpanNotFoundException();
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::printNumbers(std::ostream& os) const
{
    for (unsigned int i=0; i < _numbers.size(); i++) {
        os << _numbers[i];
        if (i != _numbers.size() - 1) {
            os << ',';
        }
    }
}

// exceptions
const char* Span::SpanFullException::what() const throw()
{
    return "This object is already full";
}

const char* Span::SpanNotFoundException::what() const throw()
{
    return "This object don't have span";
}

// operator << をoverload
std::ostream& operator<<(std::ostream& os, const Span& sp)
{
    sp.printNumbers(os);
    os << std::endl;
    return os;
}
