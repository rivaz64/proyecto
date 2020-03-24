#include "objeto.h"

vector<objeto*> objeto::objects = {};

objeto::objeto(string a)
{
	textura.loadFromFile(a);
	setTexture(&textura);
}


objeto::~objeto()
{
}
