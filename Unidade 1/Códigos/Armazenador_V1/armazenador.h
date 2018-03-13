#ifndef _ARMAZENADOR_H_
#define _ARMAZENADOR_H_

#include <iostream>

using namespace std;

/// O tipo de dados "valor"
typedef double valor;

/// O tipo de dados "lista_valor"
class lista_valor
{
private:
  ///  Numero de valores armazenados na lista
  unsigned N;
  /// Array dinamico (ponteiro) com os valores armazenados
  valor *x;
public:
  /// Construtores e destrutores
  inline lista_valor(): N(0), x(NULL) {}
  explicit lista_valor(unsigned int Num);
  lista_valor(const lista_valor &L);
  ~lista_valor();
  /// Operador de atribuicao
  void operator=(const lista_valor &L);

  /// Consulta
  inline unsigned tamanho() const {return N;}
  valor operator[](unsigned i) const;
  inline valor primeiro(void) const {return operator[](0);}

  /// Imprimir
  friend ostream& operator<<(ostream& X, const lista_valor &L);
  inline void imprimir() const {cout << *this << endl;}

  /// Inclusao e exclusao de valores
  void inserir(valor V);
  void remover(void);
};
#endif // _ARMAZENADOR_H_
