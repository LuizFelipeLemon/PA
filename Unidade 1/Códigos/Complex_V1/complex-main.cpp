#include <iostream>
#include "complex.h"

using namespace std;

int main(void)
{
  Complex C1, C2, S, P;

  cout << "Digite o primeiro numero complexo (C1):\n";
  cin >> C1;  // ou seja, operator>>(cin,C1);

  cout << "Digite o segundo numero complexo (C2):\n";
  cin >> C2;  // ou seja, operator>>(cin,C2);

  S = C1+C2;  // ou seja, S = C1.operator+(C2);
  P = C1.operator*(C2);  // ou seja, P = C1*C2;

  cout << "Soma = ";
  cout << S;  // ou seja, operator<<(cout, S);
  cout << endl;

  cout << "Soma+1.0 = ";
  cout << S+1.0;  // conversao implicita de um double para um Complex
  cout << endl;

  cout << "Produto = ";
  cout << P << endl;// ou seja, operator<<( operator<<(cout,P), endl );
}

