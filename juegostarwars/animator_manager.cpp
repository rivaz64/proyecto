#include "animator_manager.h"



animator_manager::animator_manager()
{
}


void animator_manager::next()
{
	tiempo += time.delta;
	if (tiempo > cadacuanto) {
		tiempo = 0;
		cual += 1;
		cual %= coords.size();
	}
}

sf::IntRect animator_manager::esta()
{
	return coords[cual];
}

animator_manager::~animator_manager()
{
}
