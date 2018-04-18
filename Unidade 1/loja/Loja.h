#ifndef _LIB_DO_LUIZ_PARA_LISTA_LOJA_
#define _LIB_DO_LUIZ_PARA_LISTA_LOJA_

#include <iostream>
#include "ListaCD.h"
#include "ListaDVD.h"
#include "ListaLivro.h"
// #include "Loja.h"

using namespace std;

class Loja {
 public:
  inline Loja(){};

  Loja(const Loja &l);

  void incluirLivro(const Livro &l);
  void incluirCD(const CD &cd);
  void incluirDVD(const DVD &dvd);

  void excluirLivro(unsigned i);
  void excluirCD(unsigned i);
  void excluirDVD(unsigned i);

  void imprimir() const;
  void ler(const char *c);

  void salvar(const char *c) const;

  // inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  ListaDVD ld;
  ListaCD lc;
  ListaLivro ll;
};

#endif