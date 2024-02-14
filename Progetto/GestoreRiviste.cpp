#include "GestoreRiviste.h"

GestoreRiviste::GestoreRiviste() {}

GestoreRiviste::GestoreRiviste(const GestoreRiviste& g){
	for(auto rivista: g.riviste){
		Rivista* nuova_rivista = new Rivista(rivista->get_nome(), rivista->get_acronimo(), 
			                                 rivista->get_data(), rivista->get_editore(), rivista->get_volume());
		riviste.push_back(nuova_rivista);
	}
}

GestoreRiviste::~GestoreRiviste(){ elimina_riviste(); }

GestoreRiviste& GestoreRiviste::operator=(const GestoreRiviste& g){
	if(this == &g){
       elimina_riviste();

       for(auto rivista: g.riviste){
		   Rivista* nuova_rivista = new Rivista(rivista->get_nome(), rivista->get_acronimo(), 
			                                    rivista->get_data(), rivista->get_editore(), rivista->get_volume());
		   riviste.push_back(nuova_rivista);
	   }
	}
	return *this;
}

bool GestoreRiviste::esistenza_rivista(string no, string ac, const Data& da) const{
	MezzoDivulgativo nuovo(no, ac, da);

	for(auto rivista: riviste){
        if(nuovo == *rivista){ return true; }
	}
    return false;
}

Rivista* GestoreRiviste::get_rivista(string no, string ac, const Data& da) const{
	MezzoDivulgativo nuovo(no, ac, da);

	for(auto rivista: riviste){
		if(nuovo == *rivista){ return rivista; }
	}
	
    return nullptr;
}

Rivista* GestoreRiviste::get_rivista(string nome) const{
    for(auto rivista: riviste){
        if(rivista->get_nome() == nome){ return rivista; }
    }

    return nullptr;
}

list<Rivista> GestoreRiviste::lista_riviste() const{ 
	list<Rivista> nuove_riviste;
    for(auto rivista: riviste){ nuove_riviste.push_back(*rivista); }

	return nuove_riviste; 
}

void GestoreRiviste::elimina_riviste(){ 
	for(auto rivista: riviste){ delete rivista; } 
	riviste.clear();
}

bool GestoreRiviste::aggiungi_rivista(string no, string ac, const Data& da, string ed, unsigned vo){
    if(!esistenza_rivista(no, ac, da)){ riviste.push_back(new Rivista(no, ac, da, ed, vo)); return true; }
    return false;
}

void GestoreRiviste::visualizza_riviste() const{
	for(auto rivista: riviste){
		cout << *rivista << endl;
	}
}
