#ifndef TOOL_H
#define TOOL_H
#include <QTextCodec>
#include <QListWidgetItem>
#include <QtNetwork>
#include <QWidget>
#include <stdlib.h>
#include <QDebug>
#include <QMap>
#include <QVector>
#include <QTcpServer>
#include <QMessageBox>
#include <QUdpSocket>
#include <QTcpSocket>
namespace Ui {
    class Tool;
}

class Tool : public QWidget
{
    Q_OBJECT

public:
    explicit Tool(QWidget *parent = 0);
    ~Tool();
public slots:
    void updatelist();
    void on_Exit_clicked();
    void on_Clear_clicked();
    void on_ListenTcp_clicked();
    void on_ListenUdp_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void outPut();
    void newTcpConnect();
    void newTcpCreate();
    void onSocketError(QAbstractSocket::SocketError s);
    void on_SendTcp_clicked();
    void on_Init_clicked();
    void on_SendUdp_clicked();
    void on_CreateTcp_clicked();
    void on_LocalIp_clicked();
    void on_help_clicked();
    //void on_sendfile_clicked();
    //void on_openfile_clicked();
private:
    Ui::Tool *ui;
    QByteArray buff;
    QMap<QString,QTcpSocket*> tcpsocket;
    QMap<QString,QUdpSocket *> udpsocket;
    QMap<QString,QTcpServer *> tcpserver;
};
inline void Tool::on_Exit_clicked()
{
    exit(1);
}
#endif // TOOL_H
