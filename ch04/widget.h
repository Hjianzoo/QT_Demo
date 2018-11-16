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

public slots:          //槽函数声明标志
    void FoodIsComming(); //槽函数

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
