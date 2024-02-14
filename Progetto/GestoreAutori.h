#ifndef GESTOREAUTORI_H
#define GESTOREAUTORI_H

#include "Autore.h"


class GestoreAutori{

private:

	list<Autore*> autori;
    
public:

    GestoreAutori();
    GestoreAutori(const GestoreAutori&);
    ~GestoreAutori();
    GestoreAutori& operator=(const GestoreAutori&);

    bool esistenza_autore(string) const;
    Autore* get_autore(string) const;
    list<Autore> lista_autori() const;
    void elimina_autori();

	bool aggiungi_autore(string, string, string, const list<string>&);
	void visualizza_autori() const;

};

#endif