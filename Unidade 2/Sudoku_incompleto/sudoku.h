#ifndef _SUDOKU_H_
#define _SUDOKU_H_
#include <stdint.h>
#include <queue>

using namespace std;

/// Classe que representa uma possivel jogada (coordenadas e valor)
/// Significado dos valores:
/*
 \ i | i de 0-8 | i<0 | i>8 e j>=0 |
  \j |    e     | ou  |     ou     |
 v \ | j de 0-8 | j<0 | j>8 e i>=0 |
-----+----------+-----+------------+
1 a 9|   JOGAR  | FIM |  RESOLVER  |
  0  |  APAGAR  | FIM | PREENCHER  |
 > 9 |   NOVO   | FIM |   VOLTAR   |
 < 0 |    FIM   | FIM |     FIM    |
*/
class Jogada
{
private:
  int i,j,v;
public:
  /// Construtor (por default, cria Jogada que termina o jogo)
  Jogada(int I=-1, int J=-1, int V=-1);
  /// Funcoes de acesso
  inline int linha() const {return i;}
  inline int coluna() const {return j;}
  inline int valor() const {return v;}
  /// Testa se a jogada indica que uma casa deve ser preenchida
  inline bool jogada() const {return (i>=0 && i<=8 && j>=0 && j<=8 && v>=1 && v<=9);}
  /// Testa se a jogada indica que uma casa deve ser apagada
  inline bool apagamento() const {return (i>=0 && i<=8 && j>=0 && j<=8 && v==0);}
  /// Testa se a jogada indica que o uruario quer resolver o jogo automaticamente
  inline bool resolver_jogo() const {return ( ((i>8 && j>=0) || (i>=0 && j>8)) && v>=1 && v<=9 );}
  /// Testa se a jogada indica que o uruario quer preencher as casas faceis
  inline bool preencher_jogo() const {return ( ((i>8 && j>=0) || (i>=0 && j>8)) && v==0 );}
  /// Testa se a jogada indica que o uruario quer comecar um novo jogo
  inline bool novo() const {return (i>=0 && i<=8 && j>=0 && j<=8 && v>9);}
  /// Testa se a jogada indica que o uruario quer recomecar (voltar ao tab inicial)
  inline bool voltar() const {return (((i>8 && j>=0) || (i>=0 && j>8)) && v>9);}
  /// Testa se a jogada indica que o uruario quer encerrar o jogo
  inline bool fim_de_jogo() const {return (i<0 || j<0 || v<0);}

  /// Fixa as coordenadas de uma jogada
  void setCell(int I, int J);
  /// Fixa o valor de uma jogada
  void setValue(int V);

  /// Leh uma jogada do teclado
  /// ESSE METODO ENVOLVE FORMATACAO.
  /// O codigo deve ser diferente de acordo com o modo de exibicao
  /// Sua implementacao estah no arquivo sudoku_form_*
  void ler();

  friend class Sudoku;
};

class Sudoku
{
private:
  /// Matriz que contem os valores das casas do tabuleiro
  uint8_t x[9][9];
  /// Calcula o valor possivel para preencher a casa (i,j)
  /// utilizando apenas as regras "faceis" (linha, coluna e bloco)
  /// Se houver mais de uma possibilidade de preenchimento, retorna 0 (zero)
  /// Se houver uma unica possibilidade de preenchimento, retorna o valor (1 a 9)
  /// Se nao houver nenhuma possibilidade de preenchimento, retorna <0, o que
  /// indica que o tabuleiro nao tem solucao
  int calcular_possibilidades(int i, int j) const;
public:
  /// Limpa o tabuleiro
  void limpar();
  /// Gera um novo tabuleiro
  void gerar();
  /// Cria um tabuleiro vazio
  inline Sudoku() {limpar();}
  /// Cria um tabuleiro com o conteudo do arquivo nome_arq
  /// Caso nao consiga ler do arquivo, retorna tabuleiro gerado
  /// automaticamente (caso erro ocorra logo no inicio da funcao
  /// de leitura) ou lido parcialmente, caso contrario
  Sudoku(const char *nome_arq);
  /// Operador () de consulta
  /// Retorna o i-j-esimo elemento do tabuleiro
  uint8_t operator()(int i, int j) const;
  /// Compara se dois tabuleiros sao iguais
  bool operator==(const Sudoku &S) const;
  /// Testa se a jogada J eh possivel para o tabuleiro
  bool jogada_valida(Jogada J) const;
  /// Testa se a jogada J eh um apagamento valido de uma casa para o tabuleiro,
  /// levando em conta o tabuleiro original (nao eh permitido apagar casas que
  /// estavam preenchidas no tabuleiro original)
  bool apagamento_valido(Jogada J, const Sudoku &Origem) const;
  /// Executa uma jogada (altera o tabuleiro)
  inline void fazer_jogada(Jogada J) {if (jogada_valida(J)) x[J.i][J.j] = J.v;}
  /// Apaga uma casa (altera o tabuleiro)
  inline void apagar_jogada(Jogada J, const Sudoku &O) {if (apagamento_valido(J,O)) x[J.i][J.j] = J.v;}
  /// Testa se o tabuleiro estah completo (fim de jogo)
  bool fim_de_jogo() const;
  /// Retorna o numero de casas vazias no tabuleiro
  unsigned num_casas_vazias() const;
  /// Preenche todas as casas "faceis" do tabuleiro, ou seja, aquelas que tem um
  /// unico valor possivel pelas regras do Sudoku
  /// Retorna o numero de casas adicionais preenhidas (0 ou >0) ou entao
  /// retorna <0 se houver alguma casa sem possibilidade de jogada (tabuleiro insoluvel)
  /// Quando retorna um valor negativo (ou seja, o tabuleiro eh insoluvel), o numero
  /// retornado serah o negativo do numero de casas preenchidas. Caso nenhuma casa
  /// tenha sido preeenchida e o tabuleiro seja insoluvel, serah retornado um numero
  /// negativo menor que -81.
  int resolver_casas_faceis();
  /// Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
  /// O parametro com_exibicao controla se o algoritmo deve (true) ou nao (false)
  /// exibir os tabuleiros analisados e o numero de nohs durante o algoritmo
  /// Retorna true se foi encontrada solucao
  bool resolver(bool com_exibicao=true);

  /// OS 3 METODOS A SEGUIR ENVOLVEM FORMATACAO.
  /// O codigo deve ser diferente de acordo com o modo de exibicao
  /// Sua implementacao estah no arquivo sudoku_form_*

  /// Exibir o conteudo do tabuleiro atual
  void exibir() const;
  /// Exibir o conteudo do tabuleiro inicial
  void exibir_origem() const;
  /// Exibe os numeros de tabuleiros gerados, testados e a analisar
  void exibir_andamento(unsigned Ntab_testados, unsigned Ntab_gerados, unsigned Ntab_analisar) const;

};

#endif // _SUDOKU_H_
