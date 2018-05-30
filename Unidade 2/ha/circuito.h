#ifndef _CIRCUITO_H_
#define _CIRCUITO_H_

#include <iostream>
#include <string>
#include <vector>
#include "bool3S.h"

using namespace std;

//
// A CLASSE PORTA
//

#define NUM_MAX_INPUTS_PORTA 4

class Porta;
typedef Porta *ptr_Porta;

class Porta {
protected:
  unsigned Nin;
  int id_in[NUM_MAX_INPUTS_PORTA];
  bool3S saida;
public:
  Porta(unsigned NI=2);
  Porta(const Porta &);
  inline virtual ~Porta() {}

  // Essa funcao virtual pura deve criar e retornar um ponteiro para Porta que aponta para
  // uma copia de si mesma, do tipo correto.
  // Por exemplo, se for chamada com um objeto Porta_AND, retorna um ponteiro que aponta para
  // uma area que contem uma Porta_AND cujo valor eh uma copia de *this
  virtual ptr_Porta clone() const = 0;

  // Funcao virtual pura que retorna a sigla correta da Porta (AN, NT, OR, NX, etc.)
  virtual string getNome() const = 0;

  // Funcoes de consulta
  inline unsigned getNumInputs() const {return Nin;}
  inline bool3S getSaida() const {return saida;}
  int getId_in(unsigned i) const;

  // Funcoes de modificacao

  // Fixa o numero de entradas da porta como sendo N, entre 2 e
  // NUM_MAX_INPUTS_PORTA; portanto, vale para todas as portas, exceto NOT.
  // O metodo virtual setNumInputs tem que ser refeito para a NOT.
  // Nao precisa ser reimplementado nas demais portas
  virtual void setNumInputs(unsigned N);
  // Fixa o valor logico da saida da porta
  void setSaida(bool3S s);
  // Fixa a origem (id) da i-esima entrada da porta como sendo Id
  void setId_in(unsigned i, int Id);

  // Leh uma porta do teclado
  // Este metodo para digitar uma porta com numero variavel de entradas (entre 2 e
  // NUM_MAX_INPUTS_PORTA) vale para todas as portas, exceto NOT.
  // O metodo virtual digitar tem que ser refeito para a NOT.
  // Nao precisa ser reimplementado nas demais portas
  virtual void digitar();

  // Leh uma porta da stream I. Retorna true se tudo OK, false se houve erro
  // Este metodo para ler uma porta com numero variavel de entradas (entre 2 e
  // NUM_MAX_INPUTS_PORTA) vale para todas as portas, exceto NOT.
  // O metodo virtual ler tem que ser refeito para a NOT.
  // Nao precisa ser reimplementado nas demais portas
  virtual bool ler(istream &I);

  // Imprime a porta na ostrem O (cout ou uma stream de arquivo, tanto faz)
  // Este metodo nao eh virtual, pois pode ser feito generico de forma a servir para
  // todas as portas.
  // Basta que o metodo imprima o resultado da chamada aa funcao virtual getNome()
  // Retorna a propria ostream O recebida como parametro de entrada, para que possa
  // ser encadeada
  ostream &imprimir(ostream &O) const;

  virtual bool3S simular(const bool3S in[]) = 0;
};

// Operador << com comportamento polimorfico
// Serve para todas as portas (AND, NOR, etc.)
inline ostream &operator<<(ostream &O, const Porta &X) {return (&X)->imprimir(O);};

//
// As outras PORTAS
//

class Porta_NOT: public Porta {
public:
  inline Porta_NOT(): Porta(1) {}
  inline ~Porta_NOT() {}
  inline ptr_Porta clone() const {return new Porta_NOT(*this);}
  inline string getNome() const {return "NT";};

  void setNumInputs(unsigned N);

  void digitar();
  bool ler(istream &I);

  bool3S simular(const bool3S in[]);
};

class Porta_AND: public Porta {
public:
  inline Porta_AND(): Porta() {}
  inline ~Porta_AND() {}
  inline ptr_Porta clone() const {return new Porta_AND(*this);}
  inline string getNome() const {return "AN";};

  bool3S simular(const bool3S in[]);
};

class Porta_NAND: public Porta {
public:
  inline Porta_NAND(): Porta() {}
  inline ~Porta_NAND() {}
  inline ptr_Porta clone() const {return new Porta_NAND(*this);}
  inline string getNome() const {return "NA";};

  bool3S simular(const bool3S in[]);
};

class Porta_OR: public Porta {
public:
  inline Porta_OR(): Porta() {}
  inline ~Porta_OR() {}
  inline ptr_Porta clone() const {return new Porta_OR(*this);}
  inline string getNome() const {return "OR";};

  bool3S simular(const bool3S in[]);
};

class Porta_NOR: public Porta {
public:
  inline Porta_NOR(): Porta() {}
  inline ~Porta_NOR() {}
  inline ptr_Porta clone() const {return new Porta_NOR(*this);}
  inline string getNome() const {return "NO";};

  bool3S simular(const bool3S in[]);
};

class Porta_XOR: public Porta {
public:
  inline Porta_XOR(): Porta() {}
  inline ~Porta_XOR() {}
  inline ptr_Porta clone() const {return new Porta_XOR(*this);}
  inline string getNome() const {return "XO";};

  bool3S simular(const bool3S in[]);
};

class Porta_NXOR: public Porta {
public:
  inline Porta_NXOR(): Porta() {}
  inline ~Porta_NXOR() {}
  inline ptr_Porta clone() const {return new Porta_NXOR(*this);}
  inline string getNome() const {return "NX";};

