//Luiz Felipe Santana
//PA 2018.1
#include<iostream>
#include "Voo.h"

using namespace std;

Voo::Voo(){

    //numero,departure,arrival = 0;
    //origem[0],destino[0],origem[1],destino[1],origem[2],destino[2] = '-';
}

void copy(char c1[],char c2[]){
    c1[0] = c2[0];
    c1[1] = c2[1];
    c1[2] = c2[2];
    
}
istream &operator>>(istream &put, Voo &voo){
    
    unsigned int _numero,_departure,_arrival;

    do{
        cout<<"Digite um número para o voo\n";
        put>>_numero;
    }while(_numero<1000 || _numero > 9999);

    do{
        cout<<"Digite um Horário de partida\n";
        put>>_departure;
        
    }while(_departure<0 || _departure > 2359);

    do{
        cout<<"Digite um Horário de chegada\n";
        put>>_arrival;
        
    }while(_arrival<0 || _arrival > 2359);

    cout<<"Digite a Origem\n";
    put.ignore();
    put.getline(voo.origem,4);
    cout<<"Digite a Destino\n";
    put.getline(voo.destino,4);
    voo.numero = _numero;
    voo.departure = _departure;
    voo.arrival = _arrival;

    return put;

}

ostream &operator<<(ostream &print, const Voo &voo){

    print<<"Voo de n°: "<< voo.numero<<" Partindo de "<< voo.origem << " as " << voo.departure
                        << " Pousando em " << voo.destino << " as " << voo.arrival << endl;

    return print;
}
