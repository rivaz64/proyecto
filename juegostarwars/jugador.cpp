#include "jugador.h"
#include "shoot.h"
vector<shoot*> jugador::balas = {};
//cuando sale del nivel
void jugador::salir()
{
	if (abs(getPosition().x - finish->getPosition().x) < 50 && abs(getPosition().y - finish->getPosition().y) < 70) {
		next = true;
	}
}
//cuando muere
void jugador::morir()
{
	perdio = true;
}

jugador::jugador(string a,string f) : personaje(a,f)
{

	//setea las animaciones
	restart = false;
	ifstream file;
	file.open(f, ifstream::in);
	std::string r;
	getline(file, r);
	getline(file, r);
	file >> caminar.coords;
	file >> correr.coords;
	file >> saltar.coords;
	file >> atacar.coords;
	saltar.cadacuanto = .15f;
	atacar.cadacuanto = .075f;
	
}

void jugador::update()
{
	//si se cae
	if (getPosition().y > 800) {
		restart = true;
	}
	t += time.delta;
	personaje::update();
	if (vivo) {
		setScale({ getScale().x / abs(getScale().x),getScale().y });
		setTextureRect(normal);
		setOrigin({ 20,0 });
		//si cambia al piso de la derecha
		while (piso != nullptr&&(getPosition().x > piso->derecha) || (piso->d&&piso->d->solid&&getPosition().x > piso->d->izquierda)) {
			if (!(piso->d))
				break;
			piso = piso->d;
		}
		//si cambia al piso de la izquierda
		while ((getPosition().x < piso->izquierda) || (piso->i&&piso->i->solid&&getPosition().x < piso->i->derecha)) {
			if (!(piso->i))
				break;
			piso = piso->i;
		}
		//si cambia al piso de arrib1
		if (piso&&getPosition().y < piso->arriva - getSize().y || (getPosition().y - 10 < piso->arriva - getSize().y&&piso->a&&piso->a->solid)) {
			if(piso->a)
			piso = piso->a;
		}
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
			vely += time.delta * 2.7f;
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
		vely = -1.9f;
	}
	else if (doubejump) {
		vely = -1.9f;
		saltar.cual = 0;
		doubejump = false;
	}
	jump = true;

}







jugador::~jugador()
{
}

