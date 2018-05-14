#include "mainjogovelha.h"
#include "ui_mainjogovelha.h"
#include "jogovelha.h"

#include <QPainter>
#include <QPen>

MainJogoVelha::MainJogoVelha(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainJogoVelha),
    Img(40, 40),
    ImgX(40, 40),
    ImgO(40, 40),
    NumX("-"),
    NumO("-")
{
    ui->setupUi(this);

    // Preenche as imagens uma cor de fundo
    QColor corDeFundo(255,255,200);
    Img.fill(corDeFundo);
    ImgX.fill(corDeFundo);
    ImgO.fill(corDeFundo);

    // Desenha as imagens do X e do O
    QPen pen;
    QPainter painter;

    // X vermelho
    pen.setWidth(3);
    pen.setColor(Qt::red);
    painter.begin(&ImgX);
    painter.setPen(pen);
    painter.drawLine(10,10, 29,29);
    painter.drawLine(10,29, 29,10);
    painter.end();

    // O preto
    pen.setWidth(3);
    pen.setColor(Qt::blue);
    painter.begin(&ImgO);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(20,20), 12, 12);
    painter.end();

    // Fixa o comportamento de selecao do jogo da velha
    ui->jogoVelha->setSelectionMode(QAbstractItemView::NoSelection);
    ui->jogoVelha->setTabKeyNavigation(false);

    // Cria os widgets QLabel que compoem a tabela do jogo da velha
    // Depois de criado, insere em cada QLabel a imagem correta
    for (int i=0; i<3; i++) for (int j=0; j<3; j++)
    {
        ui->jogoVelha->setCellWidget(i,j,new QLabel);
        exibirImagem(i,j);
    }

    // Exibe as imagens do jogador da vez e do vitorioso
    exibirJogadores();

    // Insere os widgets da barra de status
    statusBar()->insertWidget(0,new QLabel("Jogador X: "));
    statusBar()->insertWidget(1,&NumX);
    statusBar()->insertWidget(2,new QLabel("   Jogador O: "));
    statusBar()->insertWidget(3,&NumO);
    // Exibe os numeros de casas corretos
    exibirNumeroCasas();
}

void MainJogoVelha::exibirImagem(int I, int J)
{
    QLabel *cell = (QLabel*)ui->jogoVelha->cellWidget(I,J);
    switch (JV(I,J))
    {
        case 'X':
            cell->setPixmap(ImgX);
            break;
        case 'O':
            cell->setPixmap(ImgO);
            break;
        case ' ':
        default:
            cell->setPixmap(Img);
            break;
    }
}

void MainJogoVelha::exibirJogadores()
{
    // Imagem do jogador da vez
    if (JV.jogadorVez() == 'X') ui->imgVez->setPixmap(ImgX);
    else if (JV.jogadorVez() == 'O') ui->imgVez->setPixmap(ImgO);
    else ui->imgVez->setPixmap(Img);

    // Imagem do jogador vitorioso
    if (JV.vencedor() == 'X') ui->imgVencedor->setPixmap(ImgX);
    else if (JV.vencedor() == 'O') ui->imgVencedor->setPixmap(ImgO);
    else ui->imgVencedor->setPixmap(Img);
}

void MainJogoVelha::exibirNumeroCasas()
{
    NumX.setText(QString::number(JV.numX()));
    NumO.setText(QString::number(JV.numO()));
}

MainJogoVelha::~MainJogoVelha()
{
    delete ui;
}

void MainJogoVelha::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

void MainJogoVelha::on_jogoVelha_doubleClicked(const QModelIndex &index)
{
    int I = index.row();
    int J = index.column();
    if (JV.jogadaValida(I,J))
    {
        JV.fazerJogada(I,J);
        exibirImagem(I,J);
    }
    exibirJogadores();
    exibirNumeroCasas();
}

void MainJogoVelha::on_actionReiniciar_triggered()
{
    JV.reiniciar();
    for (int i=0; i<3; i++) for (int j=0; j<3; j++)
    {
        exibirImagem(i,j);
    }
    exibirJogadores();
    exibirNumeroCasas();
}

void MainJogoVelha::on_actionExibir_ajuda_triggered()
{
    help.show();
}
