#ifndef PUZZLESETTINGS_H
#define PUZZLESETTINGS_H

#include <QMainWindow>

namespace Ui {
class PuzzleSettings;
}

class PuzzleSettings : public QMainWindow
{
    Q_OBJECT

public:
    explicit PuzzleSettings(QWidget *parent = nullptr);
    ~PuzzleSettings();

private slots:
    void on_GP_Play_clicked();

    void on_GP_Back_clicked();

private:
    Ui::PuzzleSettings *ui;
};

#endif // PUZZLESETTINGS_H
