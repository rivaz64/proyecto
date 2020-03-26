#pragma once
#include<vector>
#include<iostream>
#include"SFML/Graphics.hpp"
#include"deltaim.h"
class jugador;
using namespace std;
class animator_manager
{
public:
	vector<sf::IntRect> coords;
	vector<sf::Vector2i> tamaños;
	bool volatil= false;
	animator_manager();
	int cual = 0;
	void next();
	void next(float);
	float tiempo=0;
	float cadacuanto = .2f;
	deltaim time;
	sf::IntRect esta();
	~animator_manager();
};

