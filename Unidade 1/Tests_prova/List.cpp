#include "List.h"
#include <iostream>

using namespace std;

List::List(const List &l) {
  N = l.N;
  x = (N == 0 ? NULL : new Val[N]);
  for (unsigned i = 0; i < N; i++) {
    x[i] = l.x[i];
  }
}

List List::operator=(const List &l) {
  N = l.N;
  x = (N == 0 ? NULL : new Val[N]);
  for (unsigned i = 0; i < N; i++) {
    x[i] = l.x[i];
  }

  return *this;
}

List::~List() {
  if (x != NULL) delete[] x;
}

void List::inserir(const Val val) {
  N++;
  Val *temp = new Val[N];
  for (unsigned i = 0; i < (N - 1); i++) {
    temp[i] = x[i];
  }
  temp[N - 1] = val;
  delete[] x;
  x = temp;
}

void List::imprimir() const {
  for (unsigned i = 0; i < N; i++) {
    cout << x[i];
  }
}

bool equals(const char c1[4], const char c2[4]) {
  for (unsigned i = 0; i < 4; i++) {
    if (c1[i] != c2[i]) return false;
  }
  return true;
}

void List::imprimir(const char origem[4]) const {
  for (unsigned i = 0; i < N; i++) {
    if (equals(x[i].getOrigem(), origem)) {
      cout << x[i];
    }
  }
}
