#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->LineEditAccPedal->setReadOnly(true);        //将LineEdit设置成只读模式
    ui->LineEditAzimuth->setReadOnly(true);
    ui->LineEditCarSpeed->setReadOnly(true);
    ui->LineEditEPBState->setReadOnly(true);
    ui->LineEditGaussX->setReadOnly(true);
    ui->LineEditGaussY->setReadOnly(true);
    ui->LineEditGear->setReadOnly(true);
    ui->LineEditGPSStatus->setReadOnly(true);
    ui->LineEditPitch->setReadOnly(true);
    ui->LineEditRoll->setReadOnly(true);
    ui->LineEditWheelAngle->setReadOnly(true);

    setWindowTitle("Monitor(minibus)");
    memset(&carParams,0,sizeof(struct params));
    udpSocket = new QUdpSocket(this);
    bool bindResult = udpSocket->bind(UDP_LOCALRECVPORT);    //接收数据时，需要将SOCKET与接收端口绑定在一起
    if(!bindResult)
    {
       QMessageBox::information(this, "消息提示", "绑定失败！");
       return;
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(udpRecvData()));    //绑定接收

}

Widget::~Widget()
{
    delete ui;
}

void Widget::udpRecvData()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize()); //设置容器大小

        udpSocket->readDatagram(datagram.data(), datagram.size());
        processRecvData(datagram.data());
        //ui->recvText->insertPlainText(msg + "\n");
        //showRecvTextEdit->setText(msg);
    }
}

void Widget::processRecvData(const char* msg)
{
    unsigned char* byteArray = (unsigned char*)msg;
    unsigned short ushort_tmpVal;
    short short_tmpVal;
    int int_tmpVal;
    unsigned int   uint_tmpVal;
    if((byteArray[0] != 0xAA) || (byteArray[1] != 0x55))
    {
        qDebug() << "recv data error";
    }

    switch(byteArray[2])
    {
    case 1:
        carParams.gear =    byteArray[3];
        carParams.epbOn =   byteArray[4];
        short_tmpVal = (byteArray[5]<<8) | byteArray[6];
        carParams.carSpeed = (float)short_tmpVal * 0.01;
        ushort_tmpVal = (byteArray[7]<<8) | byteArray[8];
        carParams.accPedal = (float)ushort_tmpVal * 0.01;
        carParams.wheelSignFlag = byteArray[13] == 1?-1:1;
        int_tmpVal = (byteArray[9]<<24) | (byteArray[10]<<16) |(byteArray[11]<<8) |(byteArray[12]);
        carParams.wheelAngle = (float)int_tmpVal * 0.01;
        break;
    case 2:
        uint_tmpVal = (byteArray[3]<<24) | (byteArray[4]<<16) |(byteArray[5]<<8) |(byteArray[6]);
        carParams.gaussX = (float)uint_tmpVal * 0.01;

        uint_tmpVal = (byteArray[7]<<24) | (byteArray[8]<<16) |(byteArray[9]<<8) |(byteArray[10]);
        carParams.gaussY = (float)uint_tmpVal * 0.01;

        short_tmpVal = (byteArray[11]<<8) | byteArray[12];
        carParams.pitch = (float)short_tmpVal * 0.01;

        short_tmpVal = (byteArray[13]<<8) | byteArray[14];
        carParams.roll = (float)short_tmpVal * 0.01;

        short_tmpVal = (byteArray[15]<<8) | byteArray[16];
        carParams.azimuth = (float)short_tmpVal * 0.01;

        carParams.gpsConfidence = byteArray[17];

        break;
    case 3:
        break;
    default:
        break;
    }
    updateParamDisplay();
}

void Widget::updateParamDisplay(void)
{
    QString p_str;

    if(carParams.gear == 3)
         ui->LineEditGear->setText(" P档");
    else if(carParams.gear == 2)
         ui->LineEditGear->setText("N档");
    else if(carParams.gear == 1)
         ui->LineEditGear->setText("R档");
    else if(carParams.gear == 0)
         ui->LineEditGear->setText(" D档");
    else
         ui->LineEditGear->setText("");
    p_str = QString::number(carParams.wheelAngle);
    ui->LineEditWheelAngle->setText(p_str);

    p_str = QString::number(carParams.carSpeed);
    ui->LineEditCarSpeed->setText(p_str);

    p_str = QString::number(carParams.accPedal);
    ui->LineEditAccPedal->setText(p_str);

    if(carParams.epbOn == 1)
        ui->LineEditEPBState->setText("驻车");
    else if(carParams.epbOn == 0)
        ui->LineEditEPBState->setText("释放");

    p_str = QString::number(carParams.gaussX);
    ui->LineEditGaussX->setText(p_str);

    p_str = QString::number(carParams.gaussY);
    ui->LineEditGaussY->setText(p_str);

    p_str = QString::number(carParams.azimuth);
    ui->LineEditAzimuth->setText(p_str);

    p_str = QString::number(carParams.pitch);
    ui->LineEditPitch->setText(p_str);

    p_str = QString::number(carParams.roll);
    ui->LineEditRoll->setText(p_str);

    p_str = QString::number(carParams.gpsConfidence,10);
    ui->LineEditGPSStatus->setText(p_str);

}
