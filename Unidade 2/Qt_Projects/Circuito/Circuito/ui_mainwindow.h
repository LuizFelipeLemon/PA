/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNovo;
    QAction *actionLer;
    QAction *actionSalvar;
    QAction *actionSair;
    QAction *actionGerar_Tabela;
    QWidget *centralWidget;
    QTableWidget *tableSaidas;
    QLabel *labelCircuito_2;
    QLabel *labelPortas;
    QLabel *labelSaidas;
    QTableWidget *tablePortas;
    QTableWidget *tableTabelaVerdade;
    QLabel *labelCircuito;
    QMenuBar *menuBar;
    QMenu *menuCircuito;
    QMenu *menuSimular;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 720);
        MainWindow->setMinimumSize(QSize(0, 0));
        actionNovo = new QAction(MainWindow);
        actionNovo->setObjectName(QStringLiteral("actionNovo"));
        actionLer = new QAction(MainWindow);
        actionLer->setObjectName(QStringLiteral("actionLer"));
        actionSalvar = new QAction(MainWindow);
        actionSalvar->setObjectName(QStringLiteral("actionSalvar"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionGerar_Tabela = new QAction(MainWindow);
        actionGerar_Tabela->setObjectName(QStringLiteral("actionGerar_Tabela"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableSaidas = new QTableWidget(centralWidget);
        if (tableSaidas->columnCount() < 1)
            tableSaidas->setColumnCount(1);
        if (tableSaidas->rowCount() < 1)
            tableSaidas->setRowCount(1);
        tableSaidas->setObjectName(QStringLiteral("tableSaidas"));
        tableSaidas->setGeometry(QRect(306, 44, 86, 551));
        tableSaidas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableSaidas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableSaidas->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableSaidas->setTabKeyNavigation(false);
        tableSaidas->setAlternatingRowColors(true);
        tableSaidas->setSelectionMode(QAbstractItemView::SingleSelection);
        tableSaidas->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableSaidas->setRowCount(1);
        tableSaidas->setColumnCount(1);
        tableSaidas->horizontalHeader()->setDefaultSectionSize(45);
        tableSaidas->horizontalHeader()->setHighlightSections(false);
        tableSaidas->horizontalHeader()->setMinimumSectionSize(25);
        tableSaidas->verticalHeader()->setVisible(true);
        tableSaidas->verticalHeader()->setDefaultSectionSize(25);
        tableSaidas->verticalHeader()->setMinimumSectionSize(20);
        labelCircuito_2 = new QLabel(centralWidget);
        labelCircuito_2->setObjectName(QStringLiteral("labelCircuito_2"));
        labelCircuito_2->setGeometry(QRect(400, -4, 401, 25));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelCircuito_2->setFont(font);
        labelCircuito_2->setFrameShape(QFrame::Box);
        labelCircuito_2->setAlignment(Qt::AlignCenter);
        labelPortas = new QLabel(centralWidget);
        labelPortas->setObjectName(QStringLiteral("labelPortas"));
        labelPortas->setGeometry(QRect(-4, 20, 311, 25));
        labelPortas->setFont(font);
        labelPortas->setFrameShape(QFrame::Box);
        labelPortas->setAlignment(Qt::AlignCenter);
        labelSaidas = new QLabel(centralWidget);
        labelSaidas->setObjectName(QStringLiteral("labelSaidas"));
        labelSaidas->setGeometry(QRect(306, 20, 86, 25));
        labelSaidas->setFont(font);
        labelSaidas->setFrameShape(QFrame::Box);
        labelSaidas->setAlignment(Qt::AlignCenter);
        tablePortas = new QTableWidget(centralWidget);
        if (tablePortas->columnCount() < 6)
            tablePortas->setColumnCount(6);
        if (tablePortas->rowCount() < 1)
            tablePortas->setRowCount(1);
        tablePortas->setObjectName(QStringLiteral("tablePortas"));
        tablePortas->setGeometry(QRect(-4, 44, 311, 551));
        tablePortas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tablePortas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tablePortas->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tablePortas->setTabKeyNavigation(false);
        tablePortas->setAlternatingRowColors(true);
        tablePortas->setSelectionMode(QAbstractItemView::SingleSelection);
        tablePortas->setSelectionBehavior(QAbstractItemView::SelectRows);
        tablePortas->setRowCount(1);
        tablePortas->setColumnCount(6);
        tablePortas->horizontalHeader()->setVisible(true);
        tablePortas->horizontalHeader()->setDefaultSectionSize(45);
        tablePortas->horizontalHeader()->setHighlightSections(false);
        tablePortas->horizontalHeader()->setMinimumSectionSize(25);
        tablePortas->verticalHeader()->setVisible(true);
        tablePortas->verticalHeader()->setDefaultSectionSize(25);
        tablePortas->verticalHeader()->setMinimumSectionSize(20);
        tableTabelaVerdade = new QTableWidget(centralWidget);
        if (tableTabelaVerdade->columnCount() < 4)
            tableTabelaVerdade->setColumnCount(4);
        if (tableTabelaVerdade->rowCount() < 99)
            tableTabelaVerdade->setRowCount(99);
        tableTabelaVerdade->setObjectName(QStringLiteral("tableTabelaVerdade"));
        tableTabelaVerdade->setGeometry(QRect(400, 20, 401, 575));
        tableTabelaVerdade->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableTabelaVerdade->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableTabelaVerdade->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableTabelaVerdade->setTabKeyNavigation(false);
        tableTabelaVerdade->setAlternatingRowColors(true);
        tableTabelaVerdade->setSelectionMode(QAbstractItemView::NoSelection);
        tableTabelaVerdade->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableTabelaVerdade->setRowCount(99);
        tableTabelaVerdade->setColumnCount(4);
        tableTabelaVerdade->horizontalHeader()->setVisible(false);
        tableTabelaVerdade->horizontalHeader()->setDefaultSectionSize(45);
        tableTabelaVerdade->horizontalHeader()->setHighlightSections(false);
        tableTabelaVerdade->horizontalHeader()->setMinimumSectionSize(25);
        tableTabelaVerdade->verticalHeader()->setVisible(false);
        tableTabelaVerdade->verticalHeader()->setDefaultSectionSize(25);
        tableTabelaVerdade->verticalHeader()->setHighlightSections(false);
        labelCircuito = new QLabel(centralWidget);
        labelCircuito->setObjectName(QStringLiteral("labelCircuito"));
        labelCircuito->setGeometry(QRect(-4, -4, 396, 25));
        labelCircuito->setFont(font);
        labelCircuito->setFrameShape(QFrame::Box);
        labelCircuito->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuCircuito = new QMenu(menuBar);
        menuCircuito->setObjectName(QStringLiteral("menuCircuito"));
        menuSimular = new QMenu(menuBar);
        menuSimular->setObjectName(QStringLiteral("menuSimular"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCircuito->menuAction());
        menuBar->addAction(menuSimular->menuAction());
        menuCircuito->addAction(actionNovo);
        menuCircuito->addAction(actionLer);
        menuCircuito->addAction(actionSalvar);
        menuCircuito->addSeparator();
        menuCircuito->addAction(actionSair);
        menuSimular->addAction(actionGerar_Tabela);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNovo->setText(QApplication::translate("MainWindow", "Novo", nullptr));
        actionLer->setText(QApplication::translate("MainWindow", "Ler", nullptr));
        actionSalvar->setText(QApplication::translate("MainWindow", "Salvar", nullptr));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", nullptr));
        actionGerar_Tabela->setText(QApplication::translate("MainWindow", "Gerar Tabela", nullptr));
        labelCircuito_2->setText(QApplication::translate("MainWindow", "TABELA VERDADE", nullptr));
        labelPortas->setText(QApplication::translate("MainWindow", "PORTAS E CONEX\303\225ES", nullptr));
        labelSaidas->setText(QApplication::translate("MainWindow", "SA\303\215DAS", nullptr));
        labelCircuito->setText(QApplication::translate("MainWindow", "CIRCUITO", nullptr));
        menuCircuito->setTitle(QApplication::translate("MainWindow", "Circuito", nullptr));
        menuSimular->setTitle(QApplication::translate("MainWindow", "Simular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
