#ifndef RIVISTA_H
#define RIVISTA_H

#include "MezzoDivulgativo.h"

//una rivista é un mezzo divulgativo quindi eredito public

class Rivista: public MezzoDivulgativo{

private:

	string editore;
	unsigned volume;

protected:

	ostream& stampa(ostream&) const;

public:

	Rivista();
	Rivista(string, string, const Data&, string, unsigned);

    string get_editore() const;
    unsigned get_volume() const;

	friend ostream& operator<<(ostream&, const Rivista&);	
};

#endif