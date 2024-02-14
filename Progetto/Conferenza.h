#ifndef CONFERENZA_H
#define CONFERENZA_H

#include "MezzoDivulgativo.h"
#include <list>

//una conferenza é un mezzo divulagativo quindi eredito public

class Conferenza: public MezzoDivulgativo{

private:

	string luogo;
	list<string> organizzatori;
	unsigned numero_partecipanti;

protected:

	ostream& stampa(ostream&) const;

public:

	Conferenza();
	Conferenza(string, string, const Data& , string, const list<string>&, unsigned);

	string get_luogo() const;
	const list<string>& get_organizzatori() const;
	unsigned get_numero_partecipanti() const;

	friend ostream& operator<<(ostream&, const Conferenza&);	
};

#endif