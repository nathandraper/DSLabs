#pragma once

using namespace std;

class EmptyShelf : public exception
{
private:


public:

	//Exception Class to test to see if the shelf is full
	const char* what() const throw() override {

		return "This shelf is empty";
	}
};
