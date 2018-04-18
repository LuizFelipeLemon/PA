#ifndef CLASSE_DO_LUIZ_PARA_UMA_CD
#define CLASSE_DO_LUIZ_PARA_UMA_CD

#include <fstream>
#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

class CD : public Produto {
 public:
  inline CD() : Produto(), faixas(0) {}

  istream &digitar(istream &in);
  ostream &imprimir(ostream &out) const;

  void ler(istream &I);
  inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  string autor;
  int faixas;
};

inline istream &operator>>(istream &I, CD &C) { return C.digitar(I); }
inline ostream &operator<<(ostream &O, CD &C) { return C.imprimir(O); }

#endif  // !CLASSE_DO_LUIZ_PARA_UMA_LOJA
