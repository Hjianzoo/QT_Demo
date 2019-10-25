#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QT UDP Recv");

    //创建UDP Socket
    udpSocket = new QUdpSocket(this);
    bool bindResult = udpSocket->bind(UDP_LOCAL_BIND_PORT);    //接收数据时，需要将SOCKET与接收端口绑定在一起
    if(!bindResult)
    {
        QMessageBox::information(this, "消息提示", "绑定失败！");
        return;
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(recvData()));    //绑定接收
}

Widget::~Widget()
{
    delete ui;
}

void Widget::recvData()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize()); //设置容器大小

        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString msg = datagram.data();
        ui->recvText->insertPlainText(msg + "\n");
        //showRecvTextEdit->setText(msg);
    }
}
