#include "widget.h"
#include "ui_widget.h"
#include <QmessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //添加关联代码，必须放在setUi函数之后
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(FoodIsComming()));
}

Widget::~Widget()
{
    delete ui;
}

//槽函数定义代码，与普通成员函数类似
void Widget::FoodIsComming()
{
    QMessageBox::information(this,tr("送餐"),tr("叮咚，外卖已送达"));
}
