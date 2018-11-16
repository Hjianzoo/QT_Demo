#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void RecvGenderID(int id);
    void RecvStatusID(int id);

private slots:
    void on_radioButton0to19_toggled(bool checked);

    void on_radioButton20to39_toggled(bool checked);

    void on_radioButton40to59_toggled(bool checked);

    void on_radioButton60to_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QButtonGroup *m_pGenderGroup;
    QButtonGroup *m_pStatusGroup;
};

#endif // WIDGET_H
