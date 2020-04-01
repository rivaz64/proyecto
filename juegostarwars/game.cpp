#include "game.h"
#include"algoritmo.h"
#include"suelo.h"
#include <stdlib.h>     
#include <time.h> 
#include"input.h"
//acomoda todo lo del nivel
void game::setear(int a)
{
	if (a == 4) {
		return;
	}
	punteros::deletear();
	level = new nivel();
	player.setPosition(50, 350);
	player.vida = 200;
	player.next = false;
	player.vivo = true;
	player.perdio = false;
	player.setSize({ 100,150 });
	level->player = &player;
	level->window = &window;
	level->fondo = &fondo;
	level->piso = &piso;
	if (charge) {
		level->guardado();
	}
	else {
		level->init(a);
	}
	
}

game::game():window(sf::VideoMode(1300,700),"star wars"),player("luke.png","luke.txt"),/*troop("trooper.png", "trooper.txt"),*/fondo("fondo.png"),piso("platform.png"),ini("menu.png"),final("Tauntaun.png")
{
	final.setSize({ 100,100 });
	final.setOrigin({ 50,0 });
	player.finish = &final;
	player.objects.push_back(&final);
	nuevo.kedice = "nueva partida";
	nuevo.posi = { 350,500 };
	nuevo.setSize({ 50,50 });
	carga.kedice = "cargar partida";
	carga.posi = { 350,550 };
	carga.setSize({ 50,50 });
	ganaste.kedice = "ganaste";
	ganaste.posi = { 175,350 };
	ganaste.setSize({ 75,75 });
	player.vivo = false;
	player.perdio = true;
	srand(std::time(NULL));
	player.window = &window;
	ini.setSize({ 700,700 });
	ini.setPosition({ 300,000 });
	final.setPosition({ 250,200 });
	player.setTextureRect(sf::IntRect(150, 440, 50, 60));
	fondo.setSize({ 700, 700 });
	piso.setPosition({ 100,100 });
	piso.setSize({ 100, 100 });
	piso.setTextureRect({ 0,432,48,48 });
	carga.setFillColor(sf::Color(127, 127, 127));
	nuevo.setFillColor(sf::Color(255, 255, 255));
	charge = false;
	//nnivel = 3;
	//setear(1);
	//troop.setPosition({ 500,300 });
}
//el gameloop
void game::run()
{
	sf::Clock clock;
	
	while (window.isOpen()) {
		//se actualiza el delta time
		
		time.delta = clock.restart().asSeconds();
		events();
		if (player.perdio||nnivel == 4) {
			update();
			render();
		}
		else {
			if (player.next) {
				charge = false;
				nnivel += 1;
				if (nnivel == 4)
					continue;
				setear(nnivel);
			}
			if (input::R || player.restart) {
				player.restart = false;
				setear(nnivel);
			}
			level->update();
			//level->edit();
			level->render();
		}
		
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
//los imputs se actualizan
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
	case sf::Keyboard::R:
		input::R = isPressed;
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
//el update fuera de los niveles
void game::update()
{
	if (input::enter) {
		setear(nnivel);
	}
	if (input::Up) {
		carga.setFillColor(sf::Color(127, 127, 127));
		nuevo.setFillColor(sf::Color(255, 255, 255));
		charge = false;
	}
	if (input::Down) {
		nuevo.setFillColor(sf::Color(127, 127, 127));
		carga.setFillColor(sf::Color(255, 255, 255));
		charge = true;
	}
}
//el render cuando esta afuera de un nivel
void game::render()
{
	window.clear();
	if (nnivel == 4) {
		ganaste.draw(window);
	}
	else {
		window.draw(ini);
		nuevo.draw(window);
		carga.draw(window);
	}
	window.display();
}
game::~game()
{
	delete level;
	
}
