// g++ -g -Wall -I/ Voo.cpp main.cpp -o test

#include "DVD.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
//#include "Produto.h"

///
using namespace std;

istream &DVD::digitar(istream &I) {
  Produto::digitar(I);
  cout << "Digite o numero a duração: ";

  I >> dur;
  I.ignore();

  cout << *this;
  return I;
}

ostream &DVD::imprimir(ostream &O) const {
  O << "D: ";
  Produto::imprimir(O);
  O << dur << endl;
  return O;
}

void DVD::ler(istream &I) {
  Produto::ler(I);
  I.ignore(numeric_limits<streamsize>::max(), ';');
  I >> dur;
}