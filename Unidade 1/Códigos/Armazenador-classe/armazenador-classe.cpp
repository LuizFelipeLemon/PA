#include <iostream>
#include "armazenador-classe.h"

using namespace std;

lista_valor::lista_valor(void)
{
  N = 0;
  x = NULL;
}

lista_valor::lista_valor(unsigned int Num)
{
  N = Num;
  x = (Num==0 ? NULL : new valor[Num]);
}

lista_valor::~lista_valor(void)
{
  if (x!=NULL) delete[] x;
}

void lista_valor::inserir(valor V)
{
  valor *prov = new valor[N+1];
  for (unsigned i=0; i<N; i++) prov[i] = x[i];
  prov[N] = V;
  delete[] x;
  x = prov;
  N++;
}

void lista_valor::remover(void)
{
  if (N==0)
  {
    cerr << "Lista vazia. Nao hah o que remover\n";
    return;
  }
  N--;
  valor *prov = new valor[N];
  for (unsigned i=0; i<N; i++) prov[i] = x[i+1];
  delete[] x;
  x = prov;
}

valor lista_valor::primeiro(void) const
{
  if (N==0)
  {
    cerr << "Lista vazia. Nao hah o que retornar\n";
    return 0;
  }
  return x[0];
}

void lista_valor::imprimir(void) const
{
  for (unsigned i=0; i<N; i++) cout << x[i] << ' ';
  cout << endl;
}
