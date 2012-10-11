/********************************************************************************
** Form generated from reading UI file 'tool.ui'
**
** Created: Fri Feb 17 01:01:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOL_H
#define UI_TOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tool
{
public:
    QLineEdit *TcpPort1;
    QPushButton *Exit;
    QTextBrowser *Display;
    QLabel *label_7;
    QLineEdit *UdpIp2;
    QPushButton *Init;
    QListWidget *listWidget;
    QPushButton *ListenTcp;
    QLineEdit *TcpIp2;
    QTextEdit *TcpInPut;
    QLineEdit *UdpPort2;
    QPushButton *SendUdp;
    QLineEdit *TcpPort2;
    QLineEdit *UdpPort1;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_5;
    QPushButton *ListenUdp;
    QLabel *label_2;
    QLabel *label;
    QPushButton *SendTcp;
    QTextEdit *UdpInPut;
    QLabel *label_11;
    QPushButton *Clear;
    QLabel *label_9;
    QLabel *label_4;
    QPushButton *CreateTcp;
    QLabel *label_6;
    QPushButton *help;
    QComboBox *ActiveTcp;
    QPushButton *LocalIp;
    QPushButton *openfile;
    QPushButton *sendfile;
    QProgressBar *progressBar;

    void setupUi(QWidget *Tool)
    {
        if (Tool->objectName().isEmpty())
            Tool->setObjectName(QString::fromUtf8("Tool"));
        Tool->resize(642, 478);
        Tool->setStyleSheet(QString::fromUtf8(""));
        TcpPort1 = new QLineEdit(Tool);
        TcpPort1->setObjectName(QString::fromUtf8("TcpPort1"));
        TcpPort1->setGeometry(QRect(440, 300, 61, 20));
        Exit = new QPushButton(Tool);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(570, 430, 51, 23));
        Display = new QTextBrowser(Tool);
        Display->setObjectName(QString::fromUtf8("Display"));
        Display->setGeometry(QRect(10, 10, 371, 251));
        label_7 = new QLabel(Tool);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 300, 54, 20));
        UdpIp2 = new QLineEdit(Tool);
        UdpIp2->setObjectName(QString::fromUtf8("UdpIp2"));
        UdpIp2->setGeometry(QRect(60, 400, 121, 20));
        Init = new QPushButton(Tool);
        Init->setObjectName(QString::fromUtf8("Init"));
        Init->setGeometry(QRect(510, 430, 51, 23));
        listWidget = new QListWidget(Tool);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(400, 10, 221, 251));
        ListenTcp = new QPushButton(Tool);
        ListenTcp->setObjectName(QString::fromUtf8("ListenTcp"));
        ListenTcp->setGeometry(QRect(400, 330, 101, 23));
        TcpIp2 = new QLineEdit(Tool);
        TcpIp2->setObjectName(QString::fromUtf8("TcpIp2"));
        TcpIp2->setGeometry(QRect(450, 370, 161, 20));
        TcpInPut = new QTextEdit(Tool);
        TcpInPut->setObjectName(QString::fromUtf8("TcpInPut"));
        TcpInPut->setGeometry(QRect(200, 290, 171, 101));
        UdpPort2 = new QLineEdit(Tool);
        UdpPort2->setObjectName(QString::fromUtf8("UdpPort2"));
        UdpPort2->setGeometry(QRect(60, 430, 51, 20));
        SendUdp = new QPushButton(Tool);
        SendUdp->setObjectName(QString::fromUtf8("SendUdp"));
        SendUdp->setGeometry(QRect(130, 430, 51, 23));
        TcpPort2 = new QLineEdit(Tool);
        TcpPort2->setObjectName(QString::fromUtf8("TcpPort2"));
        TcpPort2->setGeometry(QRect(450, 400, 51, 20));
        UdpPort1 = new QLineEdit(Tool);
        UdpPort1->setObjectName(QString::fromUtf8("UdpPort1"));
        UdpPort1->setGeometry(QRect(560, 300, 61, 20));
        label_12 = new QLabel(Tool);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 260, 71, 16));
        label_8 = new QLabel(Tool);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(400, 280, 111, 16));
        label_5 = new QLabel(Tool);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 280, 111, 16));
        ListenUdp = new QPushButton(Tool);
        ListenUdp->setObjectName(QString::fromUtf8("ListenUdp"));
        ListenUdp->setGeometry(QRect(520, 330, 101, 23));
        label_2 = new QLabel(Tool);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 370, 41, 16));
        label = new QLabel(Tool);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 260, 71, 16));
        SendTcp = new QPushButton(Tool);
        SendTcp->setObjectName(QString::fromUtf8("SendTcp"));
        SendTcp->setGeometry(QRect(320, 430, 51, 23));
        UdpInPut = new QTextEdit(Tool);
        UdpInPut->setObjectName(QString::fromUtf8("UdpInPut"));
        UdpInPut->setGeometry(QRect(10, 290, 171, 101));
        label_11 = new QLabel(Tool);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 430, 54, 12));
        Clear = new QPushButton(Tool);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(130, 260, 51, 23));
        label_9 = new QLabel(Tool);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(400, 400, 54, 12));
        label_4 = new QLabel(Tool);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 400, 41, 16));
        CreateTcp = new QPushButton(Tool);
        CreateTcp->setObjectName(QString::fromUtf8("CreateTcp"));
        CreateTcp->setGeometry(QRect(400, 430, 91, 23));
        label_6 = new QLabel(Tool);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 300, 54, 12));
        help = new QPushButton(Tool);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(570, 400, 51, 23));
        help->setDefault(false);
        help->setFlat(false);
        ActiveTcp = new QComboBox(Tool);
        ActiveTcp->setObjectName(QString::fromUtf8("ActiveTcp"));
        ActiveTcp->setGeometry(QRect(200, 400, 171, 22));
        LocalIp = new QPushButton(Tool);
        LocalIp->setObjectName(QString::fromUtf8("LocalIp"));
        LocalIp->setGeometry(QRect(510, 400, 51, 23));
        openfile = new QPushButton(Tool);
        openfile->setObjectName(QString::fromUtf8("openfile"));
        openfile->setGeometry(QRect(200, 430, 61, 23));
        sendfile = new QPushButton(Tool);
        sendfile->setObjectName(QString::fromUtf8("sendfile"));
        sendfile->setGeometry(QRect(260, 430, 61, 23));
        progressBar = new QProgressBar(Tool);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(270, 260, 101, 23));
        progressBar->setValue(0);

        retranslateUi(Tool);

        QMetaObject::connectSlotsByName(Tool);
    } // setupUi

    void retranslateUi(QWidget *Tool)
    {
        Tool->setWindowTitle(QApplication::translate("Tool", "su\347\232\204\347\275\221\347\273\234\350\260\203\350\257\225\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        Exit->setText(QApplication::translate("Tool", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Tool", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        Init->setText(QApplication::translate("Tool", "\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        ListenTcp->setText(QApplication::translate("Tool", "\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        SendUdp->setText(QApplication::translate("Tool", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Tool", "\345\217\221\351\200\201UDP\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Tool", "TCP\346\234\254\345\234\260\347\253\257\345\217\243\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Tool", "UDP\346\234\254\345\234\260\347\253\257\345\217\243\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        ListenUdp->setText(QApplication::translate("Tool", "\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Tool", "\347\233\256\346\240\207IP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Tool", "\345\217\221\351\200\201TCP\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        SendTcp->setText(QApplication::translate("Tool", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Tool", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        Clear->setText(QApplication::translate("Tool", "\346\270\205\345\261\217", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Tool", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Tool", "\347\233\256\346\240\207IP", 0, QApplication::UnicodeUTF8));
        CreateTcp->setText(QApplication::translate("Tool", "\345\273\272\347\253\213TCP\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Tool", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        help->setText(QApplication::translate("Tool", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        LocalIp->setText(QApplication::translate("Tool", "\346\234\254\345\234\260IP", 0, QApplication::UnicodeUTF8));
        openfile->setText(QApplication::translate("Tool", "\346\211\223\345\274\200\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        sendfile->setText(QApplication::translate("Tool", "\345\217\221\351\200\201\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Tool: public Ui_Tool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOL_H
