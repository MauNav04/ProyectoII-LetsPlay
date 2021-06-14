#ifndef GPSETTINGS_H
#define GPSETTINGS_H

#include <QDialog>
#include "puzzlewindow.h"

namespace Ui {
class GPSettings;
}

class GPSettings : public QDialog
{
    Q_OBJECT

public:
    explicit GPSettings(QWidget *parent = nullptr);
    ~GPSettings();

signals:
    void firstWindow();
    void secondWindow();

private slots:
    void on_GP_Back_clicked();

    void on_ImageButton_clicked();

    void on_GP_Play_clicked();
private:
    Ui::GPSettings *ui;
    puzzlewindow *gpwindow;
};

#endif // GPSETTINGS_H
