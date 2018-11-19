#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QCryptographicHash>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置密码框的显示格式
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLogin_clicked()
{
    //判断用户名密码是否为空
    if(ui->lineEditUser->text().isEmpty()||ui->lineEditPassword->text().isEmpty())
    {
        QMessageBox::warning(this,tr("警告信息"),tr("用户名或密码不能为空，不能登录。"));
        return;
    }
    //用户名
    m_strUser = ui->lineEditUser->text();
    m_passwordHash = QCryptographicHash::hash(ui->lineEditPassword->text().toUtf8(),QCryptographicHash::Sha256);

    //构造消息
    //添加用户名
    QString strMsg  = tr("用户名：") + m_strUser + tr("\r\n") + tr("密码 Hash:");
    strMsg += m_passwordHash.toHex();

    qDebug()<<strMsg;
    QMessageBox::information(this,tr("用户信息"),strMsg);
}

void Widget::on_pushButtonExit_clicked()
{
    this->close();
}
