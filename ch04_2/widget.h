#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals: //添加自定义的信号
    void SendMsg(QString str);

public slots:
    void ButtonClicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
