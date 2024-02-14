#include "GestoreAutori.h"

GestoreAutori::GestoreAutori(){}

GestoreAutori::GestoreAutori(const GestoreAutori& g){
	for(auto autore: g.autori){
		Autore* nuovo_autore = new Autore(autore->get_identificativo(), autore->get_nome(), 
			                              autore->get_cognome(), autore->get_afferenze()); 
		autori.push_back(nuovo_autore);
	}
}

GestoreAutori::~GestoreAutori(){ elimina_autori(); }

GestoreAutori& GestoreAutori::operator=(const GestoreAutori& g){
	if(this == &g){
       elimina_autori();

       for(auto autore: g.autori){
		   Autore* nuovo_autore = new Autore(autore->get_identificativo(), autore->get_nome(), 
			                                 autore->get_cognome(), autore->get_afferenze()); 
		   autori.push_back(nuovo_autore);
	   }
	}
	return *this;
}

bool GestoreAutori::esistenza_autore(string id) const{
	for(auto autore: autori){
		if(autore->get_identificativo() == id){ return true; }
	}
    return false;
}

Autore* GestoreAutori::get_autore(string id) const{
	for(auto autore: autori){
		if(autore->get_identificativo() == id){ return autore; }
	} 
    return nullptr;
}

list<Autore> GestoreAutori::lista_autori() const{ 
	list<Autore> nuovi_autori;
    
    for(auto autore: autori){
    	nuovi_autori.push_back(*autore);
    }
    
	return nuovi_autori; 
}

void GestoreAutori::elimina_autori(){
	for(auto autore: autori){ delete autore; }
		autori.clear();
}

bool GestoreAutori::aggiungi_autore(string id, string no, string co, const list<string>& aff){
	if(!esistenza_autore(id)) { autori.push_back(new Autore(id, no, co, aff)); return true; }
	return false;
}

void GestoreAutori::visualizza_autori() const{
	for(auto autore: autori){
		cout << *autore << endl;
	}
}