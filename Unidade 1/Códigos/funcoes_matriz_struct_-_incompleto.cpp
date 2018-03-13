#include <iostream>

using namespace std;

/*
Exerc�cio de utiliza��o de fun��es em conjunto com arrays alocados dinamicamente (ponteiros)

Nesse exercicio, voce deve definir o novo tipo Matriz utilizando uma struct, que armazena
tanto o numero de linhas e de colunas de cada matriz quanto o ponteiro

A partir desse tipo Matriz, voce deve programar as funcoes necessarias para executar o programa
principal a seguir. A ideia eh permitir fazer as operacoes indicadas com matrizes de quaisquer
dimensoes, fornecidas pelo usuario no momento da execucao (e nao na compilacao).

*/

// FACA SEUS ACRESCIMOS NO CODIGO AQUI


struct Matriz{
        unsigned int NL,NC;
        float **X;
    } ;

Matriz novaMatriz(unsigned int NLin, unsigned int NCol){

    Matriz prov;
    if(NLin == 0 || NCol == 0){
        cerr<<"Dimensão inválida\n";
        return (Matriz vazia);
    }
    prov.NL = NLin;
    prov.NC = NCol;
    prov.M = new float*[Nlin];

    return ;
}



int main(void)
{
    

    // Declaracao das matrizes
    Matriz A, B, C;

    unsigned NLa, NCa, NLb, NCb;
    do {
        cout << "Linhas de A: ";
        cin >> NLa;
    } while (NLa <= 0);
    do {
        cout << "Colunas de A: ";
        cin >> NCa;
    } while (NCa <= 0);
    // Obs: NLb = NCa
    NLb = NCa;
    do {
        cout << "Colunas de B: ";
        cin >> NCb;
    } while (NCb <= 0);

    // Alocacao das matrizes
    A = novaMatriz(NLa,NCa);
    B = novaMatriz(NLb,NCb);

    // Leitura das matrizes A e B
    leMatriz(A);
    leMatriz(B);

    // produto das matrizes
    C = produtoMatrizes(A,B);

    // Impressao das matrizes
    imprimeMatriz(C);

    // Liberacao das memorias
    liberaMatriz(A);
    liberaMatriz(B);
    liberaMatriz(C);

    return  0;
}
