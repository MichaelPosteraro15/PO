#include "GestoreConferenze.h"

GestoreConferenze::GestoreConferenze() {}

GestoreConferenze::GestoreConferenze(const GestoreConferenze& g){
    for(auto conferenza: g.conferenze){
		Conferenza* nuova_conferenza = new Conferenza(conferenza->get_nome(), conferenza->get_acronimo(), conferenza->get_data(),
			                                          conferenza->get_luogo(), conferenza->get_organizzatori(), conferenza->get_numero_partecipanti());
		conferenze.push_back(nuova_conferenza);
	}
}

GestoreConferenze::~GestoreConferenze(){ elimina_conferenze(); }

GestoreConferenze& GestoreConferenze::operator=(const GestoreConferenze& g){
    if(this == &g){
       elimina_conferenze();

       for(auto conferenza: conferenze){
		   Conferenza* nuova_conferenza = new Conferenza(conferenza->get_nome(), conferenza->get_acronimo(), conferenza->get_data(),
			                                             conferenza->get_luogo(), conferenza->get_organizzatori(), conferenza->get_numero_partecipanti());
		   conferenze.push_back(nuova_conferenza);
	   }
	}
	return *this;
}

bool GestoreConferenze::esistenza_conferenza(string no, string ac, const Data& da) const{
	MezzoDivulgativo nuovo(no, ac, da);

	for(auto conferenza: conferenze){
		if(nuovo == *conferenza){ return true; }
	}
	
    return false;
}

Conferenza* GestoreConferenze::get_conferenza(string no, string ac, const Data& da) const{
	MezzoDivulgativo nuovo(no, ac, da);

	for(auto conferenza: conferenze){
        if(nuovo == *conferenza){ return conferenza; }
	}
	
    return nullptr;
}

list<Conferenza> GestoreConferenze::lista_conferenze() const{ 
    list<Conferenza> nuove_conferenze;

    for(auto conferenza: conferenze){ nuove_conferenze.push_back(*conferenza); }

	return nuove_conferenze; 
}

void GestoreConferenze::elimina_conferenze(){ 
	for(auto conferenza: conferenze){ delete conferenza; } 
	conferenze.clear();
}

bool GestoreConferenze::aggiungi_conferenza(string no, string ac, const Data& da, string lu, const list<string>& og, unsigned pa){
	if(!esistenza_conferenza(no, ac, da)){ conferenze.push_back(new Conferenza(no, ac, da, lu, og, pa)); return true; }
	return false;
}

void GestoreConferenze::visualizza_conferenze() const{
	for(auto conferenza: conferenze){
		cout << *conferenza << endl;
	}
}
