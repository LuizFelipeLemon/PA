#ifndef _ARMAZENADOR_CLASSE_H_
#define _ARMAZENADOR_CLASSE_H_

typedef double valor;

class lista_valor
{
private:
  unsigned N;
  valor *x;
public:
  // Construtores e destrutores
  lista_valor();
  explicit lista_valor(unsigned int Num);
  ~lista_valor();

  // Imprimir
  void imprimir() const;

  // Consulta
  inline unsigned tamanho() const {return N;}

  // Inclusao e exclusao de valores
  void inserir(valor V);
  void remover(void);

  // Consulta
  valor primeiro(void) const;
};
#endif // _ARMAZENADOR_CLASSE_H_
