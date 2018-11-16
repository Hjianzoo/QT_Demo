#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_pushButtonConn_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonConn_clicked()
{
    //关联
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));
    //调整按钮可用性
    ui->pushButtonConn->setEnabled(false);
    ui->pushButtonDisconn->setEnabled(true);
    //QMessageBox::information(this,tr("送餐"),tr("叮咚，外卖到啦"));
}

void Widget::on_pushButtonDisconn_clicked()
{
    //解除关联
        disconnect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

        //调整按钮可用性
        ui->pushButtonConn->setEnabled(true);       //没有关联，只有关联按钮可用
        ui->pushButtonDisconn->setEnabled(false);   //没有关联，解除关联按钮禁用
}
