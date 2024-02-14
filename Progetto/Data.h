#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data{

private:

    int gg;
    int mm;
    int aa;

public:
    
    Data(){}
    Data(int g, int m, int a){ gg = g; mm = m; aa = a;}
    int get_gg() const{ return gg; }
    int get_mm() const{ return mm; }
    int get_aa() const{ return aa; }

    void set_Data(int g, int m, int a){
        gg = g;
        mm = m;
        aa = a;
    }

	bool operator==(const Data& d){
		return (gg == d.gg) && (mm == d.mm) && (aa == d.aa);
	}

	friend ostream& operator<<(ostream& o, const Data& d){
		o << d.gg << "/" << d.mm << "/" << d.aa;

		return o;
	}
};

#endif
