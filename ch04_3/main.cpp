#include "widget.h"
#include <QApplication>
#include "showvoid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    ShowVoid s;
    QObject::connect(&w,SIGNAL(SendVoid()),&s,SLOT(RecvVoid()));
    w.show();

    return a.exec();
}
