#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H
#include <exception>


class StackOverflow : public std::exception
{
public:
	const char* what() const throw() override {
		return "Stack overflow error.";
	}
};
#endif

