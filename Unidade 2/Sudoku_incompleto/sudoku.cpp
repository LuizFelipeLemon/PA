#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <fstream>
#include <string>
#include <stack>
#include <time.h>

#include "sudoku.h"

using namespace std;

/**********************************************************
 * CLASSE JOGADA                                          *
 **********************************************************/

/// Construtor (por default, cria Jogada que termina o jogo)
Jogada::Jogada(int I, int J, int V)
{
    setCell(I,J);
    setValue(V);
}

/// Fixa as coordenadas de uma jogada
/// Por default, cria Jogada que termina o jogo
void Jogada::setCell(int I, int J)
{
    if (I<0 || I>8) I=-1;
    if (J<0 || J>8) J=-1;
    i = I;
    j = J;
}

/// Fixa o valor de uma jogada
/// Por default, cria Jogada que termina o jogo
void Jogada::setValue(int V)
{
    if (V<0 || V>9) V=-1;
    v = V;
}

/**********************************************************
 * CLASSE SUDOKU                                          *
 **********************************************************/

/// Limpa o tabuleiro
void Sudoku::limpar()
{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    x[i][j] = 0;
  }
}

/// Gera um novo tabuleiro preenchido de maneira aleatoria em algumas casas
/// Esse algoritmo nao eh otimizado, no sentido que nao hah garantia de que
/// o tabuleiro gerado tenha solucao unica nem que seja minimo, ou seja, nao
/// haja outras pedras que pudessem ser removidas permanecendo com a mesma
/// solucao unica.
/// ATENCAO: esse metodo soh funciona se o metodo resolver estiver funcionando
void Sudoku::gerar()
{
  int i,j,k,n;
  srand(time(NULL));

  // Gera um tabuleiro vazio
  Sudoku completo;

  // Preenche os 3 blocos da diagonal principal
  for (n=0; n<3; n++)
  {
    // A ordem em que os numeros serao colocados no bloco
    int ordem[] = {1,2,3,4,5,6,7,8,9};
    // Faz 10 permutacoes aleatorias no vetor ordem
    for (k=0; k<10; k++)
    {
        i = rand()%9;
        j = rand()%9;
        swap(ordem[i],ordem[j]);
    }
    // Coloca os numeros no bloco
    for (i=0; i<3; i++) for (j=0; j<3; j++)
    {
        completo.x[3*n+i][3*n+j] = ordem[3*i+j];
    }
  }

  if (!completo.resolver(false))
  {
      // Tem um erro grande no programa!
      // Nao conseguiu resolver um tabuleiro consistente!!!
      return;
  }

  // Inicializa o melhor tabuleiro como sendo o completo
  // Em seguida, inicia um laco:
  // Remove uma casa do melhor tabuleiro e verifica se foi
  // encontrada a mesma solucao (completo)
  // Refaz esse procedimento ateh que tente 5 vezes consecutivas
  // remover e nao consiga mais a mesma solucao
  Sudoku melhor(completo);
  Sudoku atual,teste;

  n = 0;
  do
  {
      atual = melhor;
      // Elimina uma pedra aleatoria
      do
      {
        i = rand()%9;
        j = rand()%9;
      } while (atual.x[i][j]==0);
      atual.x[i][j]=0;
      // Tenta resolver o atual
      teste = atual;
      teste.resolver(false);
      if (teste == completo)
      {
        melhor = atual;
        n=0;
      }
      else n++;
  } while (n<5);

  // Por fim, tenta remover todas as pedras de forma sistematica
  // (nao aleatoria). Remove todas aquelas para as quais a solucao
  // encontrada apos remocao seja a mesma antes da remocao (completo)
  for (i=0; i<9; i++) for (j=0; j<9; j++) if (melhor.x[i][j] != 0)
  {
      atual = melhor;
      // Elimina a pedra i,j
      atual.x[i][j]=0;
      // Tenta resolver o atual
      teste = atual;
      teste.resolver(false);
      if (teste == completo)
      {
        melhor = atual;
      }
  }

  *this = melhor;
}

/// Cria um tabuleiro com o conteudo do arquivo nome_arq
/// Caso nao consiga ler do arquivo, retorna tabuleiro gerado
/// automaticamente (caso erro ocorra logo no inicio da funcao
/// de leitura) ou lido parcialmente, caso contrario
Sudoku::Sudoku(const char *nome_arq)
{
  // Inicialmente gera tabuleiro aleatorio
  // Se der erro, o tabuleiro ficarah assim
  gerar();

  // Le o tabuleiro inicial de arquivo
  ifstream arq(nome_arq);
  if (!arq.is_open()) return;

  string prov;
  int valor;

  arq >> prov;
  if (prov != "SUDOKU") return;

  // Limpa o tabuleiro e leh as pedras do arquivo
  limpar();
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    arq >> valor;
    if (valor != 0)
    {
      Jogada J(i,j,valor);
      if (jogada_valida(J)) x[i][j] = valor;
    }
  }
  arq.close();
}

