#include "punteros.h"

//para almazenar los punteros, para al final borrarlos
std::vector<enemy*> punteros::po = {};
std::vector<suelo*> punteros::ps = {};
punteros::punteros()
{
}

void punteros::push(enemy * a)
{
	po.push_back(a);
}
void punteros::push(suelo * a)
{
	ps.push_back(a);
}


punteros::~punteros()
{
	for (enemy* a : po) {
		delete a;
	}
	for (suelo* a : ps) {
		delete a;
	}
}
