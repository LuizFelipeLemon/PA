#ifndef _LIB_DO_LUIZ_PARA_LISTA_LIVRO
#define _LIB_DO_LUIZ_PARA_LISTA_LIVRO

#include <iostream>
#include "Livro.h"

using namespace std;

class ListaLivro {
 public:
  inline ListaLivro() : N(0), x(NULL){};

  ListaLivro(const ListaLivro &l);

  ListaLivro operator=(const ListaLivro &l);

  void incluir(const Livro livro);
  void excluir(unsigned i);

  void imprimir() const;
  void ler(istream &I);
  void salvar(ostream &O) const;

  // inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  unsigned N;
  Livro *x;
};

#endif