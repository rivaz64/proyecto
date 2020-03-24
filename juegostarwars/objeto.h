#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"SFML/Graphics.hpp"
#include"deltaim.h"
using namespace std;
class objeto:public sf::RectangleShape
{
public:
	static vector<objeto*> objects;
	virtual void update() {}
	deltaim time;
	sf::Texture textura;
	objeto(string);
	~objeto();
};

