#include "ListaCD.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void ListaCD::incluir(const CD cd) {
  N++;
  CD *temp = new CD[N];
  for (unsigned i = 0; i < (N - 1); i++) {
    temp[i] = x[i];
  }
  temp[N - 1] = cd;
  delete[] x;
  x = temp;
}

void ListaCD::excluir(unsigned i) {
  if (i < N) {
    CD *temp = new CD[N - 1];
    for (unsigned j = 0; j < i; j++) {
      temp[j] = x[j];
    }
    for (unsigned j = i; j < N - 1; j++) {
      temp[j] = x[j + 1];
    }
    delete[] x;
    x = temp;
  } else {
    cout << "Indice inválido";
  }
  N--;
}

void ListaCD::imprimir() const {
  cout << "LISTACD " << N << endl;

  for (unsigned i = 0; i < N; i++) {
    cout << i << ") " << x[i];
  }
}

void ListaCD::salvar(ostream &O) const {
  O << "LISTACD " << N << endl;

  for (unsigned i = 0; i < N; i++) {
    O << x[i];
  }
  O << endl;
}

void ListaCD::ler(istream &I) {
  I.ignore(numeric_limits<streamsize>::max(), ' ');
  I >> N;
  if (x != NULL) delete[] x;
  x = new CD[N];
  for (unsigned i = 0; i < N; i++) {
    CD d;
    d.ler(I);
    x[i] = d;
  }
}
