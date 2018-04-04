// g++ -g -Wall -I/ Voo.cpp main.cpp -o test

#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

int main() {
  Produto p;
  cin >> p;
  cout << p;

  ofstream arq("files.txt");
  if (arq.is_open()) {
    arq << p;
  }
}