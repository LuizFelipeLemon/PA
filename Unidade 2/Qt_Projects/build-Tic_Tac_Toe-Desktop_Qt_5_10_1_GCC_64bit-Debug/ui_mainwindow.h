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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReiniciar;
    QAction *actionSair;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *jogoVelha;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuJogo;
    QMenu *menuAjuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionReiniciar = new QAction(MainWindow);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        jogoVelha = new QTableWidget(centralWidget);
        if (jogoVelha->columnCount() < 3)
            jogoVelha->setColumnCount(3);
        if (jogoVelha->rowCount() < 3)
            jogoVelha->setRowCount(3);
        jogoVelha->setObjectName(QStringLiteral("jogoVelha"));
        jogoVelha->setMaximumSize(QSize(137, 137));
        jogoVelha->setRowCount(3);
        jogoVelha->setColumnCount(3);
        jogoVelha->horizontalHeader()->setVisible(false);
        jogoVelha->horizontalHeader()->setDefaultSectionSize(45);
        jogoVelha->horizontalHeader()->setMinimumSectionSize(45);
        jogoVelha->verticalHeader()->setVisible(false);
        jogoVelha->verticalHeader()->setDefaultSectionSize(45);
        jogoVelha->verticalHeader()->setMinimumSectionSize(45);

        horizontalLayout->addWidget(jogoVelha);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(45, 45));
        label_2->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(45, 45));
        label->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 17));
        menuJogo = new QMenu(menuBar);
        menuJogo->setObjectName(QStringLiteral("menuJogo"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuJogo->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuJogo->addAction(actionReiniciar);
        menuJogo->addAction(actionSair);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionReiniciar->setText(QApplication::translate("MainWindow", "Reiniciar", nullptr));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Jogador da Vez", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Vencedor", nullptr));
        label->setText(QString());
        menuJogo->setTitle(QApplication::translate("MainWindow", "Jogo", nullptr));
        menuAjuda->setTitle(QApplication::translate("MainWindow", "Ajuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
