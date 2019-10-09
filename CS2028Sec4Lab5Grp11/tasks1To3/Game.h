#pragma once
#include <iostream>
class Game
{
protected: //variables a and b protected to be inherited
	int a;
	int b;

public:
	//default constructor
	Game(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}
	//destructor implementation
	~Game() {}
	//getters and setters
	void setA(int a) { this->a = a; }
	void setB(int b) { this->b = b; }
	int getA() { return a; }
	int getB() { return b; }

	virtual void play() {
		std::cout << "Let's Play" << std::endl;
	}
	void winner() {
		std::cout << "Not Yet" << std::endl;
	}
};