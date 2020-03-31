#include "jugador.h"
#include "shoot.h"
/*#include"caminar.h"
#include "correr.h"
#include"saltar.h"
*/
vector<shoot*> jugador::balas = {};

void jugador::salir()
{
	//cout << abs(getPosition().x - finish->getPosition().x) << " " << abs(getPosition().y - finish->getPosition().y) << endl;
	if (abs(getPosition().x - finish->getPosition().x) < 50 && abs(getPosition().y - finish->getPosition().y) < 70) {
		next = true;
	}
}

void jugador::morir()
{
	perdio = true;
}

jugador::jugador(string a,string f) : personaje(a,f)//,actual(new accion(this))
{

	//setea las animaciones
	ifstream file;
	file.open(f, ifstream::in);
	std::string r;
	getline(file, r);
	getline(file, r);
	file >> caminar.coords;
	file >> correr.coords;
	file >> saltar.coords;
	file >> atacar.coords;
	/*caminar.coords = { { 0,500, 45, 60 },{ 50,500, 45, 60},{ 100,500, 45, 60 },{ 150,500, 45, 60 } };
	correr.coords = { {192, 500, 65, 60 },{257, 500, 65, 60 },{322, 500, 65, 60 },{387, 500, 65, 60 },{370, 561, 65, 60 } };
	saltar.coords = { {10, 940, 45, 60 },{60, 940, 45, 60},{110, 940, 45, 60} };
	atacar.coords = { { 10, 567, 60, 60 },{ 75, 567, 60, 60 },{ 140, 567, 60, 60 },{ 220, 567, 70, 60 }, { 0, 650, 60, 60 },{0,0,0,0} };
	*/saltar.cadacuanto = .15f;
	atacar.cadacuanto = .075f;
	vida = 10000;
}

void jugador::update()
{
	
	t += time.delta;
	personaje::update();
	/*actual->input();
	actual->update();
	actual->render();*/
	if (true) {
		setScale({ getScale().x / abs(getScale().x),getScale().y });
		//ya += deltaim;
		//setTextureRect(sf::IntRect(150, 440, 50, 60));
		setTextureRect(normal);
		setOrigin({ 20,0 });
		//cout << getPosition().x <<" "<< piso->derecha<<endl;
		//si cambia al piso de la derecha
		
		if ((getPosition().x > piso->derecha) || (piso->d&&piso->d->solid&&getPosition().x > piso->d->izquierda)) {
			piso = piso->d;
		}
		//si cambia al piso de la izquierda
		if ((getPosition().x < piso->izquierda) || (piso->i&&piso->i->solid&&getPosition().x < piso->i->derecha)) {
			piso = piso->i;
		}
		//cout << getPosition().y << " " << piso->arriva << endl;
		//cout << (piso->a) << endl;
		//si cambia al piso de arrib1
		if (getPosition().y < piso->arriva - getSize().y || (getPosition().y - 10 < piso->arriva - getSize().y&&piso->a&&piso->a->solid)) {
			piso = piso->a;
		}
		/*if (getPosition().y < piso->abajo - getSize().y && vely <= 1) {
			cout << 0;
			piso = piso->v;
		}*/
		//lo mueve a la derecha
		if (atakando) {
			render();
		}
		if (r) {
			move({ time.delta*vel,0 });
			setScale({ 1, 1 });
			dir = 1;
			render();
		}
		//lo mueve a la izquierda
		else if (l) {
			move({ -time.delta*vel,0 });
			dir = -1;
			setScale({ -1, 1 });
			render();
		}
		else {
			textnum = 0;
			if (atack && !jump) {
				atakando = true;
			}
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
			if (fast) {
				move({ time.delta*vel*(getScale().x / abs(getScale().x)),0 });
			}
			vely += time.delta * 2.5f;
			if (getPosition().y > piso->abajo - getSize().y) {
				if (piso->solid) {
					setPosition(getPosition().x, piso->abajo - getSize().y);
					jump = false;
					doubejump = true;
					saltar.cual = 0;
				}
				else {
					piso = piso->v;
				}
			}
		}
		else {
			vely = 0;
		}
		//cout << vely << endl;
		l = false;
		r = false;
		run = false;
		semueve = false;
		atack = false;
		for (shoot* a : balas) {
			a->checka();
		}
	}
	else {
		personaje::dying();
	}
}

void jugador::render()
{
	//next += deltaim;
	//animacion de brinco
	if (atakando) {
		setTextureRect({ 180, 557, 100, 60 });
		setTextureRect({ 220, 557, 45, 60 });
		setTextureRect(sf::IntRect(atacar.esta()));
		atacar.next();
		setScale({ getScale().x / abs(getScale().x)*60 / 45.f,getScale().y });
		setOrigin({ 80,-25 });
		if (atacar.cual > 2) {
			rebote = true;
			//cheka({ 25,0 }, { 100,150 },1);
			setScale({ getScale().x / abs(getScale().x) * 70.f / 45.f,getScale().y });
			setOrigin({ 30,-25 });
		}
		if (atacar.cual == 5) {
			atakando = false;
			rebote = false;
			atacar.cual = 0;
		}
	}
	else if (jump) {
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
		fast = true;
	}
	//animacion de caminar
	else {
		setTextureRect(sf::IntRect(caminar.esta()));
		caminar.next();
		fast = false;
	}



}

void jugador::salta()
{
	//cuando preciona el boton para saltar
   	if (getPosition().y == piso->abajo - getSize().y) {
		vely = -1.5f;
	}
	else if (doubejump) {
		vely = -1.5f;
		saltar.cual = 0;
		doubejump = false;
	}
	jump = true;

}







jugador::~jugador()
{
}

