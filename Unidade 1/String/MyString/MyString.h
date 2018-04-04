#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>

class MyString
{
private:
  unsigned N;
  char *c;
  void criar(unsigned numC);
  void copiar(const MyString &S);
  void limpar();
public:
  /// Construtores e destrutores
  inline MyString(): N(0), c(NULL) {} // Default
  inline MyString(const MyString &S) {copiar(S);}  // Copia
  inline explicit MyString(unsigned numC) {criar(numC);}  // Específico
  MyString(const char *S);  // Especifico
  inline ~MyString() {limpar();}

  /// Metodos de consulta e alteracao de valor
  inline unsigned size(void) const {return N;}
  char getChar(unsigned i) const;
  inline char operator[](unsigned i) const {return getChar(i);}
  void setChar(unsigned i, char C);

  /// Funcoes de entrada e saida de strings (via tela e teclado)
  friend std::ostream &operator<<(std::ostream &X, const MyString &S);
  friend std::istream &operator>>(std::istream &X, MyString &S);

  /// Atribuicao de strings
  inline void operator=(const MyString &S) {if (this!=&S) {limpar(); copiar(S);}}
  /// Concatenacao de strings
  MyString operator+(const MyString &S) const;

  /// Operadores logicos e de precedencia
  /// Compara strings char a char e por ordem alfabetica
  bool operator==(const MyString &S) const;
  inline bool operator!=(const MyString &S) const {return !operator==(S);}
  bool operator<(const MyString &S) const;
  inline bool operator>=(const MyString &S) const {return !operator<(S);}
  bool operator>(const MyString &S) const;
  inline bool operator<=(const MyString &S) const {return !operator>(S);}

  /// Conversao para maiusculas e minusculas
  MyString toupper() const;
  MyString tolower() const;
};
#endif // _MyString_H_
