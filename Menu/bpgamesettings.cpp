#include "bpgamesettings.h"
#include "ui_bpgamesettings.h"

BPGameSettings::BPGameSettings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BPGameSettings)
{
    ui->setupUi(this);
}

BPGameSettings::~BPGameSettings()
{
    delete ui;
}
