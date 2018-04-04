#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

/// Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
/// Por exemplo, em um construtor.
/// Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
void MyString::criar(unsigned numC)
{
  N = numC;
  c = (N==0 ? NULL : new char[N]);
}

/// Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
/// Por exemplo, em um construtor.
/// Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
void MyString::copiar(const MyString &S)
{
  criar(S.N);
  for (unsigned i=0; i<N; i++) c[i] = S.c[i];
}

void MyString::limpar()
{
  if (c!=NULL) delete[] c;
  N = 0;
  c = NULL;
}

/// Construtor a partir de um array de chars C
MyString::MyString(const char *S)
{
  criar(strlen(S));
  for (unsigned i=0; i<N; i++) c[i] = S[i];
}

char MyString::getChar(unsigned i) const
{
  if (i>=N)
  {
    cerr << "Indice incompativel\n";
    return '\0';
  }
  return c[i];
}

void MyString::setChar(unsigned i, char C)
{
  if (i>=N)
  {
    cerr << "Indice incompativel\n";
    return;
  }
  c[i] = C;
}

ostream &operator<<(ostream &X, const MyString &S)
{
  for (unsigned i=0; i<S.N; i++)
  {
    X << S.c[i];
  }
  return X;
}

/// Leitura de string com no máximo 255 caracteres
/// Como nao se sabe quantos caracteres o usuario vai digitar, nao eh possivel
/// alocar previamente a string.
/// Entao os caracteres vao ser lidos em um buffer provisorio
istream &operator>>(istream &X, MyString &S)
{
  static char buffer[256];  // Buffer provisorio

  // Le e descarta da stream todos os delimitadores (newline, espaco, etc)
  X >> ws;

  // Leh do teclado um maximo de 255 caracteres, ateh encontrar um newline
  X.getline(buffer,256);

  // Lima e aloca a string
  S.limpar();
  S.criar(strlen(buffer));

  // Copia os caracteres do buffer provisorio para a string
  for (unsigned i=0; i<S.N; i++) S.c[i] = buffer[i];

  return X;
}

bool MyString::operator==(const MyString &S) const
{
  if (N != S.N) return false;
  for (unsigned i=0; i<N; i++)
  {
    if (c[i] != S.c[i]) return false;
  }
  return true;
}

bool MyString::operator<(const MyString &S) const
{
  unsigned num = min(N,S.N);

  // Compara os caracteres que tem correspondente na outra string
  for (unsigned i=0; i<N; i++)
  {
    if (c[i] < S.c[i]) return true;
    if (c[i] > S.c[i]) return false;
  }
  // se chegou aqui, os num primeiros caracteres sao identicos
  // Testa o comprimento da segunda string
  if (S.N > num) return true;
  // Nesse caso, ou as duas strings sao identicas
  // ou a primeira string eh mais longa que a segunda
  return false;
}

bool MyString::operator>(const MyString &S) const
{
  unsigned num = min(N,S.N);

  // Compara os caracteres que tem correspondente na outra string
  for (unsigned i=0; i<N; i++)
  {
    if (c[i] > S.c[i]) return true;
    if (c[i] < S.c[i]) return false;
  }
  // se chegou aqui, os num primeiros caracteres sao identicos
  // Testa o comprimento da primeira string
  if (N > num) return true;
  // Nesse caso, ou as duas strings sao identicas
  // ou a segunda string eh mais longa que a segunda
  return false;
}

MyString MyString::operator+(const MyString &S) const
{
  MyString prov(N+S.N);
  for (unsigned i=0; i<N; i++) prov.c[i] = c[i];
  for (unsigned i=0; i<S.N; i++) prov.c[i+N] = S.c[i];
  return prov;
}

MyString MyString::toupper() const
{
  MyString prov(N);
  for (unsigned i=0; i<N; i++) prov.c[i] = std::toupper(c[i]);
  return prov;
}

MyString MyString::tolower() const
{
  MyString prov(N);
  for (unsigned i=0; i<N; i++) prov.c[i] = std::tolower(c[i]);
  return prov;
}
