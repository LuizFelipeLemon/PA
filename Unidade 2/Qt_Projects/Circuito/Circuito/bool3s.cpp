#include <iostream>
#include "bool3s.h"

using namespace std;

//Os operadores logicos para a classe bool3S

// NOT 3S
bool3S operator~(bool3S x)
{
  return ( x==UNDEF_3S ? UNDEF_3S : (x==TRUE_3S ? FALSE_3S : TRUE_3S) );
}

// AND 3S
bool3S operator&(bool3S x1, bool3S x2)
{
  return ( (x1==FALSE_3S || x2==FALSE_3S) ? FALSE_3S : ((x1==UNDEF_3S || x2==UNDEF_3S) ? UNDEF_3S : TRUE_3S) );
}

// OR 3S
bool3S operator|(bool3S x1, bool3S x2)
{
  return ( (x1==TRUE_3S || x2==TRUE_3S) ? TRUE_3S : ((x1==UNDEF_3S || x2==UNDEF_3S) ? UNDEF_3S : FALSE_3S) );
}

// XOR 3S
bool3S operator^(bool3S x1, bool3S x2)
{
  return ( (x1==UNDEF_3S || x2==UNDEF_3S) ? UNDEF_3S : ((x1==x2) ? FALSE_3S : TRUE_3S) );
}

// Os operadores de incremento/decremento para a classe bool3S

// Prefixados (++B, --B: incrementa, depois retorna)

bool3S& operator++(bool3S &B)
{
    if (B==UNDEF_3S) {B=FALSE_3S; return B;}
    if (B==FALSE_3S) {B=TRUE_3S; return B;}
    // Vamos fazer um incremento circular: TRUE->UNDEF
    B=UNDEF_3S; return B;
}

bool3S& operator--(bool3S &B)
{
    if (B==TRUE_3S) {B=FALSE_3S; return B;}
    if (B==FALSE_3S) {B=UNDEF_3S; return B;}
    // Vamos fazer um decremento circular: UNDEF->TRUE
    B=TRUE_3S; return B;
}

// Posfixados (B++, B--: retorna copia do valor antes de incrementar)
// O parametro int nao serve para nada, apenas diferencia dos prefixados

bool3S operator++(bool3S &B, int)
{
    bool3S prov(B);
    ++B;
    return prov;
}

bool3S operator--(bool3S &B, int)
{
    bool3S prov(B);
    --B;
    return prov;
}

// As conversoes entre bool3S e char

// Converte um bool3S para um char que o representa (F T ?)
char toChar(bool3S B)
{
   return (B==TRUE_3S ? 'T' : (B==FALSE_3S ? 'F' : '?'));
}

// Converte um char (F T ?) para o bool3S correspondente
bool3S toBool_3S(char C)
{
    C = toupper(C);
    return (C=='T' ? TRUE_3S : (C=='F' ? FALSE_3S : UNDEF_3S));
}

// Os operadores de entrada/saida para a classe bool3S

// Impressao de bool3S
ostream &operator<<(ostream &O, bool3S B)
{
  O << toChar(B);
  return O;
}

// Leitura de bool3S (? T F)
istream &operator>>(istream &I, bool3S &B)
{
  char prov;
  I >> prov;
  B = toBool_3S(prov);
  return I;
}
