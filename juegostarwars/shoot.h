#pragma once
#include "objeto.h"
#include "jugador.h"
class shoot :
	public objeto
{
public:
	objeto *x;
	jugador* este;
	shoot(sf::Vector2f,sf::Vector2f);
	sf::Vector2f delta;
	float t=0,dist;
	void update();
	void dir(sf::Vector2f);
	~shoot();
};

