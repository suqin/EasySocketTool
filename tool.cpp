#include "tool.h"
#include "ui_tool.h"

Tool::Tool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tool)
{

    ui->setupUi(this);
    ui->Display->setTabStopWidth(50);
    ui->sendfile->hide();
    ui->progressBar->hide();
    /////////////////////////����ѡ��////////////////////////////////////
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-32"));
    ///////////////////////////////////////////////////////////////////////////////
    on_help_clicked();
}
////////////////////////////////////////////////////////////////
//��ʼ�����ú�����
////////////////////////////////////////////////////////////////
void Tool::on_Init_clicked()
{
    ui->listWidget->clear();
    ui->ActiveTcp->clear();
    QMapIterator<QString,QUdpSocket *> iUdp(udpsocket);
    while(iUdp.hasNext())
    {
       iUdp.next();
       iUdp.value()->deleteLater();
       udpsocket.remove(iUdp.key());
    }
    QMapIterator<QString,QTcpSocket *> iTcp(tcpsocket);
    while(iTcp.hasNext())
    {
       iTcp.next();
       iTcp.value()->deleteLater();
       tcpsocket.remove(iTcp.key());
    }
    QMapIterator<QString,QTcpServer *> iTcpServer(tcpserver);
    while(iTcpServer.hasNext())
    {
       iTcpServer.next();
       iTcpServer.value()->deleteLater();
       tcpserver.remove(iTcpServer.key());
    }
    ui->Display->clear();
}
void Tool::on_Clear_clicked()
{
    ui->Display->clear();
}
///////////////////////////////////////////////////////////////
//linten Tcp
//////////////////////////////////////////////////////////////
void Tool::on_ListenTcp_clicked()
{
    QTcpServer *temp;
    temp=new QTcpServer();
    int port=ui->TcpPort1->text().toInt();
    if(port<=0)
    {
        QMessageBox box;
        box.setText("�˿ڴ���");
        box.exec();
        return ;
    }
    if(!temp->listen(QHostAddress::Any,port))
    {
        QMessageBox box;
        box.setText("��ȷ���˿�δ��ʹ��");
        box.exec();
        return ;
    }
    QString name;
    name=QString("Tcp ���� %1").arg(port);
    qDebug()<<name;
    tcpserver.insert(name,temp);
    ui->listWidget->addItem(name);
    connect(temp,SIGNAL(newConnection()),this,SLOT(newTcpConnect()));
}
////////////////////////////////////////////////////////////////////////
//�����µ�Tcp����
////////////////////////////////////////////////////////////////////////
void Tool::newTcpConnect()
{
    QMapIterator<QString,QTcpServer *> iTcpServer(tcpserver);
    while(iTcpServer.hasNext())
    {
        iTcpServer.next();
        QString name=QString("%1:%2:%3").arg("TCP").arg(QHostAddress(QHostAddress::Any).toString()).arg(iTcpServer.value()->serverPort());
        while(iTcpServer.value()->hasPendingConnections())
        {
            QTcpSocket *conn=iTcpServer.value()->nextPendingConnection();
            QString peerName=QString("��%1:%2��TCP����").arg(conn->peerAddress().toString()).arg(conn->peerPort());
            int r=QMessageBox::question(this,QString("��һ����TCP���������Ƿ����"),
                                            QString("%1���յ���һ������������%2").arg(name).arg(peerName),
                                            QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            if(QMessageBox::Yes!=r)
                {
                    conn->abort();
                    continue;
                }
            connect(conn,SIGNAL(readyRead()),this,SLOT(outPut()));
            connect(conn,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onSocketError(QAbstractSocket::SocketError)));
           tcpsocket.insert(peerName,conn);
        }
    }
    updatelist();
}
///////////////////////////////////////////////////////////////////
//��������
//////////////////////////////////////////////////////////////////
void Tool::onSocketError(QAbstractSocket::SocketError s)
{
    QMapIterator<QString,QUdpSocket *> iUdp(udpsocket);
    while(iUdp.hasNext())
    {
        iUdp.next();
        if(iUdp.value()->error()==s)
        {
            ui->Display->append(QString("%1��������%2").arg(iUdp.key()).arg(iUdp.value()->errorString()));
            delete iUdp.value();
            udpsocket.remove(iUdp.key());
        }
    }

    QMapIterator<QString,QTcpSocket*> iTcpSocket(tcpsocket);
    while(iTcpSocket.hasNext())
    {
        iTcpSocket.next();
        if(iTcpSocket.value()->error()==s)
        {
             ui->Display->append(QString("%1��������%2").arg(iTcpSocket.key()).arg(iTcpSocket.value()->errorString()));
            iTcpSocket.value()->abort();
            QString s=iTcpSocket.key();
            tcpsocket.remove(iTcpSocket.key());
        }
    }
    updatelist();
}
////////////////////////////////////////////////////////////////////////
//bind Udp
///////////////////////////////////////////////////////////////////////
void Tool::on_ListenUdp_clicked()
{
    QUdpSocket *temp;
    temp=new QUdpSocket();
    int port=ui->UdpPort1->text().toInt();
    if(port<=1023||port>65535)
    {
        QMessageBox box;
        box.setText("�˿ڴ���");
        box.exec();
        return ;
    }
    if(!temp->bind(port))
    {
        QMessageBox box;
        box.setText("��ȷ���˿�δ��ʹ��");
        box.exec();
        return ;
    }
    QString name;
    name=QString("Udp binding %1").arg(port);
    qDebug()<<name;
    udpsocket.insert(name,temp);
    ui->listWidget->addItem(name);
    connect(temp,SIGNAL(readyRead()),this,SLOT(outPut()));
    connect(temp,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onSocketError(QAbstractSocket::SocketError)));
}
////////////////////////////////////////////////////////////////////////
//��Ϣ���
/////////////////////////////////////////////////////////////////////////
void Tool::outPut()
{
    /////////////////////////////////////////////////////////////////////////
    //UDP����
    /////////////////////////////////////////////////////////////////////////
    QMapIterator<QString,QUdpSocket *> i(udpsocket);
    while(i.hasNext())
    {
        i.next();
        QUdpSocket *conn=i.value();
        while(conn->hasPendingDatagrams())
        {
            QByteArray data;
            data.resize(conn->pendingDatagramSize());
            QHostAddress sender;
            quint16 senderPort;
            conn->readDatagram(data.data(), data.size(),&sender, &senderPort);
            QString da;
            da=QString::fromAscii(data.data());
            qDebug()<<da;
            QString str=QString("��%1:%2�յ�ͨ��UDP���������ݰ�\n%3\n").arg(sender.toString()).arg(senderPort).arg(da);
            buff.push_back(str.toAscii());
        }
        qDebug()<<buff;
        ui->Display->append(buff);
        buff.clear();
    }
    /////////////////////////////////////////////////////////////////////////
    //Tcp����
    /////////////////////////////////////////////////////////////////////////
    QMapIterator<QString,QTcpSocket *> iTcp(tcpsocket);
    while(iTcp.hasNext())
    {
       iTcp.next();
        QTcpSocket *conn=iTcp.value();
        while(!conn->atEnd())
        {
            QByteArray data=conn->readAll();
            QString da;
            da=QString::fromAscii(data.data());
            QString str=(QString("�յ�����TCP:%1:%2�����ݰ�:\n%3")
                                                                                                           .arg(conn->peerAddress().toString())
                                                                                                           .arg(conn->peerPort())
                                                                                                           .arg(da));
            buff.push_back(str.toAscii());
        }
        qDebug()<<buff;
        ui->Display->append(buff);
        buff.clear();
    }
}
////////////////////////////////////////////////////////////////////////
//����Э���б�
////////////////////////////////////////////////////////////////////////
void Tool::updatelist()
{
    ui->listWidget->clear();
    ui->ActiveTcp->clear();
    QMapIterator<QString,QUdpSocket *> iUdp(udpsocket);
    while(iUdp.hasNext())
    {
       iUdp.next();
       ui->listWidget->addItem(iUdp.key());
    }
    QMapIterator<QString,QTcpSocket *> iTcp(tcpsocket);
    while(iTcp.hasNext())
    {
       iTcp.next();
       if(iTcp.value()->isOpen())
       {
            ui->listWidget->addItem(iTcp.key());
            ui->ActiveTcp->addItem(iTcp.key());
       }
    }
    QMapIterator<QString,QTcpServer *> iTcpServer(tcpserver);
    while(iTcpServer.hasNext())
    {
       iTcpServer.next();
       ui->listWidget->addItem(iTcpServer.key());
    }
    ui->listWidget->show();

}
////////////////////////////////////////////////////////////////////////
//�Ͽ��ѽ���������
///////////////////////////////////////////////////////////////////////
void Tool::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString info;
    if(udpsocket.contains(item->text()))
    {
        info=item->text()+"�Ͽ�\n";
        ui->Display->append(info);
        delete udpsocket[item->text()];
        udpsocket.remove(item->text());
        updatelist();
        return ;
    }
    if(tcpserver.contains(item->text()))
    {
        info=item->text()+"�Ͽ�\n";
        ui->Display->append(info);
        tcpserver[item->text()]->close();
        tcpserver.remove(item->text());
        updatelist();
        return ;
    }
    if(tcpsocket.contains(item->text()))
    {
        info=item->text()+"�Ͽ�\n";
        ui->Display->append(info);
        tcpsocket[item->text()]->close();
        tcpsocket.remove(item->text());
        updatelist();
        return ;
    }
}
//////////////////////////////////////////////////////////////////////////////////
//ͨ��TCP����
//////////////////////////////////////////////////////////////////////////////////
void Tool::on_SendTcp_clicked()
{
    if(ui->ActiveTcp->count()==0)
        return ;
    QTcpSocket *sender=tcpsocket[ui->ActiveTcp->currentText()];
    QByteArray data;
    data.append(ui->TcpInPut->toPlainText());
    sender->write(data);
    QString displayInfo;
    displayInfo=QString("ͨ��%1������Ϣ:\n").arg(ui->ActiveTcp->currentText());
    displayInfo+=QString::fromAscii(data.data());
    ui->Display->append(displayInfo);
    ui->TcpInPut->clear();
}
///////////////////////////////////////////////////////////////////
//ͨ��UDP����
//////////////////////////////////////////////////////////////////
void Tool::on_SendUdp_clicked()
{
    QUdpSocket *sender;
    sender=new QUdpSocket();
    QString GoalPort;
    QString address;
    QByteArray data;
    data.append(ui->UdpInPut->toPlainText().toAscii());
    GoalPort=ui->UdpPort2->text();
    qint16 goalPort=GoalPort.toInt();
    address=ui->UdpIp2->text();
    QHostAddress ip(address);
    if(sender->writeDatagram(data,ip,goalPort)==-1)
    {
        QMessageBox box;
        box.setText("�޷��������ݣ�����˿ں�IP��ַȷ����ȷͨ��");
        box.exec();
        return;
    }
    ui->UdpInPut->clear();
    ui->Display->append(QString("ͨ��UDP������Ϣ��%1:%2\n%3").arg(address).arg(goalPort).arg(data.data()));
}
/////////////////////////////////////////////////////////////////
//�����µ�TCP����
/////////////////////////////////////////////////////////////////
void Tool::on_CreateTcp_clicked()
{
    QHostAddress ip(ui->TcpIp2->text());
    qint16 Port=ui->TcpPort2->text().toInt();
    QTcpSocket *Tcp;
    Tcp=new QTcpSocket();
    connect(Tcp,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onSocketError(QAbstractSocket::SocketError)));
     connect(Tcp,SIGNAL(readyRead()),this,SLOT(outPut()));
    connect(Tcp,SIGNAL(connected()),this,SLOT(newTcpCreate()));
    Tcp->connectToHost(ip,Port);
    tcpsocket.insert(QString("TCP���ӵ�%1:%2").arg(ip.toString()).arg(Port),Tcp);
    ui->Display->append("������...");
}
void Tool::newTcpCreate()
{
    ui->Display->append("���ӳɹ�");
    updatelist();
}
//////////////////////////////////////////////////////////////////
//�õ�����IP
//////////////////////////////////////////////////////////////////
void Tool::on_LocalIp_clicked()
{
    QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }
        if (ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        ui->Display->append(QString("����IP%1").arg(ipAddress));
}
/////////////////////////////////////////////////////////////////////
//������Ϣ
//////////////////////////////////////////////////////////////////
void Tool::on_help_clicked()
{
    QString helpInfo;
    helpInfo+="1�����Ϸ��Ĵ���������Ϣ�����������ť�������\n\n";
    helpInfo+="2�����Ϸ��Ĵ�����Ѿ����������ӣ���ر���һ���Ļ�˫���Ϳ�����\n\n";
    helpInfo+="3��������TCP��UDP�ĸ��ֲ������˿ڵķ�Χ��1023��65535�������͡�����\n\n";
    helpInfo+="4����ʼ���ǶϿ��������ӣ�����ʹ��\n\n";
    helpInfo+="5�����պͷ��͵���Ϣ������GBK��ʽ��������д�˷��ļ����ܲ���ûʲô���ã���Ū�ý�����ѿ�������ɾ����\n\n";
    helpInfo+="���С�����Ǳ��˿���ʱ��д�ĺֲܴڣ���ʲô����ͽ����뷢����qjphh003@163.com\n������\n\n";
    ui->Display->append(helpInfo);
}

Tool::~Tool()
{
    delete ui;
}
