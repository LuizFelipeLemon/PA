// Luiz Felipe Santana
// PA 2018.1
// g++ -g -Wall -I/ Voo.cpp main.cpp -o test
#include <iostream>
#include <string>
#include "List.h"
#include "Voo.h"

using namespace std;

int main(void) {
  List LV;
  Voo V;
  char codigo[4];
  int opcao;
  cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VOOS\n";
  do {
    do {
      cout << "1 - Inserir um novo voo na lista\n";
      cout << "2 - Imprimir todos os voos da lista\n";
      cout << "3 - Procurar um voo a partir da origem\n";
      cout << "0 - Terminar o programa\n";
      cin >> opcao;
    } while (opcao < 0 || opcao > 3);
    switch (opcao) {
      case 1:
        cout << "Voo a ser inserido:\n";
        cin >> V;
        LV.inserir(V);
        break;
      case 2:
        LV.imprimir();
        break;
      case 3:
        cout << "Aeroporto de origem a pesquisar:\n";
        cin.ignore();
        cin.getline(codigo, 4);
        cout << codigo;
        LV.imprimir(codigo);
        break;
      default:
        break;
    }
  } while (opcao != 0);
  return 0;
}