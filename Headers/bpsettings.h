#ifndef BPSETTINGS_H
#define BPSETTINGS_H

#include <QDialog>

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

private slots:
    void on_BP_Back_clicked();

    void on_five_players_clicked();

    void on_eleven_players_clicked();

private:
    Ui::BPSettings *ui;

};

#endif // BPSETTINGS_H
