/*#include "correr.h"



correr::correr(jugador* a):accion(a)
{
	coords = { {192, 500, 65, 60 },{257, 500, 65, 60 },{322, 500, 65, 60 },{387, 500, 65, 60 },{370, 561, 65, 60 } };
	cadacuando = .2f;
}

void correr::input()
{
	if (este->r) {
		dir = 1;
	}
	else if (este->l) {
		dir = -1;
	}
	else {
		este->set(new accion(este));
	}
	if (!este->run) {
		este->set(new caminar(este));
	}
	if (este->jump) {
		este->set(new saltar(este, { 200,-1.1f }));
	}
}


void correr::update()
{
	este->move({ dir*time.delta * 200,0 });
	este->setScale({ dir*65.f / 45.f, 1 });
}

correr::~correr()
{
}*/
