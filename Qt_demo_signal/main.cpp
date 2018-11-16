#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow w;
    w.setWindowTitle("Hello World");
    w.resize(325,125);

    QLineEdit lineEdit(&w);
    lineEdit.setGeometry(30,20,180,36);
    lineEdit.setPlaceholderText("Please write in text");

    QPushButton btn("Cancel",&w);
    btn.setGeometry(220,20,70,36);

    QLabel label(&w);
    label.setGeometry(30,70,250,30);

    QObject::connect(&btn,SIGNAL(clicked()),&app,SLOT(quit()));
    QObject::connect(&lineEdit,SIGNAL(textChanged(QString)),&label,SLOT(setText(QString)));

    w.show();
    return app.exec();
}
