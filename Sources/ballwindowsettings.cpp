#include "ballwindowsettings.h"
#include "ui_ballwindowsettings.h"
#include "bpsettings.h"

ballwindowsettings::ballwindowsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballwindowsettings)
{
    ui->setupUi(this);
}

ballwindowsettings::~ballwindowsettings()
{
    delete ui;
}

void ballwindowsettings::on_BP_Ball_Back_clicked()
{
    this->close();
    emit FourthWindow();
}

void ballwindowsettings::on_BP_Ball_Play_clicked()
{

}
