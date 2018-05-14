#ifndef _JOGOVELHA_H
#define _JOGOVELHA_H

class JogoVelha
{
private:
    char x[3][3];
    char vez;  // Quem estah na vez de jogar
    char venc; // Quem venceu o jogo
public:
    JogoVelha();
    void reiniciar();
    // Retorna o conteudo da casa <I,J>
    char operator()(int I, int J) const;
    // Retorna quem estah na vez de jogar (' ' se ninguem)
    inline char jogadorVez() const {return vez;}
    // Retorna quem ganhou o jogo (' ' se ninguem)
    inline char vencedor() const {return venc;}
    // Retorna numero de casas X
    int numX() const;
    // Retorna numero de casas O
    int numO() const;
    // Retorna true se alguem ganhou
    // Se teste for positivo, altera venc e vez <- ' '
    bool vitoria();
    // Retorna true se nao pode mais ganhar
    // (vitoria ou tabuleiro completo)
    // Se teste for positivo, vez <- ' '
    bool fimDeJogo();
    // Testa se o jogador da vez pode jogar na casa <I,J>
    bool jogadaValida(int I, int J) const;
    // Coloca a marca do jogador da vez na casa <I,J>
    void fazerJogada(int I, int J);
};

extern JogoVelha JV;

#endif // _JOGOVELHA_H
