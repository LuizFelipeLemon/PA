#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include "novo_circuito.h"
//#include "circuito.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNovo_changed();

    void on_actionNovo_triggered();

private:
    Ui::MainWindow *ui;
    Novo_circuito novo_circuito;
    QLabel NumIn;     // Exibe o numero de entradas do circuito na barra de status
    QLabel NumOut;    // Exibe o numero de saidas do circuito na barra de status
    QLabel NumPortas; // Exibe o numero de portas do circuito na barra de status
            // Caixa de dialogo para criar um novo circuito
    //Circuito C;
};

#endif // MAINWINDOW_H
