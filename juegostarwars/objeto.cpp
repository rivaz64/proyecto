#include "objeto.h"
#include"enemy.h"
vector<objeto*> objeto::objects = {};
//le pone la textura
objeto::objeto(string a)
{
	textura.loadFromFile(a);
	setTexture(&textura);
}


objeto::~objeto()
{
}
