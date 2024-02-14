#include "Autore.h"

Autore::Autore(): identificativo(""), nome(""), cognome(""){}

Autore::Autore(string id, string no, string co){
	identificativo = id;
	nome = no;
	cognome = co;
}

Autore::Autore(string id, string no, string co, const list<string>& af){
	identificativo = id;
	nome = no;
	cognome = co;
    if(!af.empty())
        afferenze = af;
}

string Autore::get_identificativo() const{ return identificativo; }

string Autore::get_nome() const{ return nome; }

string Autore::get_cognome() const{ return cognome; }

const list<string>& Autore::get_afferenze() const{ return afferenze; }

bool Autore::operator==(const Autore& a) const{ 
	return identificativo == a.identificativo;
}

ostream& operator<<(ostream& o, const Autore& a){
	o << "Id: " << a.identificativo << endl;
	o << "Nome: " << a.nome << endl;
	o << "Cognome: " << a.cognome << endl;

    o << "Afferenze: " << endl;
	for(auto afferenza: a.afferenze){ o << afferenza << endl; }

    return o;
}