#ifndef CLASSE_DO_LUIZ_PARA_UMA_LIVRO
#define CLASSE_DO_LUIZ_PARA_UMA_LIVRO

#include <fstream>
#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

class Livro : public Produto {
 public:
  inline Livro() : Produto(), autor("") {}

  istream &digitar(istream &in);
  ostream &imprimir(ostream &out) const;

  inline friend istream &operator>>(istream &I, Livro &L) {
    return L.digitar(I);
  }
  inline friend ostream &operator<<(ostream &O, Livro &L) {
    return L.imprimir(O);
  }

  void ler(istream &I);
  inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  string autor;
};

#endif  // !CLASSE_DO_LUIZ_PARA_UMA_LOJA
