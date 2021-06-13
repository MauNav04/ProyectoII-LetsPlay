#include "../Headers/puzzlewindow.h"
#include "ui_puzzlewindow.h"

puzzlewindow::puzzlewindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::puzzlewindow)
{
    ui->setupUi(this);
    initLabels();

    QString textLabel;
    for (int i = 0; i < field.getNumRows(); i++) {
        for (int j = 0; j < field.getNumColumns(); j++) {
            textLabel.append("[");
            textLabel.append(QString::number(field.getPuzzleMatrix()[i][j]->getCorrectRow()));
            textLabel.append(",");
            textLabel.append(QString::number(field.getPuzzleMatrix()[i][j]->getCorrectColumn()));
            textLabel.append("]");
            labels[i][j]->setText(textLabel);
            if (!field.getPuzzleMatrix()[i][j]->isDisplayed()) {
                labels[i][j]->setStyleSheet("QLabel { background-color: white; }");
                labels[i][j]->setText("");
            }
            ui->grid->addWidget(labels[i][j], i, j);
            textLabel.clear();
        }
    }
}

puzzlewindow::~puzzlewindow()
{
    delete ui;
}

void puzzlewindow::initLabels()
{
    QFont font;
    font.setBold(true);
    font.setPixelSize(20);
    for (int i = 0; i < field.getNumRows(); i++) {
        for (int j = 0; j < field.getNumRows(); j++) {
            labels[i][j] = new QLabel("+");
            labels[i][j]->setFont(font);
            labels[i][j]->setStyleSheet("QLabel { background-color: lightblue; }");
            labels[i][j]->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        }
    }
}