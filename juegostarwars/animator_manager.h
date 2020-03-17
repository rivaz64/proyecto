#pragma once
#include<vector>
#include<iostream>
#include"SFML/Graphics.hpp"
#include"deltaim.h"
using namespace std;
class animator_manager
{
public:
	vector<sf::IntRect> coords;
	animator_manager();
	int cual = 0;
	void next();
	float tiempo=0;
	float cadacuanto = .2f;
	deltaim time;
	sf::IntRect esta();
	~animator_manager();
};

