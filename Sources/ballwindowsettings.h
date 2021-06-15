#ifndef BALLWINDOWSETTINGS_H
#define BALLWINDOWSETTINGS_H

#include <QDialog>

namespace Ui {
class ballwindowsettings;
}

class ballwindowsettings : public QDialog
{
    Q_OBJECT

public:
    explicit ballwindowsettings(QWidget *parent = nullptr);
    ~ballwindowsettings();

signals:
    void FourthWindow();


private slots:
    void on_BP_Ball_Back_clicked();

    void on_BP_Ball_Play_clicked();

private:
    Ui::ballwindowsettings *ui;
};

#endif // BALLWINDOWSETTINGS_H
