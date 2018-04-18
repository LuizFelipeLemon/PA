#include "ListaDVD.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void ListaDVD::incluir(const DVD dvd) {
  N++;
  DVD *temp = new DVD[N];
  for (unsigned i = 0; i < (N - 1); i++) {
    temp[i] = x[i];
  }
  temp[N - 1] = dvd;
  delete[] x;
  x = temp;
}

void ListaDVD::excluir(unsigned i) {
  if (i < N) {
    DVD *temp = new DVD[N - 1];
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

void ListaDVD::imprimir() const {
  cout << "LISTADVD " << N << endl;

  for (unsigned i = 0; i < N; i++) {
    cout << i << ") " << x[i];
  }
}

void ListaDVD::ler(istream &I) {
  I.ignore(numeric_limits<streamsize>::max(), ' ');
  I >> N;
  if (x != NULL) delete[] x;
  x = new DVD[N];
  for (unsigned i = 0; i < N; i++) {
    DVD d;
    d.ler(I);
    x[i] = d;
  }
}

void ListaDVD::salvar(ostream &O) const {
  O << "LISTADVD " << N << endl;

  for (unsigned i = 0; i < N; i++) {
    O << x[i];
  }
  O << endl;
}
