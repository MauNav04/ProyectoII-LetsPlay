#include "../Headers/puzzlewindow.h"
#include "ui_puzzlewindow.h"

puzzlewindow::puzzlewindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::puzzlewindow)
{
    ui->setupUi(this);
    initLabels();

    for (int i = 0; i < field.getNumRows(); i++) {
        for (int j = 0; j < field.getNumColumns(); j++) {
            textLabel.append("[");
            textLabel.append(QString::number(field.getPuzzleMatrix()[i][j]->getCorrectRow()));
            textLabel.append(",");
            textLabel.append(QString::number(field.getPuzzleMatrix()[i][j]->getCorrectColumn()));
            textLabel.append("]");
            labels[i][j]->setText(textLabel);
            if (!field.getPuzzleMatrix()[i][j]->isDisplayed()) {
                labels[field.getEmptyRow()][field.getEmptyColumn()]->setStyleSheet("QLabel { background-color: white; }");
                labels[field.getEmptyRow()][field.getEmptyColumn()]->setText("");
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
            labels[i][j]->setStyleSheet("QLabel { background-color: lightgreen; }");
            labels[i][j]->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        }
    }
    solution = solver.solve();
}

void puzzlewindow::on_previousButton_clicked() {
    if (numDirection > 0) {
        numDirection--;
        field.move(solution[numDirection]);
        textLabel = "";
        textLabel.append("[");
        textLabel.append(QString::number(field.getMovedRow()));
        textLabel.append(",");
        textLabel.append(QString::number(field.getMovedColumn()));
        textLabel.append("]");
        labels[field.getMovedRow()][field.getMovedColumn()]->clear();
        labels[field.getMovedRow()][field.getMovedColumn()]->setText(textLabel);
        labels[field.getMovedRow()][field.getMovedColumn()]->setStyleSheet("QLabel { background-color: lightgreen; }");

        labels[field.getEmptyRow()][field.getEmptyColumn()]->clear();
        labels[field.getEmptyRow()][field.getEmptyColumn()]->setStyleSheet("QLabel { background-color: white; }");
        labels[field.getEmptyRow()][field.getEmptyColumn()]->setText("");
    }
}

void puzzlewindow::on_nextButton_clicked() {
    if (field.isSolved() < 16) {
        numDirection++;
        field.move(solution[numDirection]);
        textLabel = "";
        textLabel.append("[");
        textLabel.append(QString::number(field.getMovedRow()));
        textLabel.append(",");
        textLabel.append(QString::number(field.getMovedColumn()));
        textLabel.append("]");
        labels[field.getMovedRow()][field.getMovedColumn()]->clear();
        labels[field.getMovedRow()][field.getMovedColumn()]->setText(textLabel);
        labels[field.getMovedRow()][field.getMovedColumn()]->setStyleSheet("QLabel { background-color: lightgreen; }");

        textLabel = "";
        textLabel.append("[");
        textLabel.append(QString::number(field.getEmptyRow()));
        textLabel.append(",");
        textLabel.append(QString::number(field.getEmptyColumn()));
        textLabel.append("]");
        labels[field.getEmptyRow()][field.getEmptyColumn()]->clear();
        labels[field.getEmptyRow()][field.getEmptyColumn()]->setStyleSheet("QLabel { background-color: white; }");
        labels[field.getEmptyRow()][field.getEmptyColumn()]->setText("");
    }
}
