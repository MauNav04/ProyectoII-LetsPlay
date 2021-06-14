#ifndef BPGAMESETTINGS_H
#define BPGAMESETTINGS_H

#include <QMainWindow>

namespace Ui {
class BPGameSettings;
}

class BPGameSettings : public QMainWindow
{
    Q_OBJECT

public:
    explicit BPGameSettings(QWidget *parent = nullptr);
    ~BPGameSettings();

private:
    Ui::BPGameSettings *ui;
};

#endif // BPGAMESETTINGS_H