/// Operador () de consulta
/// Retorna o i-j-esimo elemento do tabuleiro
uint8_t Sudoku::operator()(int i, int j) const
{
  if (i<0 || i>8 || j<0 || j>8) return 255;
  return x[i][j];
}

/// Compara se dois tabuleiros sao iguais
bool Sudoku::operator==(const Sudoku &S) const
{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (x[i][j] != S.x[i][j]) return false;
  }
  return true;
}

/// Testa se a jogada J eh possivel para o tabuleiro
bool Sudoku::jogada_valida(Jogada J) const
{
  unsigned i,j;
  // Testar a jogada
  if (!J.jogada()) return false;

  // Testar se a casa nao estah vazia
  if (x[J.i][J.j] != 0) return false;

  // Testar a linha
  for (i=0; i<9; i++)
  {
    if (x[i][J.j] == J.v) return false;
  }
  // Testar a coluna
  for (j=0; j<9; j++)
  {
    if (x[J.i][j] == J.v) return false;
  }
  // Testar o bloco
  unsigned iIni = 3*(J.i/3);
  unsigned jIni = 3*(J.j/3);
  for (i=0; i<3; i++) for (j=0; j<3; j++)
  {
    if (x[iIni+i][jIni+j] == J.v) return false;
  }
  return true;
}

/// Testa se a jogada J eh um apagamento valido de uma casa para o tabuleiro,
/// levando em conta o tabuleiro original (nao eh permitido apagar casas que
/// estavam preenchidas no tabuleiro original)
bool Sudoku::apagamento_valido(Jogada J, const Sudoku &Origem) const
{
  // Testar a jogada
  if (!J.apagamento()) return false;

  // Testar se a casa estah vazia
  if (x[J.i][J.j] == 0) return false;

  // Testar se a casa do tabuleiro original nao estah vazia
  if (Origem.x[J.i][J.j] != 0) return false;

  return true;
}

/// Testa se o tabuleiro estah completo (fim de jogo)
bool Sudoku::fim_de_jogo() const
{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (x[i][j] == 0) return false;
  }
  return true;
}

/// Retorna o numero de casas vazias no tabuleiro
unsigned Sudoku::num_casas_vazias() const
{
  unsigned N(0);
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (x[i][j] == 0) N++;
  }
  return N;
}

/// Calcula o valor possivel para preencher a casa (i,j)
/// utilizando apenas as regras "faceis" (linha, coluna e bloco)
/// Se houver mais de uma possibilidade de preenchimento, retorna 0
/// Se houver uma unica possibilidade de preenchimento, retorna o valor
/// Se nao houver nenhuma possibilidade de preenchimento, retorna <0
int Sudoku::calcular_possibilidades(int i, int j) const
{
  // A principio, todos os 9 valores de jogada sao possiveis
  bool valor_possivel[]={true,true,true,true,true,true,true,true,true};
  unsigned ii,I,jj,J,k;

  // Se a casa jah estiver preenchida, nao hah nenhuma possibilidade
  if (x[i][j]!=0) return -1;

  // Varre a linha
  for (k=0; k<9; k++)
  {
    if (x[i][k]>0) valor_possivel[x[i][k]-1] = false;
  }
  // Varre a coluna
  for (k=0; k<9; k++)
  {
    if (x[k][j]>0) valor_possivel[x[k][j]-1] = false;
  }
  // Varre a quadra
  I = 3*(i/3);
  J = 3*(j/3);
  for (ii=0; ii<3; ii++) for (jj=0; jj<3; jj++)
  {
    if (x[I+ii][J+jj]>0) valor_possivel[x[I+ii][J+jj]-1] = false;
  }
  // Conta o numero de valores possiveis
  unsigned num_possivel=0;
  for (k=0; k<9; k++)
  {
    if (valor_possivel[k]) num_possivel++;
  }
  // Nao hah nenhum valor possivel
  if (num_possivel == 0) return -1;
  // Hah mais de um valor possivel
  if (num_possivel > 1) return 0;
  // Hah uma unica possibilidade de preenchimento da casa
  // Retorna o valor possivel
  k = 0;
  while (!valor_possivel[k]) k++;
  return k+1;
}

