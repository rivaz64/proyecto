#include "punteros.h"

//para almazenar los punteros, para al final borrarlos
std::vector<objeto*> punteros::po = {};
std::vector<suelo*> punteros::ps = {};
punteros::punteros()
{
}

void punteros::push(objeto * a)
{
	po.push_back(a);
}
void punteros::push(suelo * a)
{
	ps.push_back(a);
}


punteros::~punteros()
{
	for (objeto* a : po) {
		delete a;
	}
	for (suelo* a : ps) {
		delete a;
	}
}
