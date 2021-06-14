#ifndef GPSETTINGS_H
#define GPSETTINGS_H

#include <QDialog>

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

private slots:
    void on_GP_Back_clicked();

    void on_ImageButton_clicked();

private:
    Ui::GPSettings *ui;
};

#endif // GPSETTINGS_H
