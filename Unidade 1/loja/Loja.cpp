#include "Loja.h"
#include <iostream>
#include "ListaCD.h"
#include "ListaDVD.h"
#include "ListaLivro.h"

using namespace std;

void Loja::incluirLivro(const Livro &l) { ll.incluir(l); }
void Loja::incluirCD(const CD &cd) { lc.incluir(cd); }
void Loja::incluirDVD(const DVD &dvd) { ld.incluir(dvd); }

void Loja::excluirLivro(unsigned i) { ll.excluir(i); }
void Loja::excluirCD(unsigned i) { lc.excluir(i); }
void Loja::excluirDVD(unsigned i) { ld.excluir(i); }

void Loja::ler(const char *c) {
  ifstream arq(c);
  ll.ler(arq);
  lc.ler(arq);
  ld.ler(arq);
}

void Loja::imprimir() const {
  ll.imprimir();
  lc.imprimir();
  ld.imprimir();
}

void Loja::salvar(const char *c) const {
  ofstream arq(c);
  ll.salvar(arq);
  lc.salvar(arq);
  ld.salvar(arq);
  arq.close();
}
