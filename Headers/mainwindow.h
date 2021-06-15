#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gpsettings.h"
#include "puzzlewindow.h"
#include "bpsettings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BP_Settings_clicked();

    void on_GP_Settings_clicked();

private:
    Ui::MainWindow *ui;
    GPSettings *puzzleSettings;
    BPSettings *bpsettings;
};
#endif // MAINWINDOW_H
