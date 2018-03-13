#include <iostream>

/*
Neste programa, sao apresentadas algumas operacoes basicas envolvendo ponteiros.
Existem erros em 8 linhas do programa. Tente encontra-los antes de compilar.
Alem disso, apos eliminar os erros, tente prever o que serah impresso antes de executar.
*/

using namespace std;

int main(void)
{
  int vi;
  float vf;

  int *pi;
  void *pv;

  /// Atribuicao de valores
  vi = 666;
  vf = 3.1416;

  pi = pv;
  pv = pi;
  pi = &vf;
  pv = &vf;

  &vi = pi;

  *pv = 777;
  *pi = 888;

  pi = &vi;
  *pi = 999;

  vf = 2**pi;

  /// Impressao dos atributos

  cout << "=================\n";
  cout << pi << endl;
  cout << &pi << endl;
  cout << sizeof(pi) << endl;
  cout << *pi << endl;
  cout << "=================\n";

  cout << "=================\n";
  cout << pv << endl;
  cout << &pv << endl;
  cout << sizeof(pv) << endl;
  cout << *pv << endl;
  cout << "=================\n";

  cout << "=================\n";
  cout << vi << endl;
  cout << &vi << endl;
  cout << sizeof(vi) << endl;
  cout << *vi << endl;
  cout << "=================\n";

  cout << "=================\n";
  cout << vf << endl;
  cout << &vf << endl;
  cout << sizeof(vf) << endl;
  cout << *vf << endl;
  cout << "=================\n";

  return 0;
}
