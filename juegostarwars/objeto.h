#pragma once
#include<string>
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
class objeto:public sf::RectangleShape
{
public:
	sf::Texture textura;
	objeto(string);
	~objeto();
};

