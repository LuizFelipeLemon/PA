#ifndef _MEU_CONSOLE_WIN_H_
#define _MEU_CONSOLE_WIN_H_

// Para mais informacoes sobre impressao formatada no console:
// https://msdn.microsoft.com/pt-br/library/windows/desktop/mt638032(v=vs.85).aspx

// As cores que o terminal aceita
enum CONSOLE_CORES
{
  CONSOLE_DEFAULT,
  CONSOLE_BLACK,
  CONSOLE_RED,
  CONSOLE_GREEN,
  CONSOLE_YELLOW,
  CONSOLE_BLUE,
  CONSOLE_MAGENTA,
  CONSOLE_CYAN,
  CONSOLE_WHITE,
  CONSOLE_BRIGHT_BLACK,
  CONSOLE_BRIGHT_RED,
  CONSOLE_BRIGHT_GREEN,
  CONSOLE_BRIGHT_YELLOW,
  CONSOLE_BRIGHT_BLUE,
  CONSOLE_BRIGHT_MAGENTA,
  CONSOLE_BRIGHT_CYAN,
  CONSOLE_BRIGHT_WHITE
};

// Uma classe para facilitar a impressao formatada no Windows
// ATENCAO: soh funciona no Windows 10
// O construtor da classe testa se o terminal aceita ou nao impressao formatada
// Caso nao aceite, as funcoes passam a nao fazer nada...
class Console
{
private:
  // true se terminal aceita impressao formatada
  bool form;
public:
  // O construtor faz o teste e determina o valor de form
  Console(void);
  inline bool formatado() const {return form;}
// Apaga a tela
  void clrscr() const;
  // Posiciona o cursos nas coordenadas desejadas
  void gotoYX(int I, int J) const;
  // Apaga a linha da tela onde estah o cursos
  void limpar_linha() const;

  // Muda para o modo de desenho de linhas
  // Nesse modo, alguns caracteres sao impressos como blocos de linhas
  // adequados para fazer molduras:
  //   lqqqwqqqk
  //   x   x   x
  //   tqqqnqqqu
  //   x   x   x
  //   mqqqvqqqj
  void modo_linhas() const;
  // Retorna para o modo normal (texto)
  void modo_texto() const;

  // Fixa as cores das letras e do fundo (background) do texto
  void cores(CONSOLE_CORES F, CONSOLE_CORES B) const;

  // Controla se o cursor eh ou nao exibido na tela
  void ocultar_cursor() const;
  void exibir_cursor() const;

  // Muda para a tela alternativa
  // O conteudo original da tela que havia quando o programa foi iniciado
  // retornarah quando o programa for encerrado
  void tela_alternativa() const;
  // Volta para a tela normal
  // Retorna o conteudo que havia na tela antes do programa ser executado
  void tela_normal() const;
};

// Declara, para os arquivos que incluirem "consele.h", que existe uma
// variavel global do tipo Console chamada Term, declarada em outro arquivo
// Para que nao deh erro de compilacao ao usar Term
extern Console Term;

#endif  // _MEU_CONSOLE_WIN_H_


