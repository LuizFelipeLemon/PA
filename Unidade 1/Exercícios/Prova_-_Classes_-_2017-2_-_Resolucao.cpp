#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ===========================================================================
// A CLASSE VOO
// ===========================================================================

class Voo
{
private:
  unsigned numero;
  string aero_orig, aero_dest;
  unsigned hora_part, hora_cheg;
public:
  inline Voo(): numero(0), aero_orig(""), aero_dest(""), hora_part(0), hora_cheg(0) {}
  inline string getOrigem() const {return aero_orig;}
  friend ostream &operator<<(ostream &O, const Voo &P);
  friend istream &operator>>(istream &I, Voo &P);
};

// Impressao de um voo
ostream &operator<<(ostream &O, const Voo &V)
{
  O << "Voo " << V.numero
    << ": " << V.aero_orig
    << '(' << setfill('0') << setw(4) << V.hora_part << setfill(' ') << setw(0) << ')'
    << "->" << V.aero_dest
    << '(' << setfill('0') << setw(4) << V.hora_cheg << setfill(' ') << setw(0) << ')';
  return O;
}

// Funcao auxiliar para ler, testar e retornar um codigo valido de aeroporto (3 letras)
string ler_codigo_aeroporto()
{
  string codigo;
  bool codigo_valido;
  do
  {
    cout << "Codigo (3 letras): ";
    cin >> codigo;
    codigo_valido = (codigo.size()==3);
    for (unsigned i=0; codigo_valido && i<3; i++)
    {
      codigo[i] = toupper(codigo[i]);
      codigo_valido = (codigo[i]>='A' && codigo[i]<='Z');
    }
  } while (!codigo_valido);
  return codigo;
}

// Funcao auxiliar para ler, testar e retornar um horario valido (0 a 2359)
unsigned ler_horario()
{
  unsigned horario;
  bool horario_valido;
  do
  {
    cout << "Horario (0000 a 2359): ";
    cin >> horario;
    unsigned hora = horario/100;
    unsigned minuto = horario%100;
    horario_valido = (hora>=0 && hora<=23 && minuto>=0 && minuto<=59);
  } while (!horario_valido);
  return horario;
}

// Leitura de um voo
istream &operator>>(istream &I, Voo &V)
{
  do
  {
    cout << "Numero do voo: ";
    cin >> V.numero;
  } while (V.numero<1000 || V.numero>9999);
  bool codigo_valido;
  cout << "Aeroporto de origem: ";
  V.aero_orig = ler_codigo_aeroporto();
  cout << "Partida: ";
  V.hora_part = ler_horario();
  cout << "Aeroporto de destino: ";
  V.aero_dest = ler_codigo_aeroporto();
  cout << "Chegada: ";
  V.hora_cheg = ler_horario();
  return I;
}

// ===========================================================================
// A CLASSE LISTA VOOS
// ===========================================================================

class ListaVoos
{
private:
  unsigned N;
  Voo *x;
  void criar(unsigned numV);
  void copiar(const ListaVoos &L);
  void limpar();
public:
  inline ListaVoos(): N(0), x(NULL) {}
  inline ListaVoos(const ListaVoos &L) {copiar(L);}
  inline ~ListaVoos(void) {limpar();}
  inline void operator=(const ListaVoos &L) {if (this!=&L) {limpar(); copiar(L);}}
  void inserir(const Voo &V);
  void imprimir() const;
  void imprimir(const string &C) const;
};

void ListaVoos::criar(unsigned numV)
{
  N = numV;
  if (N>0) x = new Voo[N];
  else x = NULL;
}

void ListaVoos::copiar(const ListaVoos &L)
{
  criar(L.N);
  // Copia os valores dos Voos
  for (unsigned i=0; i<N; i++) x[i]=L.x[i];
}

void ListaVoos::limpar()
{
  if (x!=NULL) delete[] x;
  N = 0;
  x = NULL;
}

void ListaVoos::inserir(const Voo &V)
{
  Voo *prov = new Voo[N+1];

  for (unsigned i=0; i<N; i++) prov[i]=x[i];
  prov[N] = V;
  if (x!=NULL) delete[] x;
  N++;
  x = prov;
}

void ListaVoos::imprimir() const
{
  for (unsigned i=0; i<N; i++) cout << x[i] << endl;
}

void ListaVoos::imprimir(const string &C) const
{
  for (unsigned i=0; i<N; i++)
  {
    if (x[i].getOrigem()==C) cout << x[i] << endl;
  }
}

// ===========================================================================
// PROGRAMA PRINCIPAL
// ===========================================================================

int main(void)
{
  ListaVoos LV;
  Voo V;
  string codigo;
  int opcao;

  cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VOOS\n";
  do
  {
    do
    {
      cout << "1 - Inserir um novo voo na lista\n";
      cout << "2 - Imprimir todos os voos da lista\n";
      cout << "3 - Procurar um voo a partir da origem\n";
      cout << "0 - Terminar o programa\n";
      cin >> opcao;
    } while (opcao<0 || opcao>3);
    switch (opcao)
    {
    case 1:
      cout << "Voo a ser inserido: ";
      cin >> V;
      LV.inserir(V);
      break;
    case 2:
      LV.imprimir();
      break;
    case 3:
      cout << "Aeroporto de origem a pesquisar: ";
      codigo = ler_codigo_aeroporto();
      LV.imprimir(codigo);
      break;
    default:
      break;
    }
  } while (opcao!=0);
  return 0;
}
