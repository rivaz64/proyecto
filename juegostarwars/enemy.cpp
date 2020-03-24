#include "enemy.h"
#include <stdlib.h>
void enemy::update()
{
	t += time.delta;
	if (t > ya) {
		t = 0;
		ya = ((float)(rand() % 2000) + 1000.f) / 1000.f;
		player->balas.push_back(new shoot({ getPosition().x +s,getPosition().y + 79 }, {player->getPosition().x-getPosition().x,player->getPosition().y - getPosition().y }));
	}
	if (player->getPosition().x < getPosition().x) {
		setScale({ 1,1 });
		s = -20;
	}
	else {
		setScale({ -1,1 });
		s = 30;
	}
}



enemy::enemy(string a, string e):personaje(a,e)
{
	setTextureRect(normal);
	setOrigin({ 40,0 });
	ya = ((float)(rand() % 3000) + 1500.f) / 1000.f;
}

enemy::~enemy()
{
}
