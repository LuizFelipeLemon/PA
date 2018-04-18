// g++ -g -Wall -I/ Voo.cpp main.cpp -o test

#include "Produto.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

///
using namespace std;

istream &Produto::digitar(istream &in) {
  in.ignore();
  cout << "Digite  o nome do produto: ";
  getline(in, nome);
  cout << "Digite o preco: ";

  in >> price;
  price *= 100;
  int temp;
  in.ignore(numeric_limits<streamsize>::max(), '.');
  in >> temp;
  in.ignore();

  price += temp;

  return in;
}

ostream &Produto::imprimir(ostream &out) const {
  out << '"' << nome << '"' << ";$" << price / 100 << '.' << price % 100 << ';';
  return out;
}

void Produto::ler(istream &I) {
  // Expectativa
  // Memorial”;$32.34;”Pedro”
  I.ignore(numeric_limits<streamsize>::max(), '"');
  getline(I, nome, '"');
  // I.ignore(numeric_limits<streamsize>::max(), ';');
  I.ignore(numeric_limits<streamsize>::max(), '$');
  float temp;
  I >> temp;
  price = temp * 100;
}
