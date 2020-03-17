#pragma once
#include<algorithm>
#include"SFML/Graphics.hpp"
#include<vector>
#include<iostream>
using namespace std;
bool operator<(sf::Vector2f a, sf::Vector2f e); 
bool operator>(sf::Vector2f a, sf::Vector2f e);
void sortear(vector < sf::Vector2f >&);
void sorteary(vector < sf::Vector2f >&);