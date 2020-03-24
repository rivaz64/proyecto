#pragma once
#include "accion.h"
class saltar :
	public accion
{
public:
	sf::Vector2f vel;
	saltar(jugador*,sf::Vector2f);
	void input();
	void update();
	void render();
	~saltar();
};

