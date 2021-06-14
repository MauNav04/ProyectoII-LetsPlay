#include "puzzlesettings.h"
#include "ui_puzzlesettings.h"
#include "mainwindow.h"

PuzzleSettings::PuzzleSettings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PuzzleSettings)
{
    ui->setupUi(this);
}

PuzzleSettings::~PuzzleSettings()
{
    delete ui;
}

void PuzzleSettings::on_GP_Play_clicked()
{

}

void PuzzleSettings::on_GP_Back_clicked()
{

}
