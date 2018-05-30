#include "circuito.h"

Porta::Porta(unsigned NI){
    if(NI > NUM_MAX_INPUTS_PORTA)
        ;//cerr << "NUMERO DE INPUTS NA PORTA INVALIDO";
    else
        Nin = NI;
}

Porta::Porta(const Porta &P){
    Nin = P.getNumInputs();
    saida = P.getSaida();
    for(int i = 0; i < Nin; i++){
        id_in[i] = P.getId_in(i);
    }
}

int Porta::getId_in(unsigned i) const{
    if(i<Nin)
        return id_in[i];
    else
        ;//cerr << "ID_IN INVALIDO";
}

void Porta::setNumInputs(unsigned N){
    if(N<2 || N > NUM_MAX_INPUTS_PORTA)
        ;//cerr << "NUMERO DE INPUTS INVÀLIDO";
    else
        Nin = N;
}

void Porta::setSaida(bool3S s){
    saida = s;
}

void Porta::setId_in(unsigned i, int Id){
    if(i<Nin)
        id_in[i] = Id;
    else
        ;//cerr<<"I INVALIDO";
}

//TODO: REFAZER
void Porta::digitar(){
    cout << "Quantidade de entradas: ";
    cin >> Nin;
    if(Nin > 1 &&  Nin <= NUM_MAX_INPUTS_PORTA){
        for (unsigned i =0; i<Nin; i++){
            cout << "Id da entrada " << i << ": ";
            cin >> id_in[i];
        }
    } else {
        cerr << "Quantidade errada de entradas";
    }

    saida = UNDEF_3S;
}

//TODO: REFAZER

bool Porta::ler(istream &I){
    I >> Nin;
    I.ignore(256,' ');

    if (Nin > NUM_MAX_INPUTS_PORTA || Nin < 1){
        cerr << "NUMERO DE INPUTS NA PORTA INVALIDO\n";
        return false;
    }

    for (unsigned i =0; i<Nin; i++){
        I >> this->id_in[i];
    }

    saida = UNDEF_3S;
    return true;
}
//TODO: REFAZER

ostream &Porta::imprimir(ostream &O) const{
    if(Nin > 1 &&  Nin < NUM_MAX_INPUTS_PORTA){
        for (unsigned i =0; i<Nin; i++){
            O << id_in[i] << " ";
        }
    }
    return O;
}

/* FUNÇÕES DE PORTA NOT */

//TODO: REFAZER

void Porta_NOT::digitar(){
    Nin = 1;
    cout<<"ID entrada: ";
    cin >> id_in[0];
    saida = UNDEF_3S;
}
//TODO: REFAZER

bool Porta_NOT::ler(istream &I){
    I >> Nin;
    if(Nin!=1){
        cerr << "NUMERO DE INPUTS NA PORTA INVALIDO\n";
        return false;
    }
    I.ignore(255,' ');
    I >> this->id_in[0];
    saida = UNDEF_3S;
    return true;
}

//TODO: REFAZER


//void Porta_NOT::imprimir(ostream &O) const{
//    O << "NT " << Nin << ": ";
//    O << id_in[0] << " ";
//    return O;
//}

bool3S Porta_NOT::simular(const bool3S in[]){
    saida = ~in[0];
    return saida;
}
/* FUNÇÕES DE PORTA OR */



bool3S Porta_OR::simular(const bool3S in[]){
    bool3S prov = FALSE_3S;
    for(int i=0; i < Nin;i++){
        prov = prov | in[i];
    }
    saida = prov;
    return saida;
}

/* FUNÇÕES DE PORTA AND */


bool3S Porta_AND::simular(const bool3S in[]){
    bool3S prov = TRUE_3S;
    for(int i = 0; i < Nin;i++){
        prov = prov & in[i];
    }
    saida = prov;
    return saida;
}

/* FUNÇÕES DE PORTA NAND */



bool3S Porta_NAND::simular(const bool3S in[]){
    bool3S prov = TRUE_3S;
    for(int i = 0; i < Nin;i++){
        prov = prov & in[i];
    }
    saida = ~prov;

    return saida;
}


/* FUNÇÕES DE PORTA NOR */


bool3S Porta_NOR::simular(const bool3S in[]){
    bool3S prov = FALSE_3S;
    for(int i=0; i < Nin;i++){
        prov = prov | in[i];
    }
    saida = ~prov;
    return saida;
}

/* FUNÇÕES DE PORTA XOR */

bool3S Porta_XOR::simular(const bool3S in[]){
    bool3S prov = FALSE_3S;
    for(int i=0; i < Nin;i++){
        prov = prov ^ in[i];
    }
    saida = prov;
    return saida;
}

/* FUNÇÕES DE PORTA NXOR */


bool3S Porta_NXOR::simular(const bool3S in[]){
    bool3S prov = FALSE_3S;
    for(int i=0; i < Nin;i++){
        prov = prov ^ in[i];
    }
    saida = ~prov;
    return saida;
}

