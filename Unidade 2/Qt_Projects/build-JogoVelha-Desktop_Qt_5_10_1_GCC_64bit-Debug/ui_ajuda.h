/********************************************************************************
** Form generated from reading UI file 'ajuda.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUDA_H
#define UI_AJUDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Ajuda
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Ajuda)
    {
        if (Ajuda->objectName().isEmpty())
            Ajuda->setObjectName(QStringLiteral("Ajuda"));
        Ajuda->resize(300, 200);
        verticalLayout = new QVBoxLayout(Ajuda);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(Ajuda);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        buttonBox = new QDialogButtonBox(Ajuda);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Ajuda);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ajuda, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ajuda, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ajuda);
    } // setupUi

    void retranslateUi(QDialog *Ajuda)
    {
        Ajuda->setWindowTitle(QApplication::translate("Ajuda", "Dialog", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("Ajuda", "JOGO DA VELHA - Qt\n"
"\n"
"Este aplicativo \303\251 um programa did\303\241tico, para aprendizado da biblioteca Qt em C++.\n"
"\n"
"Se voc\303\252 n\303\243o conhece o Jogo da Velha, ou n\303\243o se lembra das regras, inicialmente preciso perguntar: de qual planeta voc\303\252 veio? Brincadeiras \303\240 parte, procure na internet sobre esse jogo. Ele \303\251 disputado por duas pessoas, uma identificada por 'X' e a outra por 'O'.\n"
"\n"
"Quanto a esse aplicativo, para jogar \303\251 s\303\263 dar um duplo clique na casa que voc\303\252 quer preencher: ela receber\303\241 a marca do jogador da vez, e a oportunidade de jogar passa para o outro jogador.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajuda: public Ui_Ajuda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUDA_H
