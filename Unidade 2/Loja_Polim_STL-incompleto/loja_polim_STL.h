#ifndef _LOJA_P_STL_H_
#define _LOJA_P_STL_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto;

typedef Produto *pProduto;

class Produto
{
private:
  string nome;
  unsigned preco;
public:
  inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}

  // Destrutor virtual: recomendado em classes bases que tem algum metodo virtual
  inline virtual ~Produto() {}

  // Funcao clone (virtual):
  // necessaria para o construtor por copia das classes com vetores polimorficos de pProduto
  // Essa funcao aloca memoria e inicializa o valor para criar uma copia de si mesmo (do objeto)
  // Deve ser virtual para criar o objeto do tipo apropriado (das classes derivadas)
  // Metodo virtual puro (=0) porque nao faz sentido criar um objeto que seja da classe base (Produto)
  // Todos os objetos no estoque sao de alguma classe derivada
  // Com isso, a classe Produto se torna uma classe abstrata (nao posso criar objetos dessa classe)
  virtual pProduto clone() const = 0;

  // Metodos virtuais de entrada e saida
  virtual istream &digitar(istream &I);
  virtual istream &ler(istream &I);
  virtual ostream &imprimir(ostream &O) const;
};

// Operator >> e << "virtualizados"
// Para que os operadores sejam "virtuais", eles devem:
// 1) Chamar um metodo que seja virtual, como eh o caso dos metodos digitar e imprimir
// 2) Chamarem o metodo virtual atraves de um ponteiro, e nao de um objeto
// Por isso:
// return X.imprimir(O);     ERRO: nao eh virtual
// return (&X)->imprimir(O); OK: eh virtual
inline istream &operator>>(istream &I, Produto &X) {return (&X)->digitar(I);}
inline ostream &operator<<(ostream &O, Produto &X) {return (&X)->imprimir(O);}

class Livro: public Produto
{
private:
  string autor;
public:
  inline Livro(const char *N="", unsigned P=0, const char *A=""): Produto(N,P), autor(A) {}

  // Note que o metodo clone cria um objeto do tipo certo para cada classe derivada
  inline pProduto clone() const {return new Livro(*this);}

  istream &digitar(istream &I);
  istream &ler(istream &I);
  ostream &imprimir(ostream &O) const;
};

class CD: public Produto
{
private:
  unsigned nfaixas;
public:
  inline CD(const char *N="", unsigned P=0, unsigned NF=0): Produto(N,P), nfaixas(NF) {}

  // Note que o metodo clone cria um objeto do tipo certo para cada classe derivada
  inline pProduto clone() const {return new CD(*this);}

  istream &digitar(istream &I);
  istream &ler(istream &I);
  ostream &imprimir(ostream &O) const;
};

class DVD: public Produto
{
private:
  unsigned duracao;
public:
  inline DVD(const char *N="", unsigned P=0, unsigned D=0): Produto(N,P), duracao(D) {}

  // Note que o metodo clone cria um objeto do tipo certo para cada classe derivada
  inline pProduto clone() const {return new DVD(*this);}

  istream &digitar(istream &I);
  istream &ler(istream &I);
  ostream &imprimir(ostream &O) const;
};

class Loja
{
private:
  vector<pProduto> x;
  void copiar(const Loja &L);
public:
  void limpar();
  inline Loja(): x() {}
  inline Loja(const Loja &L): x() {copiar(L);}
  inline ~Loja() {limpar();}
  inline void operator=(const Loja &L) {if (this!=&L) {limpar(); copiar(L);}}

  inline size_t size() const {return x.size();}

  void incluir(const Produto &X);
  void excluir(unsigned id);

  void imprimir() const;
  void ler(const char* arq);
  void salvar(const char* arq) const;
};
#endif // _LOJA_P_STL_H_
