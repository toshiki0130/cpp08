#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>

class Span {
private:
    unsigned int _max_size;
    std::vector<int> _numbers;

public:
    // orthodox canonical form
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span &operator=(const Span& other);
    ~Span();

    // member functions
    void	addNumber(int n);
    void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int		shortestSpan() const;
    int		longestSpan() const;
	void	printNumbers(std::ostream& os) const;

	// exceptions
	class SpanFullException : public std::exception {
	public:
		const char* what() const throw();
	};
	
	class SpanNotFoundException : public std::exception {
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Span& sp);
#endif