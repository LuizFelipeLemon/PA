#include <iostream>
#include "armazenador.h"

using namespace std;

int main(void)
{
  valor V;
  lista_valor L;  // Alocacao: chama construtor default
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
      L.inserir(V);
      break;
    case 2:
      V = L.primeiro();
      cout << "Primeiro da lista = " << V << endl;
      break;
    case 3:
      L.remover();
      cout << "Primeiro elemento da lista removido\n";
      break;
    case 4:
      cout << "Numero de valores da lista = " << L.tamanho() << endl;
      break;
    case 5:
      L.imprimir();
      break;
    default:
      break;
    }
  } while (opcao!=0);
  // Destrutor: libera a memoria alocada
}
