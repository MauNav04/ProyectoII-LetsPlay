//
// Created by mavros on 6/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_puzzlewindow.h" resolved

#include "../Headers/puzzlewindow.h"
#include "ui_puzzlewindow.h"


puzzlewindow::puzzlewindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::puzzlewindow) {
    ui->setupUi(this);
}

puzzlewindow::~puzzlewindow() {
    delete ui;
}

