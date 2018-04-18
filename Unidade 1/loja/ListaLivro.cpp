#include "ListaLivro.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void ListaLivro::incluir(const Livro livro) {
  N++;
  Livro *temp = new Livro[N];
  for (unsigned i = 0; i < (N - 1); i++) {
    temp[i] = x[i];
  }
  temp[N - 1] = livro;
  delete[] x;
  x = temp;
}

void ListaLivro::excluir(unsigned i) {
  if (i < N) {
    Livro *temp = new Livro[N - 1];
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

void ListaLivro::imprimir() const {
  cout << "LISTALIVRO " << N << endl;

  for (unsigned i = 0; i < N; i++) {
    cout << i << ") " << x[i];
  }
}

void ListaLivro::salvar(ostream &O) const {
  O << "LISTALivro " << N << endl;

  for (unsigned i = 0; i < N; i++) {
    O << x[i];
  }
  O << endl;
}

void ListaLivro::ler(istream &I) {
  I.ignore(numeric_limits<streamsize>::max(), ' ');
  I >> N;

  cout << "N: " << N;
  I.ignore(numeric_limits<streamsize>::max(), '\n');

  if (x != NULL) delete[] x;
  x = new Livro[N];
  for (unsigned i = 0; i < N; i++) {
    Livro d;
    d.ler(I);
    cout << d;
    x[i] = d;
  }
}
