#ifndef _LIB_DO_LUIZ_PARA_LISTA_CD
#define _LIB_DO_LUIZ_PARA_LISTA_CD

#include <iostream>
#include "CD.h"

using namespace std;

class ListaCD {
 public:
  inline ListaCD() : N(0), x(NULL){};

  ListaCD(const ListaCD &l);

  ListaCD operator=(const ListaCD &l);

  void incluir(const CD cd);
  void excluir(unsigned i);

  void imprimir() const;
  void ler(istream &I);
  void salvar(ostream &O) const;

  // inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  unsigned N;
  CD *x;
};

#endif