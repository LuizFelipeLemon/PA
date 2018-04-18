// g++ -g -Wall -I/ Voo.cpp main.cpp -o test

#include "Livro.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
//#include "Produto.h"

///
using namespace std;

istream &Livro::digitar(istream &I) {
  Produto::digitar(I);
  cout << "Digite o nome do autor: ";
  // I.ignore();

  getline(I, autor);

  return I;
}

ostream &Livro::imprimir(ostream &O) const {
  O << "L: ";
  Produto::imprimir(O);
  O << '"' << autor << '"' << endl;
  return O;
}

void Livro::ler(istream &I) {
  Produto::ler(I);
  I.ignore(numeric_limits<streamsize>::max(), '"');
  getline(I, autor, '"');
}