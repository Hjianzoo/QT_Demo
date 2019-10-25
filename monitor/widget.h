#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QUdpSocket>
#include <QMessageBox>
#include "display.h"



#define UDP_LOCALRECVPORT 1090

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    void processRecvData(const char* msg);
    void updateParamDisplay(void);

private:
    QUdpSocket *udpSocket;
    struct params carParams;

private slots:
    void udpRecvData();
};

#endif // WIDGET_H
