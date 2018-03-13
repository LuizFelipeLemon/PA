#include<iostream>
#include"list.h"

using namespace std;

int main(){

    unsigned opcao;
    
    do{
        do{


        cout<< "1 - Inserir um valor no fim da lista\n";
        cout<< "2 - Imprimir o primeiro valor da lista\n";
        cout<< "3 - Remover o primeiro valor da lista\n";
        cout<< "4 - Imprimir o numero de elementos da lista\n";
        cout<< "5 - Imprimir todos os valores da lista\n";
        cout<< "0 - Terminar o programa\n";
        cin>> opcao;

        }while(opcao<0 || opcao>5);
        
        if(opcao == 1){

        } else if(opcao == 2){
            
        } else if(opcao == 3){
            
        } else if(opcao == 4){
            
        } else if(opcao == 5){
            
        }

    }while(opcao != 0);

    return 0;
}