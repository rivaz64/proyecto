#pragma once
#include "accion.h"
class caminar :
	public accion
{
public:
	caminar(jugador*);
	void input();
	void update();
	~caminar();
};

