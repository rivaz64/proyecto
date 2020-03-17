#include "game.h"
#include"algoritmo.h"
game::game():window(sf::VideoMode(600,600),"star wars"),player("luke.png"),fondo("fondo.png"),piso("platform.png")
{
	float a, e;
	//el archivo donde se guarda el mapa
	mapa.open("mapa.txt", fstream::in);
	mapa >> a >> e;
	while (!mapa.eof()) {
		map.push_back({ a,e });
		mapa >> a >> e;
	}
	//se acomodan de izquierda a derecha
	sortear(map);
	//cout << map.size()<<endl;
	//se ponen las conexiones del mapa
	for (int a = 0; a < map.size(); a++) {
		cout << map[a].y << endl;
		p = new suelo(map[a].x, map[a].x+100);
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
	//player.piso.abajo = map[0].y;
	mapa.close();
	player.setPosition(50, 300);
	player.setTextureRect(sf::IntRect(150, 440, 50, 60));
	fondo.setSize({ 600, 600 });
	piso.setPosition({ 100,100 });
	piso.setSize({ 100, 100 });
	piso.setTextureRect({ 0,432,48,48 });
	sorteary(map);
}
//el update del modo edit, que es para hacer los mapas
void game::edit()
{
	//cout << map.size() << endl;
	if (Left) {
		piso.move({ -time.delta*60,0 });
	}
	if (Right) {
		piso.move({ time.delta*60,0 });
	}
	if (Up) {
		piso.move({ 0,-time.delta*60 });
	}
	if (Down) {
		piso.move({ 0,time.delta*60 });
	}
	//para poner un piso
	if (enter) {
		if (!enterp) {
			map.push_back(piso.getPosition());
		}
		enterp = true;
	}
	else {
		enterp = false;
	}
	//para quitar el ultimo piso
	if (cntrlz) {
		if (!cntrlzp && map.size()>0) {
			map.pop_back();
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
		space = isPressed;
		break;
	case sf::Keyboard::Enter:
		enter = isPressed;
		break;
	case sf::Keyboard::Z:
		cntrlz= isPressed;
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
	if (space) {
		player.salta();
	}
	player.update();
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
	window.draw(player);
	window.display();
}


game::~game()
{
	mapa.open("mapa.txt", fstream::out);
	for (sf::Vector2f a: map) {
		mapa << a.x<<" "<<a.y<<endl;
	}
	mapa.close();
}
