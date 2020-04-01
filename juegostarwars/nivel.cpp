#include "nivel.h"
#include"input.h"

istream &operator>>(std::istream &x, vector<sf::Vector2f>&v) {
	float a, e;
	x >> a >> e;
	while (!x.eof()) {
		v.push_back({ a,e });
		x >> a >> e;
	}
	return x;
}
ostream &operator<<(std::ostream &x, vector<sf::Vector2f>&v) {
	for (sf::Vector2f a : v) {
		x << a.x << " " << a.y << endl;
	}
	return x;
}
nivel::nivel()
{
	
}
//acomoda el piso
void nivel::acomodapiso()
{
	vector<float> li = { -100,1400 };
	vector<suelo*> lis = {};
	suelo* tem;
	sortear(map);
	sorteary(map);
	//cout << map.size()<<endl;
	//se ponen las conexiones del file
	for (int a = 0; a < map.size(); a++) {
		//cout << map[a].y << endl;
		p = new suelo(map[a].x, map[a].x + 100);
		pointers.push(p);
		p->abajo = map[a].y;
		p->a = new suelo();
		if (a == 0) {
			player->piso = p;
			li.insert(li.begin()+1, map[a].x);
			lis.push_back(p);
			an = p;
			continue;
		}
		if (!(an&&an->abajo == p->abajo)) {
			for (int a = 0; a < lis.size(); a++) {
				lis[a]->a = new suelo();
				lis[a]->a->abajo = p->abajo;
				lis[a]->a->derecha = lis[a]->derecha;
				lis[a]->a->izquierda = lis[a]->izquierda;
				lis[a]->a->v = lis[a];
				lis[a]->arriva = p->abajo;
				lis[a] = lis[a]->a;
				if (a != 0) {
					lis[a]->i = lis[a - 1];
					lis[a - 1]->d = lis[a];
				}
				
			}
		}
		for (int e = 0; e < lis.size()+1; e++) {
			if (li[e] < p->izquierda&&p->izquierda < li[e + 1]) {
				if (e != 0) {
					if (lis[e - 1]->derecha > p->izquierda) {
						p->i = lis[e - 1];
						lis[e - 1]->d = p;
					}
					else {
						if (lis[e - 1]->d) {
							p->i = lis[e - 1]->d;
							lis[e - 1]->d->d = p;
						}
						
					}
					if (!(lis[e - 1]->derecha > p->izquierda)) {
						tem = p->i->i;
						while (tem &&tem->derecha > p->i->izquierda) {
							tem->derecha = p->i->izquierda;
							tem = tem->i;
						}
					}
				}
				
				tem = p->i;
				while (tem &&tem->derecha > p->izquierda) {
					tem->derecha = p->izquierda;
					tem = tem->i;
				}
				if (p->derecha>li[e+1]||e==lis.size()) {
					if (e != lis.size()) {
						p->d = lis[e];
						lis[e]->i = p;
						tem = p->d;
						while (tem&&tem->izquierda < p->derecha) {
							tem->izquierda = p->derecha;
							tem = tem->d;
						}
					}
					li.insert(li.begin() + e+1, p->izquierda);
					lis.insert(lis.begin() + e, p);
					if (!(lis[e - 1]->derecha > p->izquierda)) {
						li.insert(li.begin() + e + 1, p->i->izquierda);
						lis.insert(lis.begin() + e, p->i);
					}
				}
				else {
					p->d->v=p->i->v;
					if (e != lis.size()) {
						p->d->derecha = lis[e]->izquierda;
					}
					li.insert(li.begin() + e+1, p->izquierda);
					lis.insert(lis.begin() + e, p);
					li.insert(li.begin() + e+2, p->derecha);
					lis.insert(lis.begin() + e+1, p->d);

				}
				break;
			}
		}
		an = p;

	}
	sorteari(map);
}
//guarda la partida
void nivel::guardado()
{
	ifstream file,f;
	float a, e;
	int i;
	file.open("guardado.txt", ifstream::in);
	file >> num;
	f.open("mapa" + to_string(num) + ".txt", ifstream::in);
	f >> map;
	//loadata("mapa" + to_string(num) + ".txt", map);
	acomodapiso();
	file >> player->vida >> a >> e;
	player->setPosition({ a,e });
	while (!file.eof()) {
		t = new enemy("trooper.png", "trooper.txt");
		file >> t->vida;
		file >> a >> e;
		enemys.push_back({ a,e });
		t->setPosition({ a,e });
		pointers.push(t);
		t->player = player;
	}
	file.close();
}
//pone todo lo del nivel
void nivel::init(int a)
{
	num = a;
	ifstream f;
	f.open("mapa" + to_string(num) + ".txt", ifstream::in);
	f >> map;
	f.close();
	f.open("enemys" + to_string(num) + ".txt", ifstream::in);
	f >> enemys;
	f.close();
	acomodapiso();
	//acomoda a los enemigos
	for (int a = 0; a < enemys.size(); a++) {
		t = new enemy("trooper.png", "trooper.txt");
		t->setPosition(enemys[a]);
		pointers.push(t);
		t->player = player;
	}
}

//el update dentro del nivel
void nivel::update()
{
	if (input::enter) {
		player->salir();
	}
	//mueve al jugador
	if (input::Left) {
		player->l = true;
	}
	if (input::Right) {
		player->r = true;
	}
	if (input::shift) {
		player->run = true;
	}
	//ataka
	if (input::A) {
		player->atack = true;
	}
	for (int a = 0; a < player->objects.size(); a++) {
		player->objects[a]->update();
	}
}

void nivel::edit()
{
	if (input::Left) {
		cual->move({ -time.delta*60,0 });
	}
	if (input::Right) {
		cual->move({ time.delta*60,0 });
	}
	if (input::Up) {
		cual->move({ 0,-time.delta*60 });
	}
	if (input::Down) {
		cual->move({ 0,time.delta*60 });
	}
	//para poner un piso
	if (input::enter) {
		if (!input::enterp) {
			if (cual == piso) {
				map.push_back(cual->getPosition());
			}
			else {
				enemys.push_back(cual->getPosition());
			}
			
		}
		input::enterp = true;
	}
	else {
		input::enterp = false;
	}
	//para quitar el ultimo piso
	if (input::cntrlz) {
		if (!input::cntrlzp && map.size()>0)
		{
			if (cual == piso) {
				map.pop_back();
			}
			else {
				enemys.pop_back();
			}
			
		}
		input::cntrlzp = true;
	}
	else {
		input::cntrlzp = false;
	}
	posipiso = piso->getPosition();
}

void nivel::render()
{
	window->clear();
	fondo->setPosition({ 0,0 });
	window->draw(*fondo);
	fondo->setPosition({ 700,0 });
	window->draw(*fondo);
	for (sf::Vector2f a : map) {
		piso->setPosition(a);
		window->draw(*piso);
	}
	piso->setPosition(posipiso);
	window->draw(*piso);
	for (objeto* a : player->objects) {
		window->draw(*a);
	}
	window->display();
}




nivel::~nivel()
{
	ofstream f;
	f.open("mapa" + to_string(num) + ".txt", ofstream::out);
	f << map;
	f.close();
	f.open("enemys" + to_string(num) + ".txt", ofstream::out);
	f << enemys;
	f.close();
	ofstream file;
	file.open("guardado.txt", ofstream::out);
	file << num << '\n';
	file << player->vida<<" "<< player->getPosition().x << " "<< player->getPosition().y<<'\n';
	for (enemy* a : punteros::po) {
		file << a->vida << " " << a->getPosition().x << " " << a->getPosition().y << '\n';
	}
	file.close();
}
