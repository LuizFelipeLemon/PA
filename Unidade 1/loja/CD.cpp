// g++ -g -Wall -I/ Voo.cpp main.cpp -o test

#include "CD.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
//#include "Produto.h"

///
using namespace std;

istream &CD::digitar(istream &I) {
  Produto::digitar(I);
  cout << "Digite o numero de faixas: ";

  I >> faixas;
  I.ignore();

  cout << *this;
  return I;
}

ostream &CD::imprimir(ostream &O) const {
  O << "C: ";
  Produto::imprimir(O);
  O << faixas << endl;
  return O;
}

void CD::ler(istream &I) {
  Produto::ler(I);
  I.ignore(numeric_limits<streamsize>::max(), ';');
  I >> faixas;
}