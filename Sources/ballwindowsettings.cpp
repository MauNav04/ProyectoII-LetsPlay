#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../Headers/bpsettings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Initialize the puzzleSettings Window
    puzzleSettings = new GPSettings;
    //connected to the slot start the Menu window on the button in the Puzzle window
    connect(puzzleSettings, &GPSettings::firstWindow, this, &MainWindow::show);
    //Initialize the BPSettings Window
    bpsettings = new BPSettings();
    //connected to the slot start the Menu window on the button in the BPSettings window
    connect(bpsettings, &BPSettings::ThirdWindow, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BP_Settings_clicked()
{
    bpsettings->show();
    this->close();
}

void MainWindow::on_GP_Settings_clicked()
{
    puzzleSettings->show();
    this->close();

}
