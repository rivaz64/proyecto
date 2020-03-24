#include "shoot.h"
#include<algorithm>
#include<math.h>
#define PI 3.14159265
shoot::shoot(sf::Vector2f p, sf::Vector2f d):objeto("disparo.png")//,delta(d)
{
	dir(d);
	setTextureRect(sf::IntRect(425, 175, 50, 20));
	objects.push_back(this);
	setPosition(p);
	setSize({ 150, 30 });
	setOrigin(51, 19);
	//rotate(1);
	//setScale(-1, 1);
}

void shoot::update()
{
	//mueve la bala
	move(time.delta*500*delta.x, time.delta  *500* delta.y);
	t+= time.delta;
	//cout << getSize().x;
	//la borra
	if (t > 3) {
		t = 0;
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


shoot::~shoot()
{
}
