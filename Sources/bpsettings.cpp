#include "../Headers/bpsettings.h"
#include "ui_bpsettings.h"


BPSettings::BPSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BPSettings)
{
    ui->setupUi(this);
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

void BPSettings::on_five_players_clicked()
{

}

void BPSettings::on_eleven_players_clicked()
{

}
