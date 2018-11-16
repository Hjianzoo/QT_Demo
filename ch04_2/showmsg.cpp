#include "showmsg.h"
#include <QMessageBox>

ShowMsg::ShowMsg(QObject *parent) : QObject(parent)
{

}

ShowMsg::~ShowMsg()
{

}

void ShowMsg::RecvMsg(QString str)
{
    QMessageBox::information(NULL,tr("show"),str);
}
