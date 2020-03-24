#include "game.h"
#include"algoritmo.h"
#include"suelo.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
game::game():window(sf::VideoMode(1300,700),"star wars"),player("luke.png","luke.txt"),/*troop("trooper.png", "trooper.txt"),*/fondo("fondo.png"),fondo0("fondo.png"),piso("platform.png")
{
	//troop.player = &player;
	srand(std::time(NULL));
	player.window = &window;
	loadata("mapa.txt", map);
	loadata("enemys.txt",enemys);
	//se acomodan de izquierda a derecha
	sortear(map);
	//cout << map.size()<<endl;
	//se ponen las conexiones del file
	for (int a = 0; a < map.size(); a++) {
		cout << map[a].y << endl;
		p = new suelo(map[a].x, map[a].x+100);
		pointers.push(p);
		p->abajo = map[a].y;
		if (a == 0) {
			player.piso = p;
		}
		else {
			//cout << an->abajo << " " << p->abajo << endl;
			if (an->abajo < p->abajo){
				p->arribaizquierda(an);
			}
			else {
				p->abajoizquierda(an);
			}
		}
		an = p;
		/*
		if (a != 0) {
			p->a->i=an->d;
			p->i->a = an->v;
		}
		an = p;*/
		
	}
	for (int a = 0; a < enemys.size(); a++) {
		t = new enemy("trooper.png", "trooper.txt");
		t->setPosition(enemys[a]);
		pointers.push(t);
		t->player = &player;
	}
	//player.piso.abajo = map[0].y;
	
	/*file.open("enemys,txt", ifstream::in);

	file.close();*/
	player.setPosition(50, 300);
	player.setTextureRect(sf::IntRect(150, 440, 50, 60));
	fondo.setSize({ 800, 800 });
	fondo0.setSize({ 800, 800 });
	fondo0.setPosition({ 800,0 });
	fondo.objects.push_back(&fondo0);
	piso.setPosition({ 100,100 });
	piso.setSize({ 100, 100 });
	piso.setTextureRect({ 0,432,48,48 });
	sorteary(map);
	//troop.setPosition({ 500,300 });
}
//el update del modo edit, que es para hacer los files
void game::edit()
{
	cout << enemys.size() << endl;
	
	if (Left) {
		cual->move({ -time.delta*60,0 });
	}
	if (Right) {
		cual->move({ time.delta*60,0 });
	}
	if (Up) {
		cual->move({ 0,-time.delta*60 });
	}
	if (Down) {
		cual->move({ 0,time.delta*60 });
	}
	//para poner un piso
	if (enter) {
		if (!enterp) {
			if (cual == &piso) {
				map.push_back(cual->getPosition());
			}
			else {
				enemys.push_back(cual->getPosition());
			}
			
		}
		enterp = true;
	}
	else {
		enterp = false;
	}
	//para quitar el ultimo piso
	if (cntrlz) {
		if (!cntrlzp && map.size()>0) 
		{
			if (cual == &piso) {
				map.pop_back();
			}
			else {
				enemys.pop_back();
			}
			
		}
		cntrlzp = true;
	}
	else {
		cntrlzp = false;
	}
	posipiso = piso.getPosition();

}

void game::run()
{
	sf::Clock clock;
	
	while (window.isOpen()) {
		//se actualiza el delta time
		time.delta = clock.restart().asSeconds();
		events();
		update();
		//edit();
		render();
	}
}

void game::events()
{
	sf::Event eve;
	while (window.pollEvent(eve)) {
		switch (eve.type) {
		case sf::Event::KeyPressed:
			input(eve.key.code, true);
			break;
		case sf::Event::KeyReleased:
			input(eve.key.code, false);
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void game::input(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::Left:
		Left = isPressed;
		break;
	case sf::Keyboard::Right:
		Right = isPressed;
		break;
	case sf::Keyboard::Up:
		Up = isPressed;
		break;
	case sf::Keyboard::Down:
		Down = isPressed;
		break;
	case sf::Keyboard::LShift:
		shift = isPressed;
		break;
	case sf::Keyboard::Space:
		if (isPressed) {
			player.salta();
		}
		space = isPressed;
		break;
	case sf::Keyboard::Enter:
		enter = isPressed;
		break;
	case sf::Keyboard::Z:
		cntrlz= isPressed;
		break;
	case sf::Keyboard::A:
		A = isPressed;
		break;
	case sf::Keyboard::Num1:
		if (isPressed) {
			cual = &piso;
		}
		break;
	case sf::Keyboard::Num2:
		if (isPressed) {
			//cual = &troop;
		}
		break;
	default:
		break;
	}
}

void game::update()
{
	//mueve al jugador
	if (Left) {
		player.l = true;
	}
	if (Right) {
		player.r = true;
	}
	if (shift) {
		player.run = true;
	}
	/*if (space) {
		player.salta();
	}*/
	if (A) {
		player.atack = true;
	}
	for (int a = 0; a < player.objects.size(); a++) {
		player.objects[a]->update();
	}
	/*for (objeto* a : player.objects) {
		a->update();
	}*/
}

void game::render()
{
	window.clear();
	window.draw(fondo);
	for (sf::Vector2f a : map) {
		piso.setPosition(a);
		window.draw(piso);
	}	
	piso.setPosition(posipiso);
	window.draw(piso);
	for (objeto* a : player.objects) {
		window.draw(*a);
	}
	window.display();
}

void game::loadata(string f, vector<sf::Vector2f>& v)
{
	float a, e;
	file.open(f, fstream::in);
	file >> a >> e;
	while (!file.eof()) {
		v.push_back({ a,e });
		file >> a >> e;
	}
	file.close();
}

void game::savedata(string s, vector<sf::Vector2f>& v)
{
	file.open(s, fstream::out);
	for (sf::Vector2f a : v) {
		file << a.x << " " << a.y << endl;
	}
	file.close();
}


game::~game()
{
	savedata("mapa.txt", map);
	savedata("enemys.txt", enemys);
	
}
