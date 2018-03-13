#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Cria o tipo "pixel"
typedef uint8_t pixel;

// Cria o tipo "Imagem"
struct Imagem
{
  unsigned NL,NC;
  pixel **px;
};

#define ALTURA_LINHA 25

Imagem novaImagem(unsigned Ncol, unsigned Nlin);
void deletaImagem(Imagem &I);

void desenhaEstrela(Imagem &I, unsigned lin, unsigned col);
Imagem reduzImagem(const Imagem &I);
void salvaImagem(const Imagem &I, const char *nome);

int main (void)
{
    Imagem original;
    Imagem reduzida;
    unsigned num_linha, i, j, l, c;

    original = novaImagem(24*ALTURA_LINHA, 13*ALTURA_LINHA);
    for (i=0; i<original.NL; i++) for (j=0; j<original.NC; j++)
    {
        if (i<7*ALTURA_LINHA && j<10*ALTURA_LINHA)
        {
            original.px[i][j] = 127;  // BLUE
        }
        else
        {
            num_linha = i/ALTURA_LINHA;
            if (num_linha%2 == 0)
            {
                original.px[i][j] = 196;  // RED
            }
            else
            {
                original.px[i][j] = 255;  // WHITE
            }
        }
    }
    for (l=0; l<5; l++)
    {
        i = round(7.0*ALTURA_LINHA/5.0)*(l+0.5);
        for (c=0; c<6; c++)
        {
            j = round(10.0*ALTURA_LINHA/6.0)*(c+0.5);
            desenhaEstrela(original, i, j);
        }
        if (l>0)
        {
            i = round(7.0*ALTURA_LINHA/5.0)*l;
            for (c=0; c<5; c++)
            {
                j = round(10.0*ALTURA_LINHA/6.0)*(c+1.0);
                desenhaEstrela(original, i, j);
            }
        }
    }
    salvaImagem(original, "imagemBig.pgm");
    cout << "Arquivo imagemBig.pgm salvo!\n";

    reduzida = reduzImagem(original);

    salvaImagem(reduzida, "imagemSmall.pgm");
    cout << "Arquivo imagemSmall.pgm salvo!\n";

    deletaImagem(original);
    deletaImagem(reduzida);
}

// Aloca memoria para uma imagem cuja dimensao eh passada como parametro
Imagem novaImagem(unsigned Ncol, unsigned Nlin)
{
    Imagem novaI;

    novaI.NL = Nlin;
    novaI.NC = Ncol;
    novaI.px = new pixel*[Nlin];
    for(unsigned i=0;i<Nlin;i++) novaI.px[i] = new pixel[Ncol];
    return novaI;
}

// Libera memoria de uma imagem que nao serah mais utilizada
void deletaImagem(Imagem &I)
{
    for (unsigned i=0; i<I.NL; i++) delete[] I.px[i];
    delete I.px;
    I.px = NULL;
    I.NC = I.NL = 0;
}

// Desenha uma estrela na imagem, nas coordenadas lin,col
void desenhaEstrela(Imagem &I, unsigned lin, unsigned col)
{
    const unsigned RAIO_ESTRELA = round(ALTURA_LINHA/3.0);
    const unsigned LARGURA_BRACO_ESTRELA = round(ALTURA_LINHA/6.0);
    float teta;
    int i,j,k,l,largura,m;
    // Desenha os 5 bracos da estrela
    for (unsigned k=0; k<5; k++)
    {
        teta = k*(2.0*M_PI/5.0);
        for (l=0; l<RAIO_ESTRELA; l++)
        {
            largura = LARGURA_BRACO_ESTRELA*(RAIO_ESTRELA-1.0-l)/(RAIO_ESTRELA-1.0);
            for (m=-largura; m<=largura; m++)
            {
                i = round(-l*cos(teta)+m*sin(teta));
                j = round(+l*sin(teta)+m*cos(teta));
                i += lin;
                j += col;
                I.px[i][j] = 255;
            }
        }
    }
}

// Retorna uma nova imagem correspondente aa imagem original reduzida pela metade
Imagem reduzImagem(const Imagem &I)
{
    Imagem O;
    unsigned i,j;

    O.NC = I.NC/2;
    O.NL = I.NL/2;
    O.px = new pixel*[O.NL];

    for(i=0;i<O.NL;i++) O.px[i] = new pixel[O.NC];

    for(i=0;i<O.NL;i++)
    {
        for(j=0;j<O.NC;j++)
        {
            O.px[i][j] = ((int)I.px[2*i][2*j] + I.px[2*i+1][2*j] + I.px[2*i][2*j+1] + I.px[2*i+1][2*j+1])/4;
        }
    }
    return O;
}

// Salva a imagem no formato PGM
void salvaImagem(const Imagem &I, const char *nome)
{
    ofstream f(nome);

    f << "P2\n";
    f << I.NC << ' ' << I.NL << endl;
    f << (unsigned)255 << endl;
    for (unsigned i=0; i<I.NL; i++)
    {
        for (unsigned j=0; j<I.NC; j++)
        {
            f << (unsigned)I.px[i][j] << ' ';
        }
        f << endl;
    }
    f.close();
}
