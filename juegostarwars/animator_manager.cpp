#include "animator_manager.h"
#include"jugador.h"


animator_manager::animator_manager()
{
}

//pasa a la siguiente animacion
void animator_manager::next()
{
	tiempo += time.delta;
	if (tiempo > cadacuanto) {
		tiempo = 0;
		cual += 1;
		cual %= coords.size();
	}
	
}
//la animacion en al que esta
sf::IntRect animator_manager::esta()
{
	return coords[cual];
}

animator_manager::~animator_manager()
{
}
