#include <iostream>

/*
Neste programa, voce deve desenvolver um aplicativo que permita armazenar uma quantidade qualquer de valores
(int, float, char, como preferir). A quantidade nao eh conhecida a priori.
Desenvolva as funcoes necessarias para executar o programa principal a seguir.
*/

using namespace std;

// Defina o tipo valor
// Defina o tipo lista_valor

int main(void)
{
    valor V;
    lista_valor L=novaLista(0);
    int opcao;

    cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VALORES\n";
    do
    {
        do
        {
            cout << "1 - Inserir um valor no fim da lista\n";
            cout << "2 - Imprimir o primeiro valor da lista\n";
            cout << "3 - Remover o primeiro valor da lista\n";
            cout << "4 - Imprimir o numero de elementos da lista\n";
            cout << "5 - Imprimir todos os valores da lista\n";
            cout << "0 - Terminar o programa\n";
            cin >> opcao;
        } while (opcao<0 || opcao>5);
        switch (opcao)
        {
        case 1:
            cout << "Valor a ser inserido: ";
            cin >> V;
            insira_lista(L, V);
            break;
        case 2:
            V = primeiro_lista(L);
            cout << "Primeiro da lista = " << V << endl;
            break;
        case 3:
            remover_primeiro_lista(L);
            break;
        case 4:
            cout << "Numero de valores da lista = " << L.N << endl;
            break;
        case 5:
            imprimir_lista(L);
            break;
        default:
            break;
        }
    } while (opcao!=0);
    // Liberar a memoria alocada
    libera_lista(L);
}
