#include <iostream>
#include <cstdlib>
#include "sudoku.h"
#include "sudoku_form.h"

using namespace std;

int main(void)
{
  Sudoku Origem("sudoku.txt"),S(Origem);
  Jogada J;

  exibir_cabecalho();

  Origem.exibir_origem();
  S.exibir();

  do
  {
    do
    {
      J.ler();
    } while(!J.jogada() && !J.apagamento() &&
            !J.resolver_jogo() && !J.preencher_jogo() &&
            !J.novo() && !J.voltar() &&
            !J.fim_de_jogo());
    if (J.jogada())
    {
      S.fazer_jogada(J);
    }
    if (J.apagamento())
    {
      S.apagar_jogada(J,Origem);
    }
    if (J.preencher_jogo())
    {
      S.exibir_origem();
      int N = S.resolver_casas_faceis();
      S.exibir();
      exibir_preenchidas(N);
      Origem.exibir_origem();
    }
    if (J.resolver_jogo())
    {
      S.exibir_origem();
      S.resolver();
      exibir_resposta();
      Origem.exibir_origem();
    }
    if (J.novo())
    {
      Origem.gerar();
      S=Origem;
      Origem.exibir_origem();
    }
    if (J.voltar())
    {
      S = Origem;
    }
    S.exibir();
    if (!J.fim_de_jogo() && S.fim_de_jogo())
    {
      exibir_congratulacoes();
    }
  } while(!J.fim_de_jogo());

  encerra_exibicao();
}
