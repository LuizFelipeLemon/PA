//
// Created by luiz on 23/05/18.
//

#ifndef _BOOL3S_H_
#define _BOOL3S_H_

#include <iostream>

using namespace std;

// Criando um tipo de dados enumerado (bool3S) para representar um booleano com 3 estados:
// TRUE_3S, FALSE_3S e UNDEF_3S

enum bool3S {
    UNDEF_3S = -1,
    FALSE_3S = 0,
    TRUE_3S = 1
};

// Os operadores logicos para a classe bool3S
// Podem ser usados para facilitar a implementacao dos metodos de simulacao de portas logicas

// NOT 3S
bool3S operator~(bool3S x);
// AND 3S
bool3S operator&(bool3S x1, bool3S x2);
// OR 3S
bool3S operator|(bool3S x1, bool3S x2);
// XOR 3S
bool3S operator^(bool3S x1, bool3S x2);

// Os operadores de incremento/decremento para a classe bool3S

// Os operadores prefixados (++B, --B: incrementa, depois retorna)
bool3S& operator++(bool3S &B);
bool3S& operator--(bool3S &B);
// Os operadores posfixados (B++, B--: retorna copia do valor antes de incrementar)
// O parametro int nao serve para nada, apenas diferencia dos prefixados
bool3S operator++(bool3S &B, int);
bool3S operator--(bool3S &B, int);

// As conversoes entre bool3S e char

// Converte um bool3S para um char que o representa (F T ?)
char toChar(bool3S B);
// Converte um char (F T ?) para o bool3S correspondente
bool3S toBool_3S(char C);

// Os operadores de entrada/saida para a classe bool3S

// Impressao (imprime ? T F se for UNDEF_3S TRUE_3S FALSE_3S)
ostream &operator<<(ostream &O, bool3S x);
// Leitura (leh os caracteres ? T F e seta o valor do bool3S para UNDEF_3S TRUE_3S FALSE_3S)
istream &operator>>(istream &I, bool3S &x);

#endif // _BOOL3S_H_