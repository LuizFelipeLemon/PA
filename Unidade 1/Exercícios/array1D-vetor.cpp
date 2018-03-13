#include <iostream>

// Este programa ilustra a criacao de arrays unidimensionais
// Cria-se um ponteiro que aponta para uma area de memoria que contem um array de inteiros
// O resultado final se comporta como um vetor unidimensional de inteiros

using namespace std;

int main(void)
{
    int *arr;  // Ptr para int
    unsigned i,N;

    // Entrada de dados
    cout << "Programa de demonstracao de um vetor com dimensao a ser determinada durante a execucao\n";
    do
    {
        cout << "Qual a dimensao do vetor (>0)? ";
        cin >> N;
    } while (N<=0);

    // Cria um vetor de inteiros
    arr = new int[N];

    // Preenche todos os elementos do vetor de inteiros
    for (i=0; i<N; i++)
    {
        arr[i] = i+1;
    }

    // Impressao do vetor
    for (i=0; i<N; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // Liberacao da memoria
    // Libera o vetor de inteiros
    delete[] arr;

    return 0;
}
