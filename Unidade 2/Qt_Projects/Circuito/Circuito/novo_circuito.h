#ifndef NOVO_CIRCUITO_H
#define NOVO_CIRCUITO_H

#include <QDialog>

namespace Ui {
class Novo_circuito;
}

class Novo_circuito : public QDialog
{
    Q_OBJECT

public:
    explicit Novo_circuito(QWidget *parent = 0);
    ~Novo_circuito();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Novo_circuito *ui;
};

#endif // NOVO_CIRCUITO_H
