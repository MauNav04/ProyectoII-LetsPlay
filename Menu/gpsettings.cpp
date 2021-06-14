#include "gpsettings.h"
#include "ui_gpsettings.h"
#include "mainwindow.h"
#include "QFileDialog"

GPSettings::GPSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPSettings)
{
    ui->setupUi(this);
}

GPSettings::~GPSettings()
{
    delete ui;
}

void GPSettings::on_GP_Back_clicked()
{
    this->close();
    emit firstWindow();
}

void GPSettings::on_ImageButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"), "", tr("Images(*.png *.jpg *. jpeg *. bmp *. gif)"));
    if (QString::compare(filename, QString()) != 0){
        QImage GPimage;
        bool valid = GPimage.load(filename);

        if (valid){
            GPimage = GPimage.scaledToHeight(ui->ImageView->width(),Qt::SmoothTransformation);
            ui->ImageView->setPixmap(QPixmap::fromImage(GPimage));
        }
        else{
            //Error handling
        }
    }
}
