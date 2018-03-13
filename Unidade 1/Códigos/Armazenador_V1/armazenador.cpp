#include <iostream>
#include "armazenador.h"

using namespace std;

/// Construtor especifico
lista_valor::lista_valor(unsigned int Num): N(Num)
{
  x = (N==0 ? NULL : new valor[N]);
}

/// Destrutor
lista_valor::~lista_valor(void)
{
  if (x!=NULL) delete[] x;
}

/// Construtor por copia
lista_valor::lista_valor(const lista_valor &L): N(L.N)
{
  x = (N==0 ? NULL : new valor[N]);
  for (unsigned i=0; i<N; i++) x[i] = L.x[i];
}

/// Operador de atribuicao
void lista_valor::operator=(const lista_valor &L)
{
  /// Nao faz nada se o usuario estah fazendo uma autoatribuicao (A=A)
  if (this != &L)
  {
    /// Primeiro, faz uma operacao equivalente ao destrutor
    if (x!=NULL) delete[] x;
    /// Depois, faz operacoes equivalentes ao construtor por copia
    N = L.N;
    x = (N==0 ? NULL : new valor[N]);
    for (unsigned i=0; i<N; i++) x[i] = L.x[i];
  }
}

valor lista_valor::operator[](unsigned i) const
{
  if (i>=N)
  {
    cerr << "Indice invalido\n";
    return 0;
  }
  return x[i];
}

ostream& operator<<(ostream& X, const lista_valor &L)
{
  for (unsigned i=0; i<L.N; i++)
  {
    if (i!=0) X << ' ';
    X << L.x[i];
  }
  return X;
}

void lista_valor::inserir(valor V)
{
  valor *prov = new valor[N+1];
  for (unsigned i=0; i<N; i++) prov[i] = x[i];
  prov[N] = V;
  if (x!=NULL) delete[] x;
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
  valor *prov = (N==0 ? NULL : new valor[N]);
  for (unsigned i=0; i<N; i++) prov[i] = x[i+1];
  delete[] x;
  x = prov;
}
