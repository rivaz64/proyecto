#include "suelo.h"
//inizializa un suelo sin fondo
suelo::suelo() {

}
//inicialisa un suelo con fondo
suelo::suelo(int iz,int de)
{
	izquierda = iz;
	derecha = de;
	d = new suelo();
	d->solid = false;
	d->i = this;
	d->izquierda = derecha;
	i = new suelo();
	i->solid = false;
	i->d = this;
	i->derecha = izquierda;
	a = new suelo();
	a->solid = false;
	a->v = this;
	a->derecha = derecha;
	a->izquierda = izquierda;
	v = new suelo();
	v->solid = false;
	v->a = this;
	v->derecha = derecha;
	v->izquierda = izquierda;
	/*p->d = new suelo();
	p->d->solid = false;
	p->d->i = p;
	p->i = new suelo();
	p->i->solid = false;
	p->i->d = p;
	p->a = new suelo();
	p->a->solid = false;
	p->a->v = p;
	p->v = new suelo();
	p->v->solid = false;
	p->v->a = p;*/
}
//une un suelo con otro que esta arriva a la izquierda
void suelo::arribaizquierda(suelo *otro)
{
	/*if (a->d)
	otro->d->d= a->d;*/
	a = otro->d;
	a->v = this;
	otro->v->d = this;
	i = otro->v;
	arriva = otro->abajo;
	a->abajo = arriva;
	i->arriva = arriva;
	/*otro->v = i;
	i->i = otro->i->v;
	i->d = v;
	arriva = otro->abajo;
	a->abajo = arriva;
	i->arriva = arriva;
	a->i = otro;*/
}
//une un suelo con otro que esta arriva a la derecha
void suelo::arribaderecha(suelo *otro)
{
	/*if (a->i) {
		otro->i->i = a->i;
		otro->i->i->d = a;
	}*/
	otro->i = a;
	a->d = otro;
	otro->v->i = this;
	d = otro->v;
	arriva = otro->abajo;
	a->abajo = arriva;
	d->arriva = arriva;
	/*
	a = otro->i;
	a->v = this;
	otro->v->i = this;
	//otro->i->v = this;
	otro->v = d;
	//d->i = v;
	arriva = otro->abajo;
	a->abajo = arriva;
	d->arriva = arriva;
	otro->v->a = otro;
	//d = otro->v;*/
}
//une un suelo con otro que esta abajo a la izquierda
void suelo::abajoizquierda(suelo *otro)
{
	otro->arribaderecha(this);
}
//une un suelo con otro que esta abajo a la derecha
void suelo::abajoderecha(suelo *otro)
{
	otro->arribaizquierda(this);
}

suelo::~suelo()
{
}
