#pragma once
#include "Game.h"
#include <iostream>
class BoardGame : public Game
{
private:
	int c; //private variable exclusive to boardgame class
public:
	//default contrstructor
	BoardGame(int a = 0, int b = 0, int c = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	//destructor implementation
	~BoardGame() {}
	//getters and setters
	void setC(int c) { this->c = c; }
	int getC() { return c; }
	//overwrites play()
	void play() {
		std::cout << "Roll the dice" << std::endl;
	}
	void winner() {
		std::cout << "Dancing time" << std::endl;
	}
};