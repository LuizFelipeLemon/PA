#include "loja_polim_STL.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

istream &Produto::digitar(istream &I) {
  double Pr;
  I.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nome: ";
  getline(I, nome);
  cout << "Preco (##.##): ";
  I >> Pr;
  preco = (unsigned)round(100.0 * Pr);
  return I;
}

istream &Produto::ler(istream &I) {
  // Formato da linha no arquivo-> "STRING_AUTOR";$FLOAT_PRECO
  double Pr;

  I.ignore(numeric_limits<streamsize>::max(), '"');
  getline(I, nome, '"');
  I.ignore(numeric_limits<streamsize>::max(), '$');
  I >> Pr;
  preco = (unsigned)round(100.0 * Pr);
  return I;
}

ostream &Produto::imprimir(ostream &O) const {
  // Formato da linha-> "STRING_NOME";$FLOAT_PRECO;
  O << '"' << nome << '"' << ";$" << double(preco) / 100.0;
  return O;
}

istream &Livro::digitar(istream &I) {
  Produto::digitar(I);
  I.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Autor: ";
  getline(I, autor);
  return I;
}

istream &Livro::ler(istream &I) {
  // Formato da linha no arquivo->  L: <Conteudo do Produto>;"STRING_AUTOR"

  Produto::ler(
      I);  // Comeca da aspa da string do nome do Produto; ignora o L inicial
  I.ignore(numeric_limits<streamsize>::max(), '"');
  getline(I, autor, '"');
  return I;
}

ostream &Livro::imprimir(ostream &O) const {
  // Formato da linha-> L: <Conteudo do Produto>;"STRING_AUTOR"
  O << "L: ";
  Produto::imprimir(O);
  O << ';' << '"' << autor << '"';
  return O;
}

istream &CD::digitar(istream &I) {
  Produto::digitar(I);
  cout << "Numero de faixas: ";
  I >> nfaixas;
  return I;
}

istream &CD::ler(istream &I) {
  // Formato da linha no arquivo->  C: <Conteudo do Produto>;UNSIGNED_NFAIXAS
  Produto::ler(
      I);  // Comeca da aspa da string do nome do Produto; ignora o C inicial
  I.ignore(numeric_limits<streamsize>::max(), ';');
  I >> nfaixas;
  return I;
}

ostream &CD::imprimir(ostream &O) const {
  // Formato da linha-> C: <Conteudo do Produto>;UNSIGNED_NFAIXAS
  O << "C: ";
  Produto::imprimir(O);
  O << ';' << nfaixas;
  return O;
}

istream &DVD::digitar(istream &I) {
  Produto::digitar(I);
  cout << "Duracao: ";
  I >> duracao;
  return I;
}

istream &DVD::ler(istream &I) {
  // Formato da linha no arquivo-> D: <Conteudo do Produto>;UNSIGNED_DURACAO
  Produto::ler(
      I);  // Comeca da aspa da string do nome do Produto; ignora o D inicial
  I.ignore(numeric_limits<streamsize>::max(), ';');
  I >> duracao;
  return I;
}

ostream &DVD::imprimir(ostream &O) const {
  // Formato da linha-> D: <Conteudo do Produto>;UNSIGNED_DURACAO
  O << "D: ";
  Produto::imprimir(O);
  O << ';' << duracao;
  return O;
}

// Esta funcao soh eh chamada no construtor ou depois de se executar um limpar()
// Portanto, o vetor x estah sempre vazio, nao precisando ser liberado
void Loja::copiar(const Loja &X) {
  // Faz cada ponteiro do novo array apontar para uma area de memoria alocada e
  // que contem uma copia da area de memoria correspondente no array original
  // Utiliza a funcao clone
  falta_fazer();
}

void Loja::limpar() {
  // Libera a area de memoria que cada um dos ponteiros do vector x aponta
  // Em seguida, limpa o vetor x
  falta_fazer();
}

void Loja::incluir(const Produto &X) {
  // Inclui no vetor x um novo elemento (um novo ponteiro) que aponta para
  // uma area de memoria alocada e que contem uma copia de X
  // Utiliza a funcao clone

  x.push_back(clone(X));
  //falta_fazer();
}

void Loja::excluir(unsigned id) {
  // Checa o indice
  if (size() == 0 || id >= size()) {
    cerr << "Indice invalido\n";
    return;
  }
  // Libera a area de memoria para a qual x[id] aponta
  // Em seguida, exclui o elemento do vetor x
  falta_fazer();
}

void Loja::imprimir() const {
  for (unsigned i = 0; i < size(); i++) cout << i << ") " << *x[i] << endl;
}

void Loja::ler(const char *arq) {
  // Cria a stream associada ao arquivo
  ifstream myfile(arq);

  if (myfile.is_open()) {
    string pS;
    unsigned NN;
    char opcao;
    Livro L;
    CD C;
    DVD D;

    myfile >> pS >> NN;
    if (pS != "LOJA" || NN == 0) {
      cerr << "Arquivo " << arq << " invalido para leitura\n";
      return;
    }

    // Antes de ler os dados de um arquivo, zera o conteudo atual da Loja
    limpar();

    for (unsigned i = 0; i < NN; i++) {
      // Vai para o inicio de uma linha (ignora ENTER de linha anterior)
      myfile.ignore(numeric_limits<streamsize>::max(), '\n');
      // Le o primeiro caractere da linha
      myfile >> opcao;
      switch (opcao) {
        // De acordo com o primeiro caractere, le a linha em uma das variaveis
        // temporarias (C, D ou L) Em seguida, inclui a variavel temporaria na
        // Loja
        case 'C':
          C.ler(myfile);
          incluir(C);
          break;
        case 'D':
          D.ler(myfile);
          incluir(D);
          break;
        case 'L':
          L.ler(myfile);
          incluir(L);
          break;
        default:
          // Primeiro caractere da linha nao era nenhuma das op�oes validas
          cerr << "Arquivo " << arq << " parcialmente invalido para leitura\n";
          return;
      }
    }
    myfile.close();
  } else {
    cerr << "Erro na abertura do arquivo " << arq << " para leitura\n";
  }
}

void Loja::salvar(const char *arq) const {
  ofstream myfile(arq);

  if (myfile.is_open()) {
    // Salva o cabecalho em uma linha
    myfile << "LOJA " << size() << endl;

    // Salva cada um dos produtos em uma linha
    for (unsigned i = 0; i < size(); i++) myfile << *x[i] << endl;

    myfile.close();
  } else {
    cerr << "Erro na abertura do arquivo " << arq << " para escrita\n";
  }
}
