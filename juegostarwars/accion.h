#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include"jugador.h"
#include"deltaim.h"
class accion
{
public:
	deltaim time;
	float tiempo;
	float cadacuando;
	std::vector<sf::IntRect> coords;
	accion(jugador*);
	accion() {}
	jugador* este;
	int cual,dir;
	//virtual void input();
	virtual void update() {}
	virtual void render();
	void next();
	~accion();
};

