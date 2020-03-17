#include "objeto.h"



objeto::objeto(string a)
{
	textura.loadFromFile(a);
	setTexture(&textura);
}


objeto::~objeto()
{
}
