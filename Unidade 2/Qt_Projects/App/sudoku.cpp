#include "sudoku.h"
#include "ui_sudoku.h"

Sudoku::Sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sudoku)
{
    ui->setupUi(this);
}

Sudoku::~Sudoku()
{
    delete ui;
}
