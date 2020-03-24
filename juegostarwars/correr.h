#pragma once
#include "accion.h"
class correr :
	public accion
{
public:
	correr(jugador*);
	void input();
	void update();
	~correr();
};

