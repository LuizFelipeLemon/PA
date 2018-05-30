/********************************************************************************
** Form generated from reading UI file 'novo_circuito.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVO_CIRCUITO_H
#define UI_NOVO_CIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Novo_circuito
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Novo_circuito)
    {
        if (Novo_circuito->objectName().isEmpty())
            Novo_circuito->setObjectName(QStringLiteral("Novo_circuito"));
        Novo_circuito->resize(244, 190);
        Novo_circuito->setLayoutDirection(Qt::LeftToRight);
        widget = new QWidget(Novo_circuito);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 202, 147));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximumSize(QSize(48, 26));

        horizontalLayout_2->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox_3 = new QSpinBox(widget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximumSize(QSize(48, 26));

        horizontalLayout_3->addWidget(spinBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Novo_circuito);
        QObject::connect(buttonBox, SIGNAL(accepted()), Novo_circuito, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Novo_circuito, SLOT(reject()));

        QMetaObject::connectSlotsByName(Novo_circuito);
    } // setupUi

    void retranslateUi(QDialog *Novo_circuito)
    {
        Novo_circuito->setWindowTitle(QApplication::translate("Novo_circuito", "Dialog", nullptr));
        label->setText(QApplication::translate("Novo_circuito", "N\303\272mero de Entradas:", nullptr));
        label_2->setText(QApplication::translate("Novo_circuito", "N\303\272mero de Sa\303\255das:", nullptr));
        label_3->setText(QApplication::translate("Novo_circuito", "N\303\272mero de Portas:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Novo_circuito: public Ui_Novo_circuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVO_CIRCUITO_H
