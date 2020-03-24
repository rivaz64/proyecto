/*#include "caminar.h"



caminar::caminar(jugador* a):accion(a)
{
	cadacuando = .2f;
	coords = { { 0,500, 45, 60 },{ 50,500, 45, 60},{ 100,500, 45, 60 },{ 150,500, 45, 60 } };
}

void caminar::input()
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
	if (este->run) {
		este->set(new correr(este));
	}
	if (este->jump) {
		este->set(new saltar(este, { 100,-1.1f }));
	}
}

void caminar::update()
{
	este->move({ dir*time.delta*100,0 });
	este->setScale(sf::Vector2f({ dir, 1 }));
}




caminar::~caminar()
{
}
*/