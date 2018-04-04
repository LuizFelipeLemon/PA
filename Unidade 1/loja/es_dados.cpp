#include <stdint.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// UMA CLASSE PARA ARMAZENAR DATAS DE CALENDARIO VALIDAS

class Data {
 private:
  unsigned short int dia;
  unsigned short int mes;
  unsigned short int ano;

 public:
  inline Data() : dia(0), mes(0), ano(0) {}

  inline bool anoValido() const { return (ano >= 1900 && ano <= 2099); }
  inline bool bissexto() const {
    return ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0);
  }
  inline bool mesValido() const { return (mes >= 1 && mes <= 12); }
  unsigned short int numDias(void) const;
  inline bool diaValido() const { return (dia >= 1 && dia <= numDias()); }
  inline bool valido() const {
    return (anoValido() && mesValido() && diaValido());
  }

  void digitar(void);
  void ler(istream &I);
  ostream &imprimir(ostream &O) const;
};
inline ostream &operator<<(ostream &O, const Data &D) { return D.imprimir(O); }

unsigned short int Data::numDias(void) const {
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      return (bissexto() ? 29 : 28);
  }
  // Nunca deve chegar aqui...
  return 0;
}

void Data::digitar(void) {
  do {
    cout << "Ano [1900 a 2099]? ";
    cin >> ano;
  } while (!anoValido());
  do {
    cout << "Mes [1 a 12]? ";
    cin >> mes;
  } while (!mesValido());
  do {
    cout << "Dia? [1 a " << numDias() << "]? ";
    cin >> dia;
  } while (!diaValido());
}

void Data::ler(istream &I) {
  I >> dia;
  I.ignore(numeric_limits<streamsize>::max(), '/');
  I >> mes;
  I.ignore(numeric_limits<streamsize>::max(), '/');
  I >> ano;
  if (!valido()) {
    ano = mes = dia = 0;
  }
}

ostream &Data::imprimir(ostream &O) const {
  O << dia << '/' << mes << '/' << ano;
  return O;
}

// UMA CLASSE PARA ARMAZENAR NUMEROS DE CPF VALIDOS

class CPF {
 private:
  // unsigned long long int CpF;
  uint64_t CpF;

 public:
  inline CPF() : CpF(0) {}

  bool valido() const;

  void digitar(void);
  void ler(istream &I);
  ostream &imprimir(ostream &O) const;
};
inline ostream &operator<<(ostream &O, const CPF &C) { return C.imprimir(O); }

// Verifica se CPF � v�lido (retorna true) ou invalido (retorna false)
bool CPF::valido() const {
  if (CpF > 99999999999ULL || CpF <= 0) return false;

  unsigned digito[11], soma, resto, i;
  uint64_t valor = CpF, potencia = 10000000000ULL;

  // Transforma o CPF em seus 11 digitos (numeros de 0 a 9)
  for (i = 0; i < 11; i++) {
    digito[i] = valor / potencia;
    valor %= potencia;
    potencia /= 10;
  }

  // Calcula a soma ponderada dos 9 primeiros digitos
  soma = 0;
  for (i = 0; i < 9; i++) soma += digito[i] * (10 - i);
  // Calcula o primeiro digito verificador
  resto = (10 * soma) % 11;
  if (resto >= 10) resto = 0;
  if (resto != digito[9]) return false;

  // Calcula a soma ponderada dos 10 primeiros digitos
  soma = 0;
  for (i = 0; i < 10; i++) soma += digito[i] * (11 - i);
  // Calcula o segundo digito verificador
  resto = (10 * soma) % 11;
  if (resto >= 10) resto = 0;
  if (resto != digito[10]) return false;

  return true;
}

void CPF::digitar(void) {
  do {
    cout << "11 digitos? ";
    cin >> CpF;
  } while (!valido());
}

void CPF::ler(istream &I) {
  I >> CpF;
  if (!valido()) CpF = 0;
}

ostream &CPF::imprimir(ostream &O) const {
  O << CpF;
  return O;
}

// UMA CLASSE PARA ARMAZENAR DADOS PESSOAIS DE INDIVIDUOS (NOME, CPF, DATA DE
// NASCIMENTO)

class Pessoa {
 private:
  string nome;
  CPF cpf;
  Data nascimento;

 public:
  inline Pessoa() : nome(""), cpf(), nascimento() {}

  inline bool valido() const {
    return (nome != "" && cpf.valido() && nascimento.valido());
  }

  void digitar(void);
  void ler(istream &I);
  ostream &imprimir(ostream &O) const;
};
inline ostream &operator<<(ostream &O, const Pessoa &P) {
  return P.imprimir(O);
}

void Pessoa::digitar(void) {
  // Leitura do nome
  cout << "Nome?\n";
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');  // Sobra ENTER da leitura anterior
  getline(cin, nome, '\n');
  // Leitura do CPF
  cout << "CPF?\n";
  cpf.digitar();
  // Leitura da data de nascimento
  cout << "Data de nascimento?\n";
  nascimento.digitar();
}

void Pessoa::ler(istream &I) {
  // Leitura do CPF
  cpf.ler(I);
  I.ignore(numeric_limits<streamsize>::max(), ';');

  // Leitura do nome
  I.ignore(numeric_limits<streamsize>::max(), '"');
  getline(I, nome, '"');
  I.ignore(numeric_limits<streamsize>::max(), ';');

  // Leitura da data de nascimento
  nascimento.ler(I);
  I.ignore(numeric_limits<streamsize>::max(), '\n');
}

ostream &Pessoa::imprimir(ostream &O) const {
  O << cpf;
  O << ';';

  O << '"' << nome << '"';
  O << ';';

  O << nascimento;
  O << endl;

  return O;
}

int main(void) {
  unsigned N;
  Pessoa *X;
  int opcao;
  string nome_arquivo;

  // ENTRADA DE DADOS
  do {
    cout << "Como deseja entrar os dados?\n";
    cout << "1 - Do teclado\n";
    cout << "2 - De um arquivo\n";
    cin >> opcao;
  } while (opcao < 1 || opcao > 2);

  if (opcao == 1) {
    do {
      cout << "Quantas pessoas? ";
      cin >> N;
    } while (N <= 0);
    X = new Pessoa[N];
    for (unsigned i = 0; i < N; i++) {
      X[i].digitar();
    }
  } else {
    cout << "Nome do arquivo (sem espacos)? \n";
    cin >> nome_arquivo;  // Pode usar >> porque o nome do arquivo nao contem
                          // espacos
    ifstream arq(nome_arquivo.c_str());
    if (arq.is_open()) {
      string prov;
      arq >> prov;
      if (prov != "LISTA_PESSOAS") {
        cerr << "Arquivo com cabecalho invalido\n";
      } else {
        arq >> N;
        if (N <= 0) {
          cerr << "Arquivo com numero de pessoas invalido\n";
        } else {
          X = new Pessoa[N];
          for (unsigned i = 0; i < N; i++) {
            X[i].ler(arq);
            if (!X[i].valido()) {
              cerr << "Arquivo com Pessoa(s) invalida(s)\n";
              delete[] X;
              N = 0;  // Tambem faz sair do for
            }
          }
        }
      }
      arq.close();
    } else {
      cerr << "Erro na abertura do arquivo " << nome_arquivo
           << " para leitura\n";
    }
  }

  // SAIDA DE DADOS
  do {
    cout << "Como deseja sair os dados?\n";
    cout << "1 - Em tela\n";
    cout << "2 - Em um arquivo\n";
    cin >> opcao;
  } while (opcao < 1 || opcao > 2);

  if (opcao == 1) {
    cout << "Lista de pessoas:\n";
    for (unsigned i = 0; i < N; i++) {
      cout << X[i];
    }
  } else {
    cout << "Nome do arquivo (sem espacos)? \n";
    cin >> nome_arquivo;  // Pode usar >> porque o nome do arquivo nao contem
                          // espacos
    ofstream arq(nome_arquivo.c_str());
    if (arq.is_open()) {
      cout << "Escrevendo no arquivo " << nome_arquivo << ":\n";
      arq << "LISTA_PESSOAS " << N << endl;
      for (unsigned i = 0; i < N; i++) {
        arq << X[i];
      }
      arq.close();
    } else {
      cerr << "Erro na abertura do arquivo " << nome_arquivo
           << " para escrita\n";
    }
  }

  return 0;
}
