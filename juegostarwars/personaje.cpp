#include "personaje.h"



personaje::personaje(string a): objeto(a)
{
	setSize({ 100, 150 });
	setOrigin(20, 0);
	//setea las animaciones
	caminar.coords = { { 0,500, 45, 60 },{ 50,500, 45, 60},{ 100,500, 45, 60 },{ 150,500, 45, 60 } };
	correr.coords = { {192, 500, 65, 60 },{257, 500, 65, 60 },{322, 500, 65, 60 },{387, 500, 65, 60 },{370, 561, 65, 60 } };
	saltar.coords = { {10, 940, 45, 60 },{60, 940, 45, 60},{110, 940, 45, 60} };
	saltar.cadacuanto = .15f;
}

void personaje::update()
{
	//cout << getPosition().x <<" "<< piso->derecha<<endl;
	//si cambia al piso de la derecha
	if ((getPosition().x > piso->derecha)||(piso->d&&piso->d->solid&&getPosition().x>piso->d->izquierda)) {
		piso = piso->d;
	}
	//si cambia al piso de la izquierda
	if ((getPosition().x < piso->izquierda)|| (piso->i&&piso->i->solid&&getPosition().x < piso->i->derecha)) {
		piso = piso->i;
	}
	//cout << getPosition().y << " " << piso->arriva << endl;
	//cout << (piso->a) << endl;
	//si cambia al piso de arriba
	if (getPosition().y < piso->arriva - getSize().y||(getPosition().y-10 < piso->arriva - getSize().y&&piso->a&&piso->a->solid)) {
		piso = piso->a;
	}
	setScale({ getScale().x/abs(getScale().x),getScale().y });
	//ya += deltaim;
	setTextureRect(sf::IntRect(150, 440, 50, 60));
	//lo mueve a la derecha
	if (r) {
		move({ time.delta*vel,0 });
		setScale({ 1, 1 });
		render();
	}
	//lo mueve a la izquierda
	else if (l) {
		move({ -time.delta*vel,0 });
		setScale({ -1, 1 });
		render();
	}
	else {
		textnum = 0;
	}
	//si esta en el aire
	if (getPosition().y != piso->abajo - getSize().y || !piso->solid) {
		if (!jump) {
			vely = 0;
		}
		jump = true;
	}
	//si esta brincando
	if (jump) {
		render();
		move({ 0,vely });
		vely += time.delta*2;
		if (getPosition().y > piso->abajo-getSize().y) {
			if (piso->solid) {
				setPosition(getPosition().x, piso->abajo - getSize().y);
				jump = false;
				saltar.cual = 0;
			}
			else {
				piso = piso->v;
			}
		}
	}
	//cout << vely << endl;
	l = false;
	r = false;
	run = false;
	semueve = false;
}

void personaje::render()
{
	//next += deltaim;
	//animacion de brinco
	if (jump) {
		setTextureRect(sf::IntRect(saltar.esta()));
		if (saltar.cual != 2) {
			saltar.next();
		}
	}
	//animacion de correr
	else if (run) {
		move({ time.delta*vel*(getScale().x / abs(getScale().x)),0 });
		setScale({ 65.f / 45.f*getScale().x,1 });
		setTextureRect(sf::IntRect(correr.esta()));
		correr.next();

	}
	//animacion de caminar
	else {
		setTextureRect(sf::IntRect(caminar.esta()));
		caminar.next();
	}
	
	
	
}

void personaje::salta()
{
	//cuando preciona el boton para saltar
	if (getPosition().y == piso->abajo-getSize().y) {
		vely = -1.1f;
	}
	jump = true;

}


personaje::~personaje()
{
}
