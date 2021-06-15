#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Initialize the bpsettings Window
    bpsettings = new BPSettings();
    //connected to the slot start the Menu window on the button in the Puzzle window
    connect(bpsettings,&BPSettings::ThirdWindow,this,&MainWindow::show);
    //Initialize the BPSettings Window
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