/// Preenche todas as casas "faceis" do tabuleiro, ou seja, aquelas que tem um
/// unico valor possivel pelas regras do Sudoku
/// Retorna o numero de casas adicionais preenhidas (0 ou >0) ou entao
/// retorna <0 se houver alguma casa sem possibilidade de jogada (tabuleiro insoluvel)
/// Quando retorna um valor negativo (ou seja, o tabuleiro eh insoluvel), o numero
/// retornado serah o negativo do numero de casas preenchidas. Caso nenhuma casa
/// tenha sido preeenchida e o tabuleiro seja insoluvel, serah retornado um numero
/// negativo menor que -81.
int Sudoku::resolver_casas_faceis()
{
  unsigned num_casas=0;
  bool insoluvel(false),resolveu_alguma;
  unsigned i,j;
  int valor;

  do
  {
    resolveu_alguma = false;
    for (i=0; i<9; i++) for (j=0; j<9; j++) if (x[i][j]==0)
    {
      valor = calcular_possibilidades(i,j);
      if (valor < 0)
      {
        // Hah uma casa na qual nenhum valor eh possivel
        // O tabuleiro nao tem solucao
        insoluvel = true;
      }
      if (valor > 0)
      {
        x[i][j] = valor;
        resolveu_alguma = true;
        num_casas++;
      }
    }
  } while (resolveu_alguma);
  if (insoluvel)
  {
      if (num_casas==0) return -666;
      return (-num_casas);
  }
  return num_casas;
}

/// Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
/// O parametro com_exibicao controla se o algoritmo deve (true) ou nao (false)
/// exibir os tabuleiros analisados e o numero de nohs durante o algoritmo
/// Retorna true se foi encontrada solucao

///
/// ATENCAO: ESSE ALGORITMO NAO EH O CORRETO!!!
/// Eh apenas um exemplo, que tenta resolver o problema aleatoriamente
/// Voces devem substituir pelo seu proprio algoritmo
///

bool Sudoku::resolver(bool com_exibicao)
{
  // Reinicializa o gerador de numeros aleatorios
  srand(time(NULL));

  // Contadores do numero de tabuleiros gerados e testados
  int num_tab_gerados(1), num_tab_testados(1);

  // Testa se jah nao estah resolvido desde o inicio
  if (this->fim_de_jogo()) return true;

  // Melhor serah o tabuleiro encontrado com mais casas preenchidas
  Sudoku Melhor(*this);
  // Numero de casas vazias do melhor tabuleiro ateh agora
  int num_vazias_melhor = Melhor.num_casas_vazias();

  // O tabuleiro em analise
  // Comeca a busca a partir do tabuleiro inicial
  Sudoku S(*this);
  // Numero de casas vazias do tabuleiro em analise
  int num_vazias;

  bool achou_solucao;
  int i,j,k;

  do
  {
    // Preenche aleatoriamente uma casa vazia em S
    // Sorteia uma casa vazia
    do
    {
      i = rand()%9;
      j = rand()%9;
    } while (S.x[i][j] != 0);

    // Sorteia um valor de jogada para a casa
    // Se soh houver um valor possivel, nao faz sorteio e joga esse valor
    Jogada J(i,j);
    // Calcula a(s) possibilidades de jogada na casa (i,j)
    k = S.calcular_possibilidades(i,j);
    if (k<0)
    {
      // Tabuleiro S nao tem solucao
      J.setValue(-1); // Jogada invalida
    }
    else if (k==0)
    {
      // Existe mais de uma possibilidade de jogada
      // Escolhe aleatoriamente
      do
      {
        J.setValue(1+rand()%9);
      } while (!S.jogada_valida(J));
    }
    else
    {
      // Soh existe uma possibilidade de jogada
      J.setValue(k);
    }

    if (!S.jogada_valida(J))
    {
      // Tabuleiro em analise tem uma casa sem possibilidade de preenchimento
      // Nao eh possivel gerar um novo tabuleiro a partir dele
      // Recomeca a busca a partir do tabuleiro inicial
      S = *this;
    }
    else
    {
      S.fazer_jogada(J);
      num_tab_gerados++;

      // Calcula quantas casas faltam no tabuleiro
      num_vazias = S.num_casas_vazias();
      if (num_vazias < num_vazias_melhor)
      {
        Melhor = S;
        num_vazias_melhor = num_vazias;
      }
      // Testa se o tabuleiro eh solucao
      achou_solucao = (num_vazias == 0);
      num_tab_testados++;

      // Exibe o andamento do algoritmo de resolucao
      if (com_exibicao)
      {
        // Exibe o tabuleiro que foi gerado e testado
        S.exibir();
        // O terceiro parametro eh o numero de nos gerados mas ainda nao testados;
        // nesse algoritmo incorreto, eh sempre zero
        S.exibir_andamento(num_tab_testados, num_tab_gerados, 0);
      }
    }
    // Para ao encontrar uma solucao ou ao atingir o numero maximo de nos
  } while(!achou_solucao && num_tab_gerados<1000);

  if (achou_solucao) *this = Melhor;
  if (com_exibicao)
  {
    Melhor.exibir();
  }
  return achou_solucao;
}
