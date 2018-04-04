#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>

using namespace std;

class Produto {
 private:
  string nome;
  unsigned preco;

 public:
  inline Produto(const char *N = "", unsigned P = 0) : nome(N), preco(P) {}
  istream &digitar(istream &I);
  ostream &imprimir(ostream &O) const;
  istream &ler(istream &I);
  inline ostream &salvar(ostream &O) const { return imprimir(O); }
};

inline istream &operator>>(istream &I, Produto &X) { return X.digitar(I); }
inline ostream &operator<<(ostream &O, Produto &X) { return X.imprimir(O); }

// =========================================
// Inclua aqui as classes Livro, CD e DVD
// =========================================

class ListaLivro {
 private:
  Livro *x;
  unsigned N;

 public:
  // Inclua os construtores, destrutor e operadores necessarios
  void incluir(const Livro &L);
  void excluir(unsigned id);
  void imprimir() const;
  void ler(istream &I);
  void salvar(ostream &O) const;
};

// =========================================
// Inclua aqui as classes ListaCD e ListaDVD
// =========================================

class Loja {
 private:
  ListaLivro LL;
  ListaCD LC;
  ListaDVD LD;

 public:
  inline Loja() : LL(), LC(), LD() {}
  inline void incluirLivro(const Livro &X) { LL.incluir(X); }
  inline void excluirLivro(unsigned id) { LL.excluir(id); }
  inline void incluirDVD(const DVD &X) { LD.incluir(X); }
  inline void excluirDVD(unsigned id) { LD.excluir(id); }
  inline void incluirCD(const CD &X) { LC.incluir(X); }
  inline void excluirCD(unsigned id) { LC.excluir(id); }
  void imprimir() const;
  void ler(const char *arq);
  void salvar(const char *arq) const;
};
#endif  // _LOJA_H_
