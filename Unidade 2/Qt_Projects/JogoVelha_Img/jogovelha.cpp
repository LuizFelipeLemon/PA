#include "jogovelha.h"

JogoVelha::JogoVelha()
{
    reiniciar();
}

void JogoVelha::reiniciar()
{
    for (int i=0; i<3; i++) for (int j=0; j<3; j++)
    {
        x[i][j] = ' ';  // Espaco = casa vazia;
    }
    vez = 'X'; // Sempre comeca com o jogador X
    venc = ' '; // Nenhum vencedor
}

// Retorna o conteudo da casa <I,J>
char JogoVelha::operator()(int I, int J) const
{
    // Checa os indices
    if (I<0 || I>=3 || J<0 || J>=3) return '?';

    return x[I][J];
}

// Retorna numero de casas X
int JogoVelha::numX() const
{
    int N(0);
    for (int i=0; i<3; i++) for (int j=0; j<3; j++)
    {
        if (x[i][j] == 'X') N++;
    }
    return N;
}

// Retorna numero de casas O
int JogoVelha::numO() const
{
    int N(0);
    for (int i=0; i<3; i++) for (int j=0; j<3; j++)
    {
        if (x[i][j] == 'O') N++;
    }
    return N;
}

// Retorna true se alguem ganhou
// Se teste for positivo, altera venc e vez <- ' '
bool JogoVelha::vitoria()
{
    for (int k=0; k<3; k++)
    {
        // Testa as linhas
        if ((x[k][0]=='X' || x[k][0]=='O') &&
             x[k][1]==x[k][0] && x[k][2]==x[k][0] )
        {
            venc = x[k][0];
            vez = ' ';
            return true;
        }
        // Testa as colunas
        if ((x[0][k]=='X' || x[0][k]=='O') &&
             x[1][k]==x[0][k] && x[2][k]==x[0][k] )
        {
            venc = x[0][k];
            vez = ' ';
            return true;
        }
    }
    // Testa as diagonais
    if ((x[1][1]=='X' || x[1][1]=='O') &&
        ( (x[0][0]==x[1][1] && x[2][2]==x[1][1]) ||
          (x[0][2]==x[1][1] && x[2][0]==x[1][1]) ))
    {
        venc = x[1][1];
        vez = ' ';
        return true;
    }
    // Ninguem venceu
    return false;
}

// Retorna true se nao pode mais ganhar
// (vitoria ou tabuleiro completo)
// Se teste for positivo, vez <- ' '
bool JogoVelha::fimDeJogo()
{
    // Alguem jah ganhou o jogo?
    if (venc == ' ')
    {
        for (int i=0; i<3; i++) for (int j=0; j<3; j++)
        {
            if (x[i][j] == ' ') return false;
        }
    }
    // Jogo acabou: nao tem mais jogador valido
    vez = ' ';
    return true;
}

// Testa se o jogador da vez pode jogar na casa <I,J>
bool JogoVelha::jogadaValida(int I, int J) const
{
    // Alguem jah ganhou o jogo?
    if (venc != ' ') return false;
    // Tem um jogador apto a jogar?
    if (vez!='X' && vez!='O') return false;
    // Checa os indices
    if (I<0 || I>=3 || J<0 || J>=3) return false;
    // Checa se a casa estah vazia
    if (x[I][J] != ' ') return false;

    // Jogada eh valida
    return true;
}

// Coloca a marca do jogador da vez na casa <I,J>
void JogoVelha::fazerJogada(int I, int J)
{
    if (jogadaValida(I,J))
    {
        x[I][J] = vez;
    }
    // Testa se ganhou o jogo
    if (!vitoria() && !fimDeJogo())
    {
        vez = (vez=='O' ? 'X' : 'O');
    }
}
