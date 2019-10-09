#pragma once
#include "Game.h"
#include <iostream>
class VideoGame : public Game
{
private:
	int d; // private variable exclusive to videogame class
public:
	//default contstructor
	VideoGame(int a = 0, int b = 0, int d = 0) {
		this->a = a;
		this->b = b;
		this->d = d;
	}
	//destructor implementation
	~VideoGame() {}
	//getters and setters
	void setD(int d) { this->d = d; }
	int getD() { return d; }
	//overwrites play()
	void play() {
		std::cout << "Mash the buttons" << std::endl;
	}
	void winner() {
		std::cout << "Winner music" << std::endl;
	}
};