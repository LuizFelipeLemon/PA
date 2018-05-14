/********************************************************************************
** Form generated from reading UI file 'mainjogovelha.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINJOGOVELHA_H
#define UI_MAINJOGOVELHA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainJogoVelha
{
public:
    QAction *actionReiniciar;
    QAction *actionSair;
    QAction *actionExibir_ajuda;
    QWidget *centralWidget;
    QTableWidget *jogoVelha;
    QLabel *jogadorVez;
    QLabel *imgVez;
    QLabel *jogadorVencedor;
    QLabel *imgVencedor;
    QMenuBar *menuBar;
    QMenu *menuReiniciar;
    QMenu *menuAjuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainJogoVelha)
    {
        if (MainJogoVelha->objectName().isEmpty())
            MainJogoVelha->setObjectName(QStringLiteral("MainJogoVelha"));
        MainJogoVelha->resize(280, 184);
        actionReiniciar = new QAction(MainJogoVelha);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        actionSair = new QAction(MainJogoVelha);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionExibir_ajuda = new QAction(MainJogoVelha);
        actionExibir_ajuda->setObjectName(QStringLiteral("actionExibir_ajuda"));
        centralWidget = new QWidget(MainJogoVelha);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        jogoVelha = new QTableWidget(centralWidget);
        if (jogoVelha->columnCount() < 3)
            jogoVelha->setColumnCount(3);
        if (jogoVelha->rowCount() < 3)
            jogoVelha->setRowCount(3);
        jogoVelha->setObjectName(QStringLiteral("jogoVelha"));
        jogoVelha->setGeometry(QRect(20, 10, 122, 122));
        jogoVelha->setCornerButtonEnabled(false);
        jogoVelha->setRowCount(3);
        jogoVelha->setColumnCount(3);
        jogoVelha->horizontalHeader()->setVisible(false);
        jogoVelha->horizontalHeader()->setDefaultSectionSize(40);
        jogoVelha->horizontalHeader()->setHighlightSections(false);
        jogoVelha->horizontalHeader()->setMinimumSectionSize(40);
        jogoVelha->verticalHeader()->setVisible(false);
        jogoVelha->verticalHeader()->setDefaultSectionSize(40);
        jogoVelha->verticalHeader()->setHighlightSections(false);
        jogoVelha->verticalHeader()->setMinimumSectionSize(40);
        jogadorVez = new QLabel(centralWidget);
        jogadorVez->setObjectName(QStringLiteral("jogadorVez"));
        jogadorVez->setGeometry(QRect(190, 5, 81, 16));
        imgVez = new QLabel(centralWidget);
        imgVez->setObjectName(QStringLiteral("imgVez"));
        imgVez->setGeometry(QRect(190, 23, 40, 40));
        imgVez->setFrameShape(QFrame::Box);
        jogadorVencedor = new QLabel(centralWidget);
        jogadorVencedor->setObjectName(QStringLiteral("jogadorVencedor"));
        jogadorVencedor->setGeometry(QRect(190, 76, 47, 13));
        imgVencedor = new QLabel(centralWidget);
        imgVencedor->setObjectName(QStringLiteral("imgVencedor"));
        imgVencedor->setGeometry(QRect(190, 92, 40, 40));
        imgVencedor->setFrameShape(QFrame::Box);
        MainJogoVelha->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainJogoVelha);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 280, 21));
        menuReiniciar = new QMenu(menuBar);
        menuReiniciar->setObjectName(QStringLiteral("menuReiniciar"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        MainJogoVelha->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainJogoVelha);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainJogoVelha->setStatusBar(statusBar);

        menuBar->addAction(menuReiniciar->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuReiniciar->addAction(actionReiniciar);
        menuReiniciar->addSeparator();
        menuReiniciar->addAction(actionSair);
        menuAjuda->addAction(actionExibir_ajuda);

        retranslateUi(MainJogoVelha);

        QMetaObject::connectSlotsByName(MainJogoVelha);
    } // setupUi

    void retranslateUi(QMainWindow *MainJogoVelha)
    {
        MainJogoVelha->setWindowTitle(QApplication::translate("MainJogoVelha", "Jogo da Velha", Q_NULLPTR));
        actionReiniciar->setText(QApplication::translate("MainJogoVelha", "Reiniciar", Q_NULLPTR));
        actionSair->setText(QApplication::translate("MainJogoVelha", "Sair", Q_NULLPTR));
        actionExibir_ajuda->setText(QApplication::translate("MainJogoVelha", "Exibir ajuda...", Q_NULLPTR));
        jogadorVez->setText(QApplication::translate("MainJogoVelha", "Jogador da vez:", Q_NULLPTR));
        imgVez->setText(QString());
        jogadorVencedor->setText(QApplication::translate("MainJogoVelha", "Vencedor:", Q_NULLPTR));
        imgVencedor->setText(QString());
        menuReiniciar->setTitle(QApplication::translate("MainJogoVelha", "Jogo", Q_NULLPTR));
        menuAjuda->setTitle(QApplication::translate("MainJogoVelha", "Ajuda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainJogoVelha: public Ui_MainJogoVelha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINJOGOVELHA_H
