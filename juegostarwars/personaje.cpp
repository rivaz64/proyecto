#include "personaje.h"



#include"personaje.h"
//inizialisa a un personaje
std::istream & operator>>(std::istream &x, vector<sf::IntRect>&v)
{
	int a, b, c, d;
	x >> a;
	x >> b;
	x >> c;
	x >> d;
	v.push_back(sf::IntRect(a, b, c, d));
	while (x.peek() != '\n') {
		x >> a;
		x >> b;
		x >> c;
		x >> d;
		v.push_back(sf::IntRect(a, b, c, d));
	}
	return x;
}

void personaje::update()
{
	
	if (vida < 0) {
		vivo = false;
		vida = 10000;
		t = 0;
		setTextureRect(muerto.esta());
	}
	ct += time.delta;
	if (ct > .5f) {
		setFillColor(sf::Color(255,255,255));
	}
}
void personaje::atakado()
{
	vida -= std::rand() % 10 + 20;
	setFillColor(sf::Color::Red);
	ct = 0;
}
void personaje::dying()
{
	if (t > 1) {
		if (muerto.cual ==1) {
			
		}
		else {
			muerto.next(t);
			setTextureRect(muerto.esta());
			//t = 0;
			if (muerto.cual == 1) {
				setSize({ 150,50 });
				move({ 0,95 });
			}
			

		}
	}
}
personaje::personaje(string a,string f):objeto(a)
{

	objects.push_back(this);
	setSize({ 100, 150 });
	setOrigin(20, 0);
	ifstream file;
	file.open(f, ifstream::in);
	normal = inrec(file);
	file >> muerto.coords;
	file.close();
}
//saca las animaciones de los archivos
sf::IntRect personaje::inrec(ifstream &x)
{
	int a, b, c, d;
	x >> a;
	x >> b;
	x >> c;
	x >> d;
	return sf::IntRect(a,b,c,d);
}

//saca una animacion entera
void personaje::llenar(ifstream & i,vector<sf::IntRect>&v)
{
	v.push_back(inrec(i));
	while (i.peek() != '\n') {
		v.push_back(inrec(i));
	}
}


personaje::~personaje()
{
}
sf::IntRect inrec(ifstream &x)
{
	int a, b, c, d;
	x >> a;
	x >> b;
	x >> c;
	x >> d;
	return sf::IntRect(a, b, c, d);
}
/*std::istream & operator>>(std::istream &x, vector<sf::IntRect>&v)
{
	int a, b, c, d;
	x >> a;
	x >> b;
	x >> c;
	x >> d;
	v.push_back(sf::IntRect(a, b, c, d));
	while (x.peek() != '\n') {
		x >> a;
		x >> b;
		x >> c;
		x >> d;
		v.push_back(sf::IntRect(a, b, c, d));
	}
	return x;
}*/

