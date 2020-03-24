/*#include "saltar.h"



saltar::saltar(jugador*a, sf::Vector2f v):accion(a)
{
	coords = { {10, 940, 45, 60 },{60, 940, 45, 60},{110, 940, 45, 60} };
	vel = v;
	cadacuando = .15f;
}

void saltar::input()
{
	if (este->r) {
		dir = 1;
	}
	if (este->l) {
		dir = -1;
	}
	
	
}


void saltar::update()
{
	este->move({ dir*time.delta * vel.x,vel.y });
	este->setScale<sf::Vector2>({ dir, 1 });
	vel.y += time.delta * 2;
}

void saltar::render()
{
	if (cual != 2) {
		next();
	}
	este->setTextureRect(coords[cual]);
}

saltar::~saltar()
{
}*/
