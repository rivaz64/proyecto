#include "objeto.h"
#include"enemy.h"
vector<objeto*> objeto::objects = {};
objeto::objeto(string a)
{
	textura.loadFromFile(a);
	setTexture(&textura);
}


objeto::~objeto()
{
}
