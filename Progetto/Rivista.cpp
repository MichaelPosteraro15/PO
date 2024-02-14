#include "Rivista.h"

Rivista::Rivista(): MezzoDivulgativo(), editore(""), volume(0){}

Rivista::Rivista(string no, string ac, const Data& da, string ed, unsigned vo) : MezzoDivulgativo(no, ac, da){
	editore = ed;
	volume = vo;
}

string Rivista::get_editore() const{ return editore; }

unsigned Rivista::get_volume() const{ return volume; }

ostream& Rivista::stampa(ostream& o) const{
	MezzoDivulgativo::stampa(o) << "Editore: " << editore << endl;
	o << "Volume:" << volume << endl;

	return o;
}

ostream& operator<<(ostream& o, const Rivista& r){ return r.stampa(o);}