#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QT UDP Sender");

    udpSocket = new QUdpSocket(this);

    recvPort = UDP_LOCAL_BIND_PORT;
    bool bindResult = udpSocket->bind(recvPort);    //接收数据时，需要将SOCKET与接收端口绑定在一起
    if(!bindResult)
        {
            QMessageBox::information(this, "消息提示", "绑定失败！");
            return;
        }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sendButton_clicked()
{
    QString ip_str = ui->dstIPEditLine->text();
    dstIPAddress.setAddress(ip_str);

    QString port_str = ui->dstPortEditLine->text();
    sendPort = port_str.toInt();

    //QString send_str;

    QString send_str = ui->sendTextEdit->toPlainText();

    if(send_str.isEmpty())
       {
           QMessageBox::information(this, "消息提示", "输入数据为空，请重新输入...");
           return;
       }
    //本地：QHostAddress::LocalHost
    int length = udpSocket->writeDatagram(send_str.toStdString().c_str(), dstIPAddress, sendPort);        //向指定端口发送数据
    qDebug() << send_str;
    qDebug() << dstIPAddress.toString();
    qDebug() << sendPort;
    if(length != send_str.length())
        {
            QMessageBox::information(this, "消息提示", "发送失败！");
            return;
        }
}
