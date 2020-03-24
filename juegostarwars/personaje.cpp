#include "personaje.h"



#include"personaje.h"
//inizialisa a un personaje
personaje::personaje(string a,string f):objeto(a)
{

	objects.push_back(this);
	setSize({ 100, 150 });
	setOrigin(20, 0);
	ifstream file;
	file.open(f, ifstream::in);
	normal = inrec(file);
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

