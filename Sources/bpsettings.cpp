#include "../Headers/bpsettings.h"
#include "ui_bpsettings.h"
#include "../Headers/mainwindow.h"



BPSettings::BPSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BPSettings)
{
    ui->setupUi(this);
    //Initialize the bpsettings Window
//    ballsettings = new ballwindowsettings();
    //connected to the slot start the Menu window on the button in the Puzzle window
//    connect(ballsettings,&ballwindowsettings::FourthWindow,this,&MainWindow::show);
    //Initialize the BPSettings Window
}

BPSettings::~BPSettings()
{
    delete ui;
}

void BPSettings::on_BP_Back_clicked()
{
    this->close();
    emit FourthWindow();

}
void BPSettings::on_BP_Play_clicked()
{
//    ballsettings->show();
   bpwindow->show(numPlayers, formation, balls);
   this->close();
   //emit FourthWindow();
}

void BPSettings::on_five_players_clicked()
{
    numPlayers = 5;
}

void BPSettings::on_eleven_players_clicked()
{
    numPlayers = 11;
}

void BPSettings::on_First_Formation_clicked()
{
    formation = 1;
}

void BPSettings::on_Second_Formation_clicked()
{
    formation = 2;
}

void BPSettings::on_Third_Formation_clicked()
{
    formation = 3;
}


