#include "shoot.h"
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include"punteros.h"
#include"enemy.h"
#define PI 3.14159265
shoot::shoot(sf::Vector2f p, sf::Vector2f d):objeto("disparo.png")
{
	k = 1;
	dir(d);
	setTextureRect(sf::IntRect(425, 175, 50, 20));
	objects.push_back(this);
	setPosition(p);
	setSize({ 150, 30 });
	setOrigin(51, 19);
}

void shoot::update()
{
	//mueve la bala
	move(time.delta*500*delta.x, time.delta  *500* delta.y);
	t+= time.delta;
	//la borra
	if (t > 3) {
		objects.erase(std::find(objects.begin(), objects.end(), this));
		jugador::balas.erase(std::find(jugador::balas.begin(), jugador::balas.end(), this));
		delete this;
	}
}

void shoot::dir(sf::Vector2f d)
{
	//le ponela direccion
	delta.x = d.x / sqrt(d.x*d.x + d.y*d.y);
	delta.y = d.y / sqrt(d.x*d.x + d.y*d.y);
	setRotation(atan(d.y / d.x) * 180 / PI);
}



void shoot::checka()
{
	//cheka donde esta
	int lon = 16;
	switch (k) {
	//se destrulle
	case 0:
		objects.erase(std::find(objects.begin(), objects.end(), this));
		jugador::balas.erase(std::find(jugador::balas.begin(), jugador::balas.end(), this));
		delete this;
		break;
	//si no a llegado al jugador
	case 1:
		if (este->dir*(este->dir * 25 + delta.x * lon) > getPosition().x - este->getPosition().x && getPosition().x - este->getPosition().x> -este->dir*(este->dir * 25 + delta.x * lon)) {
			k = 2;
		}
		else if (este->dir*(este->dir * 100 - delta.x * lon) > getPosition().x - este->getPosition().x) {
			if (150 + delta.y*lon > getPosition().y - este->getPosition().y&& -delta.y * lon < getPosition().y - este->getPosition().y&&este->rebote) {
				dir({ sf::Mouse::getPosition(*(este->window)).x - getPosition().x,sf::Mouse::getPosition(*(este->window)).y - getPosition().y });
				k = 3;
			}
		}
		break;
	//si no la regresa
	case 2:
		if (150 + delta.y*lon > getPosition().y - este->getPosition().y&& -delta.y * lon < getPosition().y-50 - este->getPosition().y) {
			este->atakado();
			k = 0;
		}
		else if (este->dir*(-este->dir * 25 + delta.x * lon) > getPosition().x - este->getPosition().x) {
			k = 0;
		}
		break;
	//si la regresa
	case 3:
		for (enemy* a : punteros::po) {
			if (150 + delta.y*lon > getPosition().y - a->getPosition().y&& -delta.y * lon < getPosition().y - a->getPosition().y&&a->dir*(a->dir * 25 + delta.x * lon) > getPosition().x - a->getPosition().x&&a->dir*(-a->dir * 25 + delta.x * lon) < getPosition().x - a->getPosition().x) {
				a->atakado();
				k = 0;
			}
		}
		break;
	}
}

shoot::~shoot()
{
}
