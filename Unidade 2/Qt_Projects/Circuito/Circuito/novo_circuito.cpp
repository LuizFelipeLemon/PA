#include "novo_circuito.h"
#include "ui_novo_circuito.h"
#include "circuito.h"

extern Circuito C;

Novo_circuito::Novo_circuito(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Novo_circuito)
{
    ui->setupUi(this);
    this->setWindowTitle("Novo Circuito");

}

Novo_circuito::~Novo_circuito()
{
    delete ui;
}



void Novo_circuito::on_buttonBox_accepted()
{
    C.limpar();
    //C.set
}
