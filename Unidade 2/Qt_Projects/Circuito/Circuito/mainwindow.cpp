#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "novo_circuito.h"
#include "circuito.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

extern Circuito C;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    novo_circuito(this),
    NumIn(this),
    NumOut(this) ,
    NumPortas(this)
{


    ui->setupUi(this);
    this->setWindowTitle("Simulador de Circuitos Digitais");

    ui->tablePortas->setHorizontalHeaderLabels(QStringList() << "TIPO" << "Nº\nENTR"
                                               << "ENTR\n1" << "ENTR\n2" << "ENTR\n3" << "ENTR\n4");
    ui->tableSaidas->setHorizontalHeaderLabels(QStringList() << "ORIG\nSAÍDA");


    statusBar()->insertWidget(0,new QLabel("N° entradas: "));
    statusBar()->insertWidget(1,&NumIn);
    statusBar()->insertWidget(2,new QLabel("   Nº saídas: "));
    statusBar()->insertWidget(3,&NumOut);
    statusBar()->insertWidget(4,new QLabel("   Nº portas: "));
    statusBar()->insertWidget(5,&NumPortas);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNovo_triggered()
{
    novo_circuito.show();
}

void MainWindow::on_actionNovo_changed()
{

}

void MainWindow::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        //ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            //stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }

}



void MainWindow::on_actionSair_triggered()
{

}
