#include"algoritmo.h"
bool operator<(sf::Vector2f a, sf::Vector2f e)
{
	return a.y<e.y;
}
bool operator>(sf::Vector2f a, sf::Vector2f e)
{
	return a.x > e.x;
}
//sortea vector2 en x
void sortear(vector < sf::Vector2f > &a) {
	bool x = true;
	sf::Vector2f h;
	while (x) {
		x = false;
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] > a[i + 1]) {
				x = true;
				h = a[i];
				a[i] = a[i + 1];
				a[i + 1] = h;
			}
		}
	}
}
//sortea vector2 en y
void sorteary(vector < sf::Vector2f > &a) {
	bool x = true;
	sf::Vector2f h;
	while (x) {
		x = false;
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] < a[i + 1]) {
				x = true;
				h = a[i];
				a[i] = a[i + 1];
				a[i + 1] = h;
			}
		}
	}
}
void sorteari(vector < sf::Vector2f > &a) {
	bool x = true;
	sf::Vector2f h;
	while (x) {
		x = false;
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i+1] < a[i ]) {
				x = true;
				h = a[i];
				a[i] = a[i + 1];
				a[i + 1] = h;
			}
		}
	}
}
