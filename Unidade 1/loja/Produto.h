#ifndef CLASSE_DO_LUIZ_PARA_UMA_LOJA
#define CLASSE_DO_LUIZ_PARA_UMA_LOJA

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Produto {
 public:
  inline Produto() : nome(""), price(0){};
  inline Produto(string _nome, int _price) : nome(_nome), price(_price){};

  istream &digitar(istream &in);
  ostream &imprimir(ostream &out) const;

  inline friend istream &operator>>(istream &I, Produto &X) {
    return X.digitar(I);
  }
  inline friend ostream &operator<<(ostream &O, Produto &X) {
    return X.imprimir(O);
  }

  void ler(istream &I);
  inline ostream &salvar(ostream &O) const { return imprimir(O); }

 private:
  string nome;
  int price;
};

#endif  // !CLASSE_DO_LUIZ_PARA_UMA_LOJA
