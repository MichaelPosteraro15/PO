#include "Conferenza.h"

Conferenza::Conferenza():MezzoDivulgativo(), luogo(""), numero_partecipanti(0){}

Conferenza::Conferenza(string no, string ac, const Data& da, string lu, const list<string>& og, unsigned np):
MezzoDivulgativo(no, ac, da){
	luogo = lu;
	organizzatori = og;
	numero_partecipanti = np;
}

string Conferenza::get_luogo() const{ return luogo; }

const list<string>& Conferenza::get_organizzatori() const{ return organizzatori; }

unsigned Conferenza::get_numero_partecipanti() const{ return numero_partecipanti; }

ostream& Conferenza::stampa(ostream& o) const{
	MezzoDivulgativo::stampa(o) << "Luogo: " << luogo << endl;
	o << "Organizzatori: " << endl;

	for(auto organizzatore: organizzatori){
		o << organizzatore << endl;
	}

	o << "Numero Partecipanti: " << numero_partecipanti << endl;

	return o;
}

ostream& operator<<(ostream& o, const Conferenza& c){ return c.stampa(o); }