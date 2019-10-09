#pragma once

using namespace std;

class FullShelf : public exception
{
private:


public:

	//Exception Class to test to see if the shelf is full
	const char* what() const throw() override {

		return "This shelf is full";
	}
};
#pragma once
#include "GameShelf.h"
#include <exception>
using namespace std;


