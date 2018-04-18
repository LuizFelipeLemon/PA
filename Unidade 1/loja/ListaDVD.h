#ifndef _LIB_DO_LUIZ_PARA_LISTA_DVD
#define _LIB_DO_LUIZ_PARA_LISTA_DVD

#include <iostream>
#include "DVD.h"

using namespace std;

class ListaDVD {
 public:
  inline ListaDVD() : N(0), x(NULL){};

  ListaDVD(const ListaDVD &l);

  ListaDVD operator=(const ListaDVD &l);

  void incluir(const DVD dvd);
  void excluir(unsigned i);

  void imprimir() const;
  void ler(istream &I);
  void salvar(ostream &O) const;

  // inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  unsigned N;
  DVD *x;
};

#endif