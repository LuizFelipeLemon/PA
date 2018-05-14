#include <iostream>
#include <windows.h>
#include "console.h"

// Para mais informacoes sobre impressao formatada no console:
// https://msdn.microsoft.com/pt-br/library/windows/desktop/mt638032(v=vs.85).aspx

// Necessario para que os comandos de console funcionem
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

using namespace std;

// Uma variavel global para representar o terminal
Console Term;

// Coloca o terminal do Windows no modo que permite comando
// Faz form=true se OK; form=false em caso de erro
Console::Console(void)
{
  form = false;
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hOut == INVALID_HANDLE_VALUE) return;

  DWORD dwMode = 0;
  if (!GetConsoleMode(hOut, &dwMode)) return;

  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  if (!SetConsoleMode(hOut, dwMode)) return;

  form = true;
}

// Apaga a tela
void Console::clrscr() const
{
  if (!form) return;
  cout << "\x1b[1;1H";
  cout << "\x1b[23";
}

// Posiciona o cursos nas coordenadas desejadas
void Console::gotoYX(int I, int J) const
{
  if (!form) return;
  cout << "\x1b[" << I << ";" << J << "H";
}

// Delete linha
void Console::limpar_linha() const
{
  if (!form) return;
  cout << "\x1b[1M";
}

// Muda para o modo de desenho de linhas
// Nesse modo, alguns caracteres sao impressos como blocos de linhas
// adequados para fazer molduras:
//   lqqqwqqqk
//   x   x   x
//   tqqqnqqqu
//   x   x   x
//   mqqqvqqqj
void Console::modo_linhas() const
{
  if (!form) return;
  cout << "\x1b(0";
}

// Retorna para o modo normal (texto)
void Console::modo_texto() const
{
  if (!form) return;
  cout << "\x1b(B";
}

// Fixa as cores da frente e do fundo do texto
void Console::cores(CONSOLE_CORES F, CONSOLE_CORES B) const
{
  if (!form) return;

  int cF, cB;
  switch (F)
  {
  default:
  case CONSOLE_DEFAULT:
    cF = 39;
    break;
  case CONSOLE_BLACK:
    cF = 30;
    break;
  case CONSOLE_RED:
    cF = 31;
    break;
  case CONSOLE_GREEN:
    cF = 32;
    break;
  case CONSOLE_YELLOW:
    cF = 33;
    break;
  case CONSOLE_BLUE:
    cF = 34;
    break;
  case CONSOLE_MAGENTA:
    cF = 35;
    break;
  case CONSOLE_CYAN:
    cF = 36;
    break;
  case CONSOLE_WHITE:
    cF = 37;
    break;
  case CONSOLE_BRIGHT_BLACK:
    cF = 90;
    break;
  case CONSOLE_BRIGHT_RED:
    cF = 91;
    break;
  case CONSOLE_BRIGHT_GREEN:
    cF = 92;
    break;
  case CONSOLE_BRIGHT_YELLOW:
    cF = 93;
    break;
  case CONSOLE_BRIGHT_BLUE:
    cF = 94;
    break;
  case CONSOLE_BRIGHT_MAGENTA:
    cF = 95;
    break;
  case CONSOLE_BRIGHT_CYAN:
    cF = 96;
    break;
  case CONSOLE_BRIGHT_WHITE:
    cF = 97;
    break;
  }

  switch (B)
  {
  default:
  case CONSOLE_DEFAULT:
    cB = 49;
    break;
  case CONSOLE_BLACK:
    cB = 40;
    break;
  case CONSOLE_RED:
    cB = 41;
    break;
  case CONSOLE_GREEN:
    cB = 42;
    break;
  case CONSOLE_YELLOW:
    cB = 43;
    break;
  case CONSOLE_BLUE:
    cB = 44;
    break;
  case CONSOLE_MAGENTA:
    cB = 45;
    break;
  case CONSOLE_CYAN:
    cB = 46;
    break;
  case CONSOLE_WHITE:
    cB = 47;
    break;
  case CONSOLE_BRIGHT_BLACK:
    cB = 100;
    break;
  case CONSOLE_BRIGHT_RED:
    cB = 101;
    break;
  case CONSOLE_BRIGHT_GREEN:
    cB = 102;
    break;
  case CONSOLE_BRIGHT_YELLOW:
    cB = 103;
    break;
  case CONSOLE_BRIGHT_BLUE:
    cB = 104;
    break;
  case CONSOLE_BRIGHT_MAGENTA:
    cB = 105;
    break;
  case CONSOLE_BRIGHT_CYAN:
    cB = 106;
    break;
  case CONSOLE_BRIGHT_WHITE:
    cB = 107;
    break;
  }
  cout << "\x1b[" << cF << ';' << cB << "m";
}

// Nao exibe o cursor na tela
void Console::ocultar_cursor() const
{
  if (!form) return;
  cout << "\x1b[?25l";
}

// Exibe o cursor na tela
void Console::exibir_cursor() const
{
  if (!form) return;
  cout << "\x1b[?25h";
}

// Muda para a tela alternativa
// O conteudo original da tela que havia quando o programa foi iniciado
// retornarah quando o programa for encerrado
void Console::tela_alternativa() const
{
  if (!form) return;
  cout << "\x1b[?1049h";
}

// Volta para a tela normal;
// Retorna o conteudo que havia na tela antes do programa ser executado
void Console::tela_normal() const
{
  if (!form) return;
  cout << "\x1b[?1049l";
}
