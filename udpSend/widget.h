#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QUdpSocket>
#include <QMessageBox>

#define UDP_LOCAL_BIND_PORT 1086


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
    int sendPort;
    int recvPort;
    QHostAddress dstIPAddress;
    QUdpSocket *udpSocket;

private slots:
    void on_sendButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
