/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QFrame *line;
    QPushButton *start;
    QPushButton *falha;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *stop;
    QPushButton *sent;
    QLabel *label_6;
    QPushButton *pare;
    QLabel *label_7;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(660, 584);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-20, -10, 691, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        line = new QFrame(Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 661, 20));
        line->setLineWidth(4);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        start = new QPushButton(Dialog);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(30, 260, 101, 91));
        start->setStyleSheet(QString::fromUtf8(""));
        start->setIconSize(QSize(101, 91));
        start->setAutoDefault(false);
        start->setFlat(true);
        falha = new QPushButton(Dialog);
        falha->setObjectName(QString::fromUtf8("falha"));
        falha->setGeometry(QRect(30, 70, 101, 91));
        falha->setStyleSheet(QString::fromUtf8(""));
        falha->setIconSize(QSize(101, 91));
        falha->setAutoDefault(false);
        falha->setFlat(true);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 240, 151, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 50, 161, 20));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 390, 131, 61));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        lcdNumber->setPalette(palette);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 360, 121, 20));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(540, 50, 111, 41));
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        stop = new QPushButton(Dialog);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(540, 90, 101, 91));
        stop->setStyleSheet(QString::fromUtf8(""));
        stop->setIconSize(QSize(101, 91));
        stop->setAutoDefault(false);
        stop->setFlat(true);
        sent = new QPushButton(Dialog);
        sent->setObjectName(QString::fromUtf8("sent"));
        sent->setGeometry(QRect(20, 200, 93, 31));
        sent->setStyleSheet(QString::fromUtf8(""));
        sent->setIconSize(QSize(91, 31));
        sent->setCheckable(false);
        sent->setChecked(false);
        sent->setAutoDefault(false);
        sent->setFlat(true);
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 170, 141, 16));
        label_6->setFont(font1);
        pare = new QPushButton(Dialog);
        pare->setObjectName(QString::fromUtf8("pare"));
        pare->setGeometry(QRect(30, 480, 101, 91));
        pare->setIconSize(QSize(101, 91));
        pare->setAutoDefault(false);
        pare->setFlat(true);
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 460, 121, 16));
        label_7->setFont(font1);

        retranslateUi(Dialog);

        falha->setDefault(false);
        sent->setDefault(false);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "PAINEL DE ACIONAMENTO DE MOTORES", nullptr));
        start->setText(QString());
        falha->setText(QString());
        label_2->setText(QCoreApplication::translate("Dialog", "Start Motor A", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Falha Motor A", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "RPM Motor A", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Parada de Emerg\303\252ncia", nullptr));
        stop->setText(QString());
        sent->setText(QString());
        label_6->setText(QCoreApplication::translate("Dialog", "Sentido Motor A", nullptr));
        pare->setText(QString());
        label_7->setText(QCoreApplication::translate("Dialog", "STOP Motor A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
