/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serialport
{
public:
    QPushButton *back_pushButton;

    void setupUi(QWidget *Serialport)
    {
        if (Serialport->objectName().isEmpty())
            Serialport->setObjectName(QString::fromUtf8("Serialport"));
        Serialport->resize(800, 600);
        back_pushButton = new QPushButton(Serialport);
        back_pushButton->setObjectName(QString::fromUtf8("back_pushButton"));
        back_pushButton->setGeometry(QRect(640, 530, 131, 31));

        retranslateUi(Serialport);

        QMetaObject::connectSlotsByName(Serialport);
    } // setupUi

    void retranslateUi(QWidget *Serialport)
    {
        Serialport->setWindowTitle(QApplication::translate("Serialport", "Form", 0, QApplication::UnicodeUTF8));
        back_pushButton->setText(QApplication::translate("Serialport", "back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Serialport: public Ui_Serialport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
