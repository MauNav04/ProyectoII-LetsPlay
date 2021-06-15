#include "bpsettings.h"
#include "ui_bpsettings.h"
#include "mainwindow.h"



BPSettings::BPSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BPSettings)
{
    ui->setupUi(this);
    //Initialize the bpsettings Window
    ballsettings = new ballwindowsettings();
    //connected to the slot start the Menu window on the button in the Puzzle window
    connect(ballsettings,&ballwindowsettings::FourthWindow,this,&MainWindow::show);
    //Initialize the BPSettings Window
}

BPSettings::~BPSettings()
{
    delete ui;
}

void BPSettings::on_BP_Back_clicked()
{
    this->close();
    emit ThirdWindow();

}
void BPSettings::on_BP_Play_clicked()
{
   ballsettings->show();
   this->close();
   //emit FourthWindow();
}

void BPSettings::on_five_players_clicked()
{

}

void BPSettings::on_eleven_players_clicked()
{

}


