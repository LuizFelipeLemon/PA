#ifndef _LIB_DO_LUIZ_
#define _LIB_DO_LUIZ_

#include <iostream>
#include "Voo.h"

using namespace std;

typedef Voo Val;

class List {
 public:
  inline List() : N(0), x(NULL){};

  List(const List &l);

  List operator=(const List &l);

  ~List();

  void inserir(const Val val);
  void imprimir() const;
  void imprimir(const char origem[4]) const;

 private:
  unsigned N;
  Val *x;
};

#endif