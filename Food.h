#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "game.h"

using namespace sf;
using namespace std;

class food {
public:
	Texture tex;
	Sprite spr;
	bool show;
	virtual int score() = 0;
	food() {

	}
};


class Red_Rectangle:public food {
public:
	int score() {
		show = false;
		return 5;
	}
	//Box smallBoxes[44];
	Red_Rectangle() {
		tex.loadFromFile("img/PNG/FOOD/food1.png");
		spr.setTexture(tex);
		spr.setScale(0.5,0.5);
		spr.setPosition(10,10);
		show = true;
	}

};

//
//int score() {
//	show = false;
//
//	return 5;
//
//}