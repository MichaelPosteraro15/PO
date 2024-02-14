#ifndef MEZZODIVULGATIVO_H
#define MEZZODIVULGATIVO_H

#include "Data.h"

class MezzoDivulgativo{

private:

	string nome;
	string acronimo;
    Data data;

protected:

	virtual ostream& stampa(ostream&) const;

public:

	MezzoDivulgativo();
    MezzoDivulgativo(string, string, const Data&);
    virtual ~MezzoDivulgativo();

	string get_nome() const;
	string get_acronimo() const;
	Data get_data() const;

    bool operator==(const MezzoDivulgativo&);
	friend ostream& operator<<(ostream&, const MezzoDivulgativo&);
};

#endif
