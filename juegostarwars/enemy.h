#pragma once
#include "personaje.h"
#include "shoot.h"
#include"jugador.h"
class enemy :
	public personaje
{
public:
	jugador* player;
	float ya;
	void update();
	float t = 2,s=20;
	enemy(string, string);
	~enemy();
};

