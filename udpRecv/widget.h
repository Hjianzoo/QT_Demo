#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDialog>
#include <QString>
#include <QUdpSocket>
#include <QMessageBox>

#define UDP_LOCAL_BIND_PORT 1090

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
    QUdpSocket *udpSocket;

private slots:
    void recvData();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
