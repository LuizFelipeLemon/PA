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
    for(unsigned i = 0; i < Nin; i++){
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
void Porta_NOT::imprimir() const{
    //O << "NT " << Nin << ": ";
    //O << id_in[0] << " ";
    //return O;
}

void Porta_NOT::setNumInputs(unsigned N){
    if(N<1)
        ;//cerr << "NUMERO DE INPUTS INVÀLIDO";
    else
        Nin = N;
}

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


void Circuito::limpar(){
    inputs.clear();
    id_out.clear();
    for(int i = 0; i<portas.size();i++){
        delete portas[i];
    }
    portas.clear();
}

void Circuito::alocar(unsigned NI, unsigned NO, unsigned NP){
    limpar();
    inputs.resize(NI);
    id_out.resize(NO);
    portas.resize(NP);
    for(unsigned i = 0; i<NP;i++){
        portas[i] = NULL;
    }
}

void Circuito::copiar(const Circuito &C){
    limpar();
    alocar(C.getNumInputs(),C.getNumOutputs(),C.getNumPortas());
    inputs = C.inputs;
    id_out = C.id_out;
    for(unsigned i = 0; i< portas.size();i++){

        portas[i] = C.portas[i]->clone();

    }
}

string Circuito::getNomePorta(unsigned IdPorta) const{
    if(!(IdPorta>portas.size()))
        return portas[IdPorta]->getNome();
    return NULL;
}

unsigned Circuito::getNumInputsPorta(unsigned IdPorta) const{
    if(!(IdPorta>portas.size()))
        return portas[IdPorta]->getNumInputs();
    return 0;
}

int Circuito::getId_inPorta(unsigned IdPorta, unsigned i) const{
    if(!(IdPorta>portas.size()))
        return portas[IdPorta]->getId_in(i);
    return 0;
}

bool3S Circuito::getSaida(unsigned IdOut) const{
     if(!(IdOut>id_out.size()))
        return portas[id_out[IdOut]]->getSaida();
     return UNDEF_3S;
}

int Circuito::getIdOutput(unsigned IdOut) const{
    if(!(IdOut>id_out.size()))
       return id_out[IdOut];
    return 0;
}


bool Circuito::valido() const{

    for(unsigned i = 0; i<portas.size();i++){
        for(unsigned j = 0; j< portas[i]->getNumInputs();j++){
            if(portas[i]->getId_in(j) == 0)
                return false;
        }
    }

    return true;

}

void Circuito::setPorta(unsigned idPorta, const string &T, unsigned NIn){
    if(T == "NT"){
        Porta_NOT NT;
        (&NT)->setNumInputs(NIn);
        portas[idPorta] = (&NT) -> clone();

    }
    else if(T == "AN") {
        Porta_AND AN;
        (&AN)->setNumInputs(NIn);
        portas[idPorta] = (&AN) -> clone();
    }
    else if(T == "NA")  {
        Porta_NAND NA;
        (&NA)->setNumInputs(NIn);
        portas[idPorta] = (&NA) -> clone();
    }
    else if(T == "OR")  {
        Porta_OR OR;
        (&OR)->setNumInputs(NIn);
        portas[idPorta] = (&OR) -> clone();
    }
    else if(T == "NO")  {
        Porta_NOR NOR;
        (&NOR)->setNumInputs(NIn);
        portas[idPorta] = (&NOR) -> clone();
    }
    else if(T == "XO")  {
        Porta_XOR XO;
        (&XO)->setNumInputs(NIn);
        portas[idPorta] = (&XO) -> clone();
    }
    else if(T == "NX")  {
        Porta_NXOR NX;
        (&NX)->setNumInputs(NIn);
        portas[idPorta] = (&NX) -> clone();
    }
    else{
        //cerr << "Tipo de porta inesistente.";
        limpar();
        return;
    }
}


void Circuito::setId_inPorta(unsigned IdPorta, unsigned I, int Id) const{
    if(!(IdPorta>portas.size()|| Id>portas.size()))
        portas[IdPorta]->setId_in(I,Id);

}

void Circuito::setIdOutput(unsigned IdOut, int Id){
    if(!(IdOut>id_out.size() || Id>portas.size()))
        id_out[IdOut] = Id;

}

void Circuito::simular(){
    for(unsigned i = 0; i<portas.size();i++){
        portas[i]->setSaida(UNDEF_3S);
    }
    bool tudo = true;
    bool some = false;
    bool3S in_porta[NUM_MAX_INPUTS_PORTA];
    do{


        for(unsigned i = 0; i<portas.size();i++){
            if(portas[i]->getSaida() == UNDEF_3S){
                unsigned in = portas[i]->getNumInputs();
                for(unsigned j = 0; j<in;j++){
                    if (portas[i]->getId_in(j) < 0){
                        in_porta[j] = inputs[-1*(portas[i]->getId_in(j))-1];
                    }

                    if (portas[i]->getId_in(j) > 0){
                        in_porta[j] = portas[portas[i]->getId_in(j)-1]->getSaida();
                    }
                }
                portas[i]->simular(in_porta);
                if(portas[i]->getSaida()==UNDEF_3S)
                    tudo =false;
                else
                    some = true;
            }
        }

    }while(!tudo && some);
}

//TODO: FIX THIS SHIT
bool Circuito::simular(vector<bool3S> Inputs){
    for(unsigned i = 0; i<portas.size();i++){
        portas[i]->setSaida(UNDEF_3S);
    }

    bool tudo = true;
    bool some = false;
    bool3S in_porta[NUM_MAX_INPUTS_PORTA];


    do{

        for(unsigned i = 0; i<portas.size();i++){
            if(portas[i]->getSaida() == UNDEF_3S){
                unsigned in = portas[i]->getNumInputs();
                for(unsigned j = 0; j<in;j++){
                    if (portas[i]->getId_in(j) < 0){
                        in_porta[j] = Inputs[-1*(portas[i]->getId_in(j))-1];
                    }

                    if (portas[i]->getId_in(j) > 0){
                        in_porta[j] = portas[portas[i]->getId_in(j)-1]->getSaida();
                    }
                }
                portas[i]->simular(in_porta);
                if(portas[i]->getSaida() == UNDEF_3S)
                    tudo =false;
                else
                    some = true;
            }
        }

    }while(!tudo && some);
    return true;
}

//void Circuito::gerarTabela(void){
//    for(unsigned i=0; i<Nin; i++){
//        inputs[i] = FALSE_3S;
//    }
//    int i=0;

//    for(unsigned k=0;k<Nin;k++)
//        cout<<"In"<<k+1<<"\t";
//    cout<<"|\t";
//    for(unsigned k=0;k<Nout;k++)
//        cout<<"Out"<<k+1<<"\t";

//    cout<<endl;
//    do{
//        simular();
//        for(unsigned k=0;k<Nin;k++)
//            cout<<inputs[k]<<"\t";
//        cout<<"|\t";
//        for(unsigned j=0;j<Nout;j++)
//            cout<<portas[j]->getSaida()<<"\t";

//        cout<<endl;

//        i=Nin-1;
//        while(i>=0 && inputs[i]==UNDEF_3S){
//            inputs[i]=FALSE_3S;
//            i--;
//        }
//        if(i>=0){
//            if(inputs[i]==FALSE_3S)
//                inputs[i]=TRUE_3S;
//            else
//                inputs[i]=UNDEF_3S;
//        }
//    }
//    while(i>=0);
//}
