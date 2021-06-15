#ifndef BPSETTINGS_H
#define BPSETTINGS_H

#include <QDialog>
#include "ballwindowsettings.h"

namespace Ui {
class BPSettings;
}

class BPSettings : public QDialog
{
    Q_OBJECT

public:
    explicit BPSettings(QWidget *parent = nullptr);
    ~BPSettings();

signals:
    void ThirdWindow();
    void FourthWindow();

private slots:
    void on_BP_Back_clicked();

    void on_five_players_clicked();

    void on_eleven_players_clicked();

    void on_BP_Play_clicked();

private:
    Ui::BPSettings *ui;
    ballwindowsettings *ballsettings;

};

#endif // BPSETTINGS_H
