#include "accion.h"
#include "caminar.h"
/*#include"correr.h"
accion::accion(jugador* a)
{
	cual = 0;
	este = a;
	coords = { este->normal };
}
void accion::input()
{
	if (este->r) {
		dir = 1;
		este->set(new caminar(este));
	}
	if (este->l) {
		dir = -1;
		este->set(new caminar(este));
	}
	if (este->jump) {
		este->set(new saltar(este, { 0,-1.1f }));
	}
}
*/
void accion::render()
{
	next();
	este->setTextureRect(coords[cual]);
}

void accion::next()
{
	tiempo += time.delta;
	if (tiempo > cadacuando) {
		tiempo = 0;
		cual += 1;
		cual %= coords.size();
	}
	tiempo += time.delta;
}

accion::~accion()
{
}
