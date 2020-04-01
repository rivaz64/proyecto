#include "enemy.h"
#include <stdlib.h>
#include"punteros.h"
void enemy::update()
{
	personaje::update();
	t += time.delta;
	if (vivo) {
		//dispara apuntando a donde esta el jugador
		if (t > ya) {
			t = 0;
			ya = ((float)(rand() % 5000) + 3000.f) / 1000.f;
			player->balas.push_back(new shoot({ getPosition().x + s,getPosition().y + 79 }, { player->getPosition().x - getPosition().x,player->getPosition().y - getPosition().y }));
			player->balas[player->balas.size() - 1]->este = player;
		}
		//voltea a ver donde esta viendo el jugador
		if (player->getPosition().x < getPosition().x) {
			setScale({ 1,1 });
			dir = 1;
			s = -20;
		}
		else {
			setScale({ -1,1 });
			dir = -1;
			s = 30;
		}
	}
	else {
		//muere
		personaje::dying();
		//desaparece
		if (t > 1.5f) {
			objects.erase(std::find(objects.begin(), objects.end(), this));
			punteros::po.erase(std::find(punteros::po.begin(), punteros::po.end(), this));
			delete this;
		}
		
	}
}





enemy::enemy(string a, string e):personaje(a,e)
{
	ifstream file;
	string w;
	setTextureRect(normal);
	setOrigin({ 40,0 });
	ya = ((float)(rand() % 3000) + 1500.f) / 1000.f;
}

enemy::~enemy()
{
}
