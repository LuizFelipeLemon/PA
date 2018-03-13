//Luiz Felipe Santana
//PA 2018.1

//
#ifndef _LIBRARY_DO_LUIZ_PRA_VOO_
#define _LIBRARY_DO_LUIZ_PRA_VOO_

#include<iostream>

using namespace std;


class Voo {
    
public:
    Voo();
    
    
    friend istream &operator>>(istream &put, Voo &voo);
    friend ostream &operator<<(ostream &print, const Voo &voo);


    inline unsigned getNumero() const {return numero;}
    inline unsigned getDeparture() const {return departure;}
    inline unsigned getArrival() const {return arrival;}

    inline char* getOrigem() {return origem;};
    inline char* getDestino() {return destino;};

    

private:

    unsigned int numero;
    char origem[4];
    char destino[4];
    unsigned int departure, arrival;

};

#endif
