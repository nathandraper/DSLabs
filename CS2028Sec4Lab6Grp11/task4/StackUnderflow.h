#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H
#include <exception>

using namespace std;

class StackUnderflow : public std::exception
{
public:
	const char* what() const throw() override {
		return "Stack underflow error.";
	}
};
#endif

