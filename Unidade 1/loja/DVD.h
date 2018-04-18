#ifndef CLASSE_DO_LUIZ_PARA_UMA_DVD
#define CLASSE_DO_LUIZ_PARA_UMA_DVD

#include <fstream>
#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

class DVD : public Produto {
 public:
  inline DVD() : Produto(), dur(0) {}

  istream &digitar(istream &in);
  ostream &imprimir(ostream &out) const;

  void ler(istream &I);
  inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  string autor;
  int dur;
};

inline istream &operator>>(istream &I, DVD &C) { return C.digitar(I); }
inline ostream &operator<<(ostream &O, DVD &C) { return C.imprimir(O); }

#endif  // !CLASSE_DO_LUIZ_PARA_UMA_LOJA
