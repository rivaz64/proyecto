#include "game.h"
#include"algoritmo.h"
#include"suelo.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include"input.h"
void game::setear(int a)
{
	level = new nivel();
	player.vida = 100;
	player.next = false;
	player.vivo = true;
	player.perdio = false;
	level->player = &player;
	level->window = &window;
	level->fondo = &fondo;
	//level->fondo0 = &fondo0;
	level->piso = &piso;
	level->init(a);
	
}
game::game():window(sf::VideoMode(1300,700),"star wars"),player("luke.png","luke.txt")/*,troop("trooper.png", "trooper.txt")*/,fondo("fondo.png"),piso("platform.png"),ini("menu.png"),final("Tauntaun.png")
{
	
	final.setSize({ 100,100 });
	final.setOrigin({ 50,0 });
	player.finish = &final;
	player.objects.push_back(&final);
	//troop.player = &player;
	bla.kedice = "press enter";
	bla.posi = { 350,500 };
	bla.setSize({ 50,50 });
	//player.sets
	player.vivo = false;
	player.perdio = true;
	srand(std::time(NULL));
	player.window = &window;
	ini.setSize({ 700,700 });
	ini.setPosition({ 300,000 });
	player.setPosition(50, 300);
	final.setPosition(player.getPosition());
	player.setTextureRect(sf::IntRect(150, 440, 50, 60));
	fondo.setSize({ 700, 700 });
	//fondo0.setSize({ 800, 800 });
	//fondo0.setPosition({ 800,0 });
	//fondo.objects.push_back(&fondo0);
	piso.setPosition({ 100,100 });
	piso.setSize({ 100, 100 });
	piso.setTextureRect({ 0,432,48,48 });
	setear(1);
	//troop.setPosition({ 500,300 });
}
//el update del modo edit, que es para hacer los files
/*void game::edit()
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

}*/

void game::run()
{
	sf::Clock clock;
	
	while (window.isOpen()) {
		//se actualiza el delta time
		
		time.delta = clock.restart().asSeconds();
		events();
		/*if (player.perdio) {
			update();
			render();
		}
		else {*/
		if (player.next) {
			nnivel += 1;
			setear(nnivel);
			}
			level->update();
			//level->edit();
			level->render();
		//}
		
		//edit();
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
		input::Left = isPressed;
		break;
	case sf::Keyboard::Right:
		input::Right = isPressed;
		break;
	case sf::Keyboard::Up:
		input::Up = isPressed;
		break;
	case sf::Keyboard::Down:
		input::Down = isPressed;
		break;
	case sf::Keyboard::LShift:
		input::shift = isPressed;
		break;
	case sf::Keyboard::Space:
		if (isPressed) {
			player.salta();
		}
		input::space = isPressed;
		break;
	case sf::Keyboard::Enter:
		input::enter = isPressed;
		break;
	case sf::Keyboard::Z:
		input::cntrlz= isPressed;
		break;
	case sf::Keyboard::A:
		input::A = isPressed;
		break;
	case sf::Keyboard::Num1:
		if (isPressed) {
			level->cual = &piso;
		}
		break;
	case sf::Keyboard::Num2:
		if (isPressed) {
			//level->cual = &troop;
		}
		break;
	default:
		break;
	}
}

void game::menu()
{

}

void game::update()
{
	if (input::enter) {
		setear(1);
	}
}

/*void game::update()
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
	}
	if (A) {
		player.atack = true;
	}
	for (int a = 0; a < player.objects.size(); a++) {
		player.objects[a]->update();
	}
	/*for (objeto* a : player.objects) {
		a->update();
	}
}*/

/*void game::render()
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
}*/

void game::render()
{
	window.clear();
	window.draw(ini);
	bla.draw(window);
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
	delete level;
	
}
