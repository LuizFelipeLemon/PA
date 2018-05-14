/********************************************************************************
** Form generated from reading UI file 'sudoku.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKU_H
#define UI_SUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sudoku
{
public:
    QAction *actionReiniciar;
    QAction *actionNovo;
    QAction *actionPreencher_Imediatas;
    QAction *actionResolver;
    QAction *actionSair;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTableWidget *atual;
    QLabel *label_3;
    QTableWidget *inicial;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *linha_3;
    QLabel *coluna_3;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *jogar_3;
    QMenuBar *menuBar;
    QMenu *menuSudoku;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sudoku)
    {
        if (Sudoku->objectName().isEmpty())
            Sudoku->setObjectName(QStringLiteral("Sudoku"));
        Sudoku->resize(600, 464);
        actionReiniciar = new QAction(Sudoku);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        actionNovo = new QAction(Sudoku);
        actionNovo->setObjectName(QStringLiteral("actionNovo"));
        actionPreencher_Imediatas = new QAction(Sudoku);
        actionPreencher_Imediatas->setObjectName(QStringLiteral("actionPreencher_Imediatas"));
        actionResolver = new QAction(Sudoku);
        actionResolver->setObjectName(QStringLiteral("actionResolver"));
        actionSair = new QAction(Sudoku);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        centralWidget = new QWidget(Sudoku);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(600, 420));
        centralWidget->setMaximumSize(QSize(600, 420));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 590, 390));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(271, 20));
        label_4->setMaximumSize(QSize(271, 20));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(271, 20));
        label_2->setMaximumSize(QSize(271, 20));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(271, 20));
        label->setMaximumSize(QSize(271, 20));

        horizontalLayout_3->addWidget(label);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(271, 20));
        label_5->setMaximumSize(QSize(271, 20));

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        atual = new QTableWidget(verticalLayoutWidget);
        if (atual->columnCount() < 9)
            atual->setColumnCount(9);
        if (atual->rowCount() < 9)
            atual->setRowCount(9);
        atual->setObjectName(QStringLiteral("atual"));
        atual->setMinimumSize(QSize(272, 272));
        atual->setMaximumSize(QSize(272, 272));
        atual->setShowGrid(true);
        atual->setRowCount(9);
        atual->setColumnCount(9);
        atual->horizontalHeader()->setVisible(false);
        atual->horizontalHeader()->setDefaultSectionSize(30);
        atual->horizontalHeader()->setHighlightSections(false);
        atual->horizontalHeader()->setMinimumSectionSize(30);
        atual->verticalHeader()->setVisible(false);
        atual->verticalHeader()->setDefaultSectionSize(30);
        atual->verticalHeader()->setHighlightSections(false);
        atual->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout->addWidget(atual);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(16, 272));
        label_3->setMaximumSize(QSize(16, 272));

        horizontalLayout->addWidget(label_3);

        inicial = new QTableWidget(verticalLayoutWidget);
        if (inicial->columnCount() < 9)
            inicial->setColumnCount(9);
        if (inicial->rowCount() < 9)
            inicial->setRowCount(9);
        inicial->setObjectName(QStringLiteral("inicial"));
        inicial->setMinimumSize(QSize(272, 272));
        inicial->setMaximumSize(QSize(272, 272));
        inicial->setShowGrid(true);
        inicial->setRowCount(9);
        inicial->setColumnCount(9);
        inicial->horizontalHeader()->setVisible(false);
        inicial->horizontalHeader()->setDefaultSectionSize(30);
        inicial->horizontalHeader()->setHighlightSections(false);
        inicial->horizontalHeader()->setMinimumSectionSize(30);
        inicial->verticalHeader()->setVisible(false);
        inicial->verticalHeader()->setDefaultSectionSize(30);
        inicial->verticalHeader()->setHighlightSections(false);
        inicial->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout->addWidget(inicial);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        linha_3 = new QLabel(verticalLayoutWidget);
        linha_3->setObjectName(QStringLiteral("linha_3"));
        linha_3->setMinimumSize(QSize(70, 20));
        linha_3->setMaximumSize(QSize(70, 20));

        verticalLayout_7->addWidget(linha_3);

        coluna_3 = new QLabel(verticalLayoutWidget);
        coluna_3->setObjectName(QStringLiteral("coluna_3"));
        coluna_3->setMinimumSize(QSize(70, 20));
        coluna_3->setMaximumSize(QSize(70, 20));

        verticalLayout_7->addWidget(coluna_3);


        horizontalLayout_4->addLayout(verticalLayout_7);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_6);

        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimumSize(QSize(75, 25));
        spinBox_3->setMaximumSize(QSize(75, 25));
        spinBox_3->setMaximum(9);

        horizontalLayout_4->addWidget(spinBox_3);

        horizontalSpacer_6 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(80, 18));

        horizontalLayout_4->addWidget(pushButton_4);

        horizontalSpacer_10 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        jogar_3 = new QPushButton(verticalLayoutWidget);
        jogar_3->setObjectName(QStringLiteral("jogar_3"));
        jogar_3->setMaximumSize(QSize(80, 18));

        horizontalLayout_4->addWidget(jogar_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        Sudoku->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Sudoku);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuSudoku = new QMenu(menuBar);
        menuSudoku->setObjectName(QStringLiteral("menuSudoku"));
        Sudoku->setMenuBar(menuBar);
        statusBar = new QStatusBar(Sudoku);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Sudoku->setStatusBar(statusBar);

        menuBar->addAction(menuSudoku->menuAction());
        menuSudoku->addAction(actionReiniciar);
        menuSudoku->addAction(actionNovo);
        menuSudoku->addAction(actionPreencher_Imediatas);
        menuSudoku->addAction(actionResolver);
        menuSudoku->addSeparator();
        menuSudoku->addAction(actionSair);

        retranslateUi(Sudoku);

        QMetaObject::connectSlotsByName(Sudoku);
    } // setupUi

    void retranslateUi(QMainWindow *Sudoku)
    {
        Sudoku->setWindowTitle(QApplication::translate("Sudoku", "Sudoku", nullptr));
        actionReiniciar->setText(QApplication::translate("Sudoku", "Reiniciar", nullptr));
        actionNovo->setText(QApplication::translate("Sudoku", "Novo", nullptr));
        actionPreencher_Imediatas->setText(QApplication::translate("Sudoku", "Preencher Imediatas", nullptr));
        actionResolver->setText(QApplication::translate("Sudoku", "Resolver", nullptr));
        actionSair->setText(QApplication::translate("Sudoku", "Sair", nullptr));
        label_4->setText(QApplication::translate("Sudoku", "TABULEIRO ATUAL", nullptr));
        label_2->setText(QApplication::translate("Sudoku", "TABULEIRO INICIAL", nullptr));
        label->setText(QApplication::translate("Sudoku", "  1     2      3      4      5      6      7      8      9", nullptr));
        label_5->setText(QApplication::translate("Sudoku", "     1       2      3      4      5       6      7       8     9", nullptr));
        label_3->setText(QApplication::translate("Sudoku", "<html><head/><body><p>A</p><p>B</p><p>C</p><p>D</p><p>E</p><p>F</p><p>G</p><p>H</p><p>I</p></body></html>", nullptr));
        linha_3->setText(QApplication::translate("Sudoku", "Linha:       ?", nullptr));
        coluna_3->setText(QApplication::translate("Sudoku", "Coluna:    ?", nullptr));
        label_6->setText(QApplication::translate("Sudoku", "VALOR:", nullptr));
        spinBox_3->setSpecialValueText(QApplication::translate("Sudoku", "Apagar", nullptr));
        pushButton_4->setText(QApplication::translate("Sudoku", "COTINUAR", nullptr));
        jogar_3->setText(QApplication::translate("Sudoku", "JOGAR", nullptr));
        menuSudoku->setTitle(QApplication::translate("Sudoku", "Sudoku", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sudoku: public Ui_Sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
