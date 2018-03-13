#include <iostream>

// Este programa ilustra a criacao de arrays bidimensionais
// Cria-se um ponteiro que aponta para uma area de memoria que contem um array de ponteiros
// Cada um dos ponteiros do array aponta para uma area de memoria que contem um array de inteiros
// O resultado final se comporta como uma matriz bidimensional de inteiros

using namespace std;

int main(void)
{
    int **arr;  // Ptr para ptr para int
    unsigned i,j,NL,NC;

    // Entrada de dados
    cout << "Programa de demonstracao de uma matriz com dimensao a ser determinada durante a execucao\n";
    do
    {
        cout << "Qual o numero de linhas (>0)? ";
        cin >> NL;
    } while (NL<=0);
    do
    {
        cout << "Qual o numero de colunas (>0)? ";
        cin >> NC;
    } while (NC<=0);

    // Cria um vetor de ponteiros
    arr = new int*[NL];
    for (i=0; i<NL; i++)
    {
        // Faz cada ponteiro do vetor de ponteiros apontar para um vetor de inteiros
        arr[i] = new int[NC];
        for (j=0; j<NC; j++)
        {
            // Preenche todos os elementos de cada um dos vetores de inteiros (colunas da matriz)
            arr[i][j] = 10*(i+1) + (j+1);
        }
    }

    // Impressao da matriz
    for (i=0; i<NL; i++)
    {
        for (j=0; j<NC; j++) cout << arr[i][j] << ' ';
        cout << endl;
    }

    // Liberacao da memoria
    // Primeiro, libera os NL vetores de inteiros
    for (i=0; i<NL; i++) delete[] arr[i];
    // Em seguida, libera o vetor de ponteiros
    delete[] arr;

    return 0;
}