  bool3S simular(const bool3S in[]);
};

//
// A CLASSE CIRCUITO
//

class Circuito {
private:
  // Nao precisa manter variaveis (unsigned) para guardar as dimensoes do Circuito, ou seja,
  // o numero de entradas, saidas e portas
  // Essas informacoes estao armazenadas nos tamanhos (size) dos vetores correspondentes:
  // inputs, id_out e portas
  // Os metodos de consulta getNumInputs, getNumOutputs e getNumPortas dao acesso a essas
  // informacoes de maneira eficiente
  vector<bool3S> inputs;   // vetor que deve ser alocado com dimensao "Nin"
  vector<int> id_out;       // vetor que deve ser alocado com dimensao "Nout"
  vector<ptr_Porta> portas; // vetor que deve ser alocado com dimensao "Nportas"

  // ATENCAO: fora de um construtor, sempre chamar limpar() antes de utilizar a funcao alocar
  void alocar(unsigned NI, unsigned NO, unsigned NP);
  // ATENCAO: fora de um construtor, sempre chamar limpar() antes de utilizar a funcao copiar
  void copiar(const Circuito &C);
public:
  // As variaveis do tipo Circuito sao sempre criadas sem nenhum dado
  // A definicao do numero de entradas, saidas e portas eh feita ao ler do teclado ou arquivo
  // ou ao executar o metodo redimensionar
  inline Circuito():inputs(),id_out(),portas() {}
  // Construtor por copia: apenas chama a funcao copiar
  inline Circuito(const Circuito &C) {copiar(C);}
  // Limpa todo o conteudo do circuito
  void limpar();
  // Destrutor: apenas chama a funcao limpar
  inline ~Circuito() {limpar();}
  // Operador de atribuicao: apenas chama as funcoes copiar e limpar
  inline void operator=(const Circuito &C) {if (this!=&C) {limpar(); copiar(C);}}

  // Funcoes de consulta
  // Caracteristicas do circuito
  inline unsigned getNumInputs() const {return inputs.size();}
  inline unsigned getNumOutputs() const {return id_out.size();}
  inline unsigned getNumPortas() const {return portas.size();}
  // Caracteristicas das portas
  string getNomePorta(unsigned IdPorta) const;
  // Retorna o numero de entradas da porta cuja id eh IdPorta
  unsigned getNumInputsPorta(unsigned IdPorta) const;
  // Retorna a origem (a id) da i-esima entrada da porta cuja id eh IdPorta
  int getId_inPorta(unsigned IdPorta, unsigned i) const;
  // Caracteristicas das saidas
  // Retorna o valor logico atual da saida cuja id eh IdOut
  bool3S getSaida(unsigned IdOut) const;
  // Retorna a origem (a id) do sinal de saida cuja id eh IdOut
  int getIdOutput(unsigned IdOut) const;
  // Retorna true se o circuito eh valido (estah com todos os dados corretamente preenchidos)
  bool valido() const;

  // Funcoes de modificacao de valores
  // Caracteristicas do circuito
  // Redimensiona o circuito para passar a ter NI entradas, NO saidas e NP portas
  inline void redimensionar(unsigned NI, unsigned NO, unsigned NP) {limpar(); alocar(NI,NO,NP);}
  // Caracteristicas das portas
  // A porta cuja id eh IdPorta passa a ser do tipo T (NT, AN, etc.), com NIn entradas
  void setPorta(unsigned IdPorta, const string &T, unsigned NIn);
  // Altera a origem da I-esima entrada da porta cuja id eh IdPorta, que passa a ser "Id"
  void setId_inPorta(unsigned IdPorta, unsigned I, int Id) const;
  // Caracteristicas das saidas
  // Altera a origem da saida de id "IdOut", que passa a ser "Id"
  void setIdOutput(unsigned IdOut, int Id);

  // Entrada dos dados de um circuito via teclado
  void digitar();
  // Entrada dos dados de um circuito via arquivo
  // Retorna true se deu tudo OK; false se deu erro
  bool ler(const string &arq);
  // Saida dos dados de um circuito (em tela ou arquivo, a mesma funcao serve para os dois)
  ostream &imprimir(ostream &O=cout) const;
  // Salvar circuito em arquivo
  // Abre a stream e depois chama o metodo imprimir
  // Retorna true se deu tudo OK; false se deu erro
  bool salvar(const string &arq) const;
  // Solicita ao usuario que digite os valores das entradas do circuito, que sao
  // as variaveis inputs[i], i de 0 a Nin-1
  void digitarEntradas();
  // Imprime em tela os valores das variaveis inputs[i]
  void imprimirEntradas(void) const;
  // Imprime em tela os valores das saidas das portas ou das entradas do circuito que estao conectadas
  // aas saidas do circuito, de acordo com as variaveis id_out[i], i de 0 a Nout-1
  void imprimirSaidas(void) const;

  // Calcula a saida das portas do circuito para os valores de entrada que estao em inputs[i]
  void simular();
  // Calcula a saida das portas do circuito para os valores de entrada passados como parametro.
  // A entrada eh um vetor de bool3S, com dimensao igual ao numero de entradas do circuito.
  // Retorna true se a simulacao foi OK; false caso deh erro
  bool simular(vector<bool3S> Inputs);
  // Gera e imprime em tela todas as linhas da tabela verdade do circuito
  void gerarTabela(void);
};

// Operador de impressao da classe Circuito
// Utiliza o metodo imprimir
inline ostream &operator<<(ostream &O, const Circuito &C) {return C.imprimir(O);}

#endif // _CIRCUITO_H_
