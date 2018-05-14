#ifndef _MAINJOGOVELHA_H
#define _MAINJOGOVELHA_H

#include "ajuda.h"

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>

namespace Ui {
class MainJogoVelha;
}

class MainJogoVelha : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainJogoVelha(QWidget *parent = 0);
    ~MainJogoVelha();

private slots:
    void on_actionSair_triggered();

    void on_jogoVelha_doubleClicked(const QModelIndex &index);

    void on_actionReiniciar_triggered();

    void on_actionExibir_ajuda_triggered();

private:
    Ui::MainJogoVelha *ui;
    QPixmap Img;
    QPixmap ImgX;
    QPixmap ImgO;
    QLabel NumX;
    QLabel NumO;

    Ajuda help;

    void exibirJogadores();
    void exibirNumeroCasas();
    void exibirImagem(int I, int J);
};

#endif // _MAINJOGOVELHA_H
