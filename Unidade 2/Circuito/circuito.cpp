//
// Created by luiz on 23/05/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "bool3S.h"
#include "circuito.h"

using namespace std;


#define NUM_MAX_INPUTS_PORTA 4


Porta::Porta(unsigned int NI) {

    if(NI > NUM_MAX_INPUTS_PORTA){
        Nin = 4;
        for (int i = 0; i < NUM_MAX_INPUTS_PORTA; ++i) id_in[i] = 0;
    }else{
        Nin = NI;
        for (int i = 0; i < NI; ++i) id_in[i] = 0;
    }
}


Porta::Porta(const Porta &P): Nin(P.Nin), saida(P.saida) {

    for (int i = 0; i < NUM_MAX_INPUTS_PORTA; ++i) id_in[i] = P.id_in[i];
}


int Porta::getId_in(unsigned i) const {
    if(i > Nin)
        return id_in[i];
    else
        return -666;
}

void Porta::setSaida(bool3S s){ saida = s; }

void Porta::setId_in(unsigned i, int Id) {
    if(i > NUM_MAX_INPUTS_PORTA){
        cout<<"Deu ruim";
    }else{
        id_in[i] = Id;
    }
}

void Porta::setNumInputs(unsigned N) {

    if(N > NUM_MAX_INPUTS_PORTA){
        Nin = 4;
        for (int i = 0; i < NUM_MAX_INPUTS_PORTA; ++i) id_in[i] = 0;
    }else{
        Nin = N;
        for (int i = 0; i < N; ++i) id_in[i] = 0;
    }
}

void Porta::digitar() {
    do{
        cout << "Digite o numero de Entradas :\n";
        cin>>Nin;
    }while (Nin < 2 || Nin > NUM_MAX_INPUTS_PORTA);

    for (int i = 0; i < Nin; ++i) id_in[i] = 0;
}

bool Porta::ler(istream &I) {

    I>>Nin;
    I.ignore(numeric_limits<streamsize>::max(),':');
    for (int i = 0; i < Nin; ++i) {
        I>>id_in[i];
    }


}

