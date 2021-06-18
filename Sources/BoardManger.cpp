//
// Created by mauro on 6/10/21.
//

#include "../Headers/BoardManger.h"
#include <QList>
#include <QString>
#include <QGraphicsScene>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <string>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


QList<QList<QString>> playerPositions = {};

QList<QList<QString>> onlyPlayers = {};

QList<QString> gameBoard = {};

QGraphicsScene *superScene;
std::string direction;
std::string strength;
QPoint currentPlayer;
QPoint currentBallPosition;

bool xxx = true;
bool pathRequest = false;

BoardManger::BoardManger() = default;

BoardManger::BoardManger(QGraphicsScene * parentScene, int amountPlayers, int formationID, int cantidadBolas) {
    superScene = parentScene;
    respuestaServer = connManager.mandarPeticion("{\"juego\" : \"BPGame\", \"accion\" : \"Alineacion\", \"numJugadores\" : \""+ std::to_string(amountPlayers) +"\", \"tipoAlineacion\" : \"" + std::to_string(formationID) + "\"}");

    //parse json
    jsonDoc = QJsonDocument::fromJson(respuestaServer.toUtf8());
    jsonObj = jsonDoc.object();

    mensaje = jsonObj["mensaje"].toString();

    qDebug() << "Mensaje: " << mensaje;

    respuestaServer = connManager.mandarPeticion("{\"juego\" : \"BPGame\", \"accion\" : \"CantidadBolas\", \"numBolas\" : \""+ std::to_string(cantidadBolas) +"\"}");

    //parse json
    jsonDoc = QJsonDocument::fromJson(respuestaServer.toUtf8());
    jsonObj = jsonDoc.object();

    mensaje = jsonObj["mensaje"].toString();

    qDebug() << "Mensaje: " << mensaje;

    setFormation(amountPlayers, formationID);
    PositionSelector();
    ExtractPlayers();
    draw(parentScene);
    ControllingButtons (parentScene);
}

void BoardManger::setFormation(int amountPlayers, int formationID){
    if(amountPlayers == 5){
        if(formationID == 1){
            gameBoard= {"FFFFFFFFFFFFFFFFFFFFFFFFF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXX2XXX1XXXXXXXXXF",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "EXX1XXXXXXXX*XXXXXXXX2XXE",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "FXXXXXXXXX2XXX1XXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FFFFFFFFFFFFFFFFFFFFFFFFF"};
        }
        else if(formationID == 2){
            gameBoard= {"FFFFFFFFFFFFFFFFFFFFFFFFF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXX1XXXXXXXXX2XXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "EXX1XXX2XXX2*1XXX1XXX2XXE",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXX1XXXXXXXXX2XXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FFFFFFFFFFFFFFFFFFFFFFFFF"};
        }
        else if(formationID == 3){
            gameBoard= {"FFFFFFFFFFFFFFFFFFFFFFFFF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXX2XXXXX1XXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "EXX1XXXXXXXX*XXXXXXXX2XXE",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXX2XXXXX1XXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FFFFFFFFFFFFFFFFFFFFFFFFF"};
        }
    }
    else if(amountPlayers == 11){
        if(formationID == 1){
            gameBoard= {"FFFFFFFFFFFFFFFFFFFFFFFFF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXX2XXXX1XXXXX2XXXX1XXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "EXXXXXXXXX2XXX1XXXXXXXXXE",
                        "EXX1XXXXXXXX*XXXXXXXX2XXE",
                        "EXXXXXXXXX2XXX1XXXXXXXXXE",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXX2XXXX1XXXXX2XXXX1XXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FFFFFFFFFFFFFFFFFFFFFFFFF"};
        }
        else if(formationID == 2){
            gameBoard= {"FFFFFFFFFFFFFFFFFFFFFFFFF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXX1XXXXXXXXX2XXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXX1XXXX1XXX2XXXX2XXXXF",
                        "FXXXXXXX2XXXXXXX1XXXXXXXF",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "EXX1XX2XXX1X*X2XXX1XX2XXE",
                        "EXXXXXXXXXXXXXXXXXXXXXXXE",
                        "FXXXXXXX2XXXXXXX1XXXXXXXF",
                        "FXXXX1XXXX1XXX2XXXX2XXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FXXXXXX1XXXXXXXXX2XXXXXXF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FFFFFFFFFFFFFFFFFFFFFFFFF"};
        }
        else if(formationID == 3){
            gameBoard= {"FFFFFFFFFFFFFFFFFFFFFFFFF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FX2XXXXXXXXXXXXXXXXXXX1XF",
                        "FXXXXXXXX2XXXXX1XXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXXX1XXX2XXXXXXXXXF",
                        "EXXXXXX2XXXXXXXXX1XXXXXXE",
                        "EXX1XXXXXXXX*XXXXXXXX2XXE",
                        "EXXXXXX2XXXXXXXXX1XXXXXXE",
                        "FXXXXXXXXX1XXX2XXXXXXXXXF",
                        "FXXXXX1XXXXXXXXXXX2XXXXXF",
                        "FXXXXXXXX2XXXXX1XXXXXXXXF",
                        "FX2XXXXXXXXXXXXXXXXXXX1XF",
                        "FXXXXXXXXXXXXXXXXXXXXXXXF",
                        "FFFFFFFFFFFFFFFFFFFFFFFFF"};
        }
    }
}

void BoardManger::ExtractPlayers(){
    int lim = playerPositions.length();
    for(int i=0; i<lim; i++){
        if(playerPositions[i][2] == "1" or playerPositions[i][2] == "2"){

            onlyPlayers.append(playerPositions[i]);
        }
    }
}

//Takes the positions from the first String
void BoardManger::PositionSelector(){
    for(int colID = 0; colID<gameBoard.length(); colID++){
        for(int rowID = 0; rowID<25; rowID++){
            if(gameBoard[colID][rowID] != "X"){
                QString strColID = QString::number(colID);
                QString strRowID = QString::number(rowID);

                //QStringList ObjectPackedData;
                QString infoStr = strColID + "," + strRowID + "," + gameBoard[colID][rowID] ;
                QList<QString> QSList = infoStr.split(",");

                playerPositions.append(QSList);

            }
        }
    }
}

//Creates the matrix of the game based on the list of strings
void BoardManger::draw(QGraphicsScene *scene){
    int RowNumber1 = 15;
    int ColNumber1 = 25;

    int current = 0;

    for(int i = 0; i<RowNumber1; i++){
        for(int j = 0; j<ColNumber1; j++){
            //Verifies if player positions still has pieces to place
            if(current < playerPositions.length()) {
                //Makes a comparison between each one of the spaces on the matrix and the position specified
                //by the current player piece being analyzed
                if (i == playerPositions[current][0].toInt() && j == playerPositions[current][1].toInt()) {
                    //If the position matches, looks for the type of piece in order to place the right image
                    if (playerPositions[current][2] == "E") {
                        QLabel *label_goal = new QLabel();

                        label_goal->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_goal->setLineWidth(2);
                        label_goal->setStyleSheet("QLabel { background-color : yellow; color : brown; }");
                        label_goal->setGeometry(j*30,i*30,30,30);
                        scene->addWidget(label_goal);

                        current += 1;
                    }
                    else if (playerPositions[current][2] == "1") {
                        QLabel *label_player1 = new QLabel();

                        label_player1->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_player1->setLineWidth(2);
                        label_player1->setGeometry(j*30,i*30,30,30);
                        label_player1->setStyleSheet("QLabel { background-color : red; color : red; }");
                        scene->addWidget(label_player1);

                        current += 1;
                    }
                    else if (playerPositions[current][2] == "2") {
                        QLabel *label_player2 = new QLabel();

                        label_player2->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_player2->setLineWidth(2);
                        label_player2->setGeometry(j*30,i*30,30,30);
                        label_player2->setStyleSheet("QLabel { background-color : blue; color : blue; }");
                        scene->addWidget(label_player2);

                        current += 1;
                    }
                    else if (playerPositions[current][2] == "3") {
                        QLabel *label_player1ball = new QLabel();

                        label_player1ball->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_player1ball->setLineWidth(2);
                        label_player1ball->setGeometry(j*30,i*30,30,30);
                        label_player1ball->setStyleSheet("QLabel { background-color : red; color : yellow; }");
                        scene->addWidget(label_player1ball);

                        current += 1;
                    }
                    else if (playerPositions[current][2] == "4") {
                        QLabel *label_player2ball = new QLabel();

                        label_player2ball->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_player2ball->setLineWidth(2);
                        label_player2ball->setGeometry(j*30,i*30,30,30);
                        label_player2ball->setStyleSheet("QLabel { background-color : blue; color : yellow; }");
                        scene->addWidget(label_player2ball);

                        current += 1;
                    }
                    else if (playerPositions[current][2] == "*") {
                        QLabel *label_Ball = new QLabel();

                        label_Ball->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_Ball->setLineWidth(2);
                        label_Ball->setGeometry(j*30,i*30,30,30);
                        label_Ball->setStyleSheet("QLabel { background-color : white; color : black; }");
                        scene->addWidget(label_Ball);

                        current += 1;
                    }
                    else if (playerPositions[current][2] == "F") {
                        QLabel *label_border = new QLabel();

                        label_border->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_border->setLineWidth(2);
                        label_border->setGeometry(j*30,i*30,30,30);
                        label_border->setStyleSheet("QLabel { background-color : gray; color : black; }");
                        scene->addWidget(label_border);

                        current += 1;
                    }

                    else if (playerPositions[current][2] == "P") {
                        QLabel *label_path = new QLabel();

                        label_path->setFrameStyle(QFrame::Panel | QFrame::Raised);
                        label_path->setLineWidth(2);
                        label_path->setGeometry(j*30,i*30,30,30);
                        label_path->setStyleSheet("QLabel { background-color : magenta; color : green; }");
                        scene->addWidget(label_path);

                        current += 1;
                    }

                    else{
                        QLabel *label_grass = new QLabel();

                        label_grass->setFrameStyle(QFrame::Panel | QFrame::Plain);
                        label_grass->setLineWidth(2);
                        label_grass->setStyleSheet("QLabel { background-color : green; color : black; }");
                        label_grass->setGeometry(j*30,i*30,30,30);
                        scene->addWidget(label_grass);
                    }
                }
                else{
                    QLabel *label_grass = new QLabel();

                    label_grass->setFrameStyle(QFrame::Panel | QFrame::Plain);
                    label_grass->setLineWidth(2);
                    label_grass->setGeometry(j*30,i*30,30,30);
                    label_grass->setStyleSheet("QLabel { background-color : green; color : black; }");
                    scene->addWidget(label_grass);;
                }
            }
            else{
                QLabel *label_grass = new QLabel();

                label_grass->setFrameStyle(QFrame::Panel | QFrame::Plain);
                label_grass->setLineWidth(2);
                label_grass->setGeometry(j*30,i*30,30,30);
                label_grass->setStyleSheet("QLabel { background-color : green; color : black; }");
                scene->addWidget(label_grass);
            }
        }
    }
}

QList<QString> BoardManger::updateBoard(QPoint spaceToMove){
    for(int i=0; i<gameBoard.length(); i++ ){
        QString newRow = gameBoard[i];
        for(int j=0; j<25; j++){
            if(spaceToMove.x() == i and spaceToMove.y() == j){
                newRow.replace(j,1,"*");
            }
        }
        if(gameBoard[i].contains("*")){
            newRow.replace("*", "X");
        }
        gameBoard[i] = newRow;
    }
    //qDebug()<< "Final result: " << board;
    return gameBoard;
}

QList<QString> BoardManger::updatePath(QPoint spaceToMove){
    for(int i=0; i<gameBoard.length(); i++ ){
        QString newRow = gameBoard[i];
        for(int j=0; j<25; j++){
            if(spaceToMove.x() == i and spaceToMove.y() == j){
                newRow.replace(j,1,"P");
            }
        }
        gameBoard[i] = newRow;
    }
    //qDebug()<< "Final result: " << board;
    return gameBoard;
}

void BoardManger::GraphicUpdate(QGraphicsScene *scene, QList<QPoint> BallTrace){
    int amountofSteps = BallTrace.length();

    for(int step = 0; step<amountofSteps; step++){
        if(pathRequest){
            QList<QString> UpdatedBoard = updatePath(BallTrace[step]);
            qDebug() << "NewBoard: " << UpdatedBoard;
            //Deletes current values inside board
            gameBoard.clear();
            //Sets new Board
            gameBoard = UpdatedBoard;
        }
        else {
            //Sets position of the ball on the board's matrix
            QList<QString> UpdatedBoard = updateBoard(BallTrace[step]);
            qDebug() << "NewBoard: " << UpdatedBoard;
            //Deletes current values inside board
            gameBoard.clear();
            //Sets new Board
            gameBoard = UpdatedBoard;
        }
        //Deletes current values inside playerPositions
        playerPositions.clear();
        //Sets new player positions
        PositionSelector();
        //Draws players on the field based on the results of playerPositions
        draw(scene);
        //Delays the code so a change can be appreciated
        msleep(10);
    }
}

void BoardManger::ControllingButtons (QGraphicsScene *scene){

    QPushButton * buttonNW = new QPushButton("NW");
    buttonNW->setGeometry(75, 455, 40,40);
    connect(buttonNW, SIGNAL(clicked()), this, SLOT(btnClicked_NW()));
    scene->addWidget(buttonNW);

    QPushButton * buttonN = new QPushButton("N");
    buttonN->setGeometry(120, 455, 40,40);
    connect(buttonN, SIGNAL(clicked()), this, SLOT(btnClicked_N()));
    scene->addWidget(buttonN);

    QPushButton * buttonNE = new QPushButton("NE");
    buttonNE->setGeometry(165, 455, 40,40);
    connect(buttonNE, SIGNAL(clicked()), this, SLOT(btnClicked_NE()));
    scene->addWidget(buttonNE);

    QPushButton * buttonE = new QPushButton("E");
    buttonE->setGeometry(165, 500, 40,40);
    connect(buttonE, SIGNAL(clicked()), this, SLOT(btnClicked_E()));
    scene->addWidget(buttonE);

    QPushButton * buttonSW = new QPushButton("SW");
    buttonSW->setGeometry(75, 545, 40,40);
    connect(buttonSW, SIGNAL(clicked()), this, SLOT(btnClicked_SW()));
    scene->addWidget(buttonSW);

    QPushButton * buttonW = new QPushButton("W");
    buttonW->setGeometry(75, 500, 40,40);
    connect(buttonW, SIGNAL(clicked()), this, SLOT(btnClicked_W()));
    scene->addWidget(buttonW);

    QPushButton * buttonS = new QPushButton("S");
    buttonS->setGeometry(120, 545, 40,40);
    connect(buttonS, SIGNAL(clicked()), this, SLOT(btnClicked_S()));
    scene->addWidget(buttonS);

    QPushButton * buttonSE = new QPushButton("SE");
    buttonSE->setGeometry(165, 545, 40,40);
    connect(buttonSE, SIGNAL(clicked()), this, SLOT(btnClicked_SE()));
    scene->addWidget(buttonSE);

    QPushButton * buttonWeak = new QPushButton("Debil");
    buttonWeak->setGeometry(225, 500, 100,40);
    connect(buttonWeak, SIGNAL(clicked()), this, SLOT(btnClicked_Weak()));
    scene->addWidget(buttonWeak);

    QPushButton * buttonNormal = new QPushButton("Normal");
    buttonNormal->setGeometry(335, 500, 100,40);
    connect(buttonNormal, SIGNAL(clicked()), this, SLOT(btnClicked_Normal()));
    scene->addWidget(buttonNormal);

    QPushButton * buttonStrong = new QPushButton("Fuerte");
    buttonStrong->setGeometry(445, 500, 100,40);
    connect(buttonStrong, SIGNAL(clicked()), this, SLOT(btnClicked_Strong()));
    scene->addWidget(buttonStrong);

    QPushButton * buttonShoot = new QPushButton("Disparar");
    buttonShoot->setGeometry(560, 480, 125,70);
    buttonShoot->setStyleSheet("QPushButton { background-color : Red; color : black; }");
    connect(buttonShoot, SIGNAL(clicked()), this, SLOT(btnClicked_Shoot()));
    scene->addWidget(buttonShoot);

    QPushButton * buttonPathFinding = new QPushButton("Path Finding");
    buttonPathFinding->setGeometry(560, 555, 125,25);
    connect(buttonPathFinding, SIGNAL(clicked()), this, SLOT(btnClicked_PathF()));
    scene->addWidget(buttonPathFinding);

    QPushButton * buttonCenterBall = new QPushButton("Tiro Central");
    buttonCenterBall->setGeometry(695, 480, 90,40);
    connect(buttonCenterBall, SIGNAL(clicked()), this, SLOT(btnClicked_CenterBall()));
    scene->addWidget(buttonCenterBall);
}

void BoardManger::btnClicked_NW() {
    direction = "NO";
}

void BoardManger::btnClicked_N() {
    direction = "N";

}

void BoardManger::btnClicked_NE() {
    direction = "NE";
}

void BoardManger::btnClicked_E() {
    direction = "E";
}

void BoardManger::btnClicked_SE() {
    direction = "SE";
}

void BoardManger::btnClicked_S() {
    direction = "S";
}

void BoardManger::btnClicked_SW() {
    direction = "SO";
}

void BoardManger::btnClicked_W() {
    direction = "O";
}

void BoardManger::btnClicked_Weak() {
    strength = "25";
}

void BoardManger::btnClicked_Normal() {
    strength = "100";
    gamy = false;
}

void BoardManger::btnClicked_Strong() {
    strength = "250";
}


void BoardManger::btnClicked_Shoot() {
    respuestaServer = connManager.mandarPeticion("{\"juego\" : \"BPGame\", \"accion\" : \"Tirar\", \"direccion\" : \""+ direction +"\", \"potencia\" : \""+ strength +"\"}");
    qDebug() << "respuestaServer: " << respuestaServer;

    //parse json
    jsonDoc = QJsonDocument::fromJson(respuestaServer.toUtf8());
    jsonObj = jsonDoc.object();

    QJsonValue value = jsonObj.value("trayectoria");
    QJsonArray array = value.toArray();
    temp = {};
            foreach (const QJsonValue & v, array) {
            numeroCasilla = v.toObject().value("numero").toInt();
            coordX = numeroCasilla/25;
            coordY = numeroCasilla - (coordX*25 +1);
            temp.append(QPoint(coordX,coordY));
        }

    qDebug() << "temp: " << temp ;
    GraphicUpdate(superScene, temp);

}

void BoardManger::btnClicked_PathF() {
    pathRequest = true;
    respuestaServer = connManager.mandarPeticion("{\"juego\" : \"BPGame\", \"accion\" : \"Pathfinding\"}");
    qDebug() << "respuestaServer: " << respuestaServer;

    //parse json
    jsonDoc = QJsonDocument::fromJson(respuestaServer.toUtf8());
    jsonObj = jsonDoc.object();

    QJsonValue value = jsonObj.value("trayectoria");
    QJsonArray array = value.toArray();
    temp = {};
            foreach (const QJsonValue & v, array) {
            numeroCasilla = v.toObject().value("numero").toInt();
            coordX = numeroCasilla/25;
            coordY = numeroCasilla - (coordX*25 +1);
            temp.append(QPoint(coordX,coordY));
        }

    qDebug() << "temp: " << temp ;
    GraphicUpdate(superScene, temp);
    pathRequest = false;
}

void BoardManger::btnClicked_CenterBall() {
    respuestaServer = connManager.mandarPeticion("{\"juego\" : \"BPGame\", \"accion\" : \"TiroCentral\"}");
    qDebug() << "respuestaServer: " << respuestaServer;

    //parse json
    jsonDoc = QJsonDocument::fromJson(respuestaServer.toUtf8());
    jsonObj = jsonDoc.object();

    QJsonValue value = jsonObj.value("trayectoria");
    QJsonArray array = value.toArray();
    temp = {};
    foreach (const QJsonValue & v, array) {
        numeroCasilla = v.toObject().value("numero").toInt();
        coordX = numeroCasilla/25;
        coordY = numeroCasilla - (coordX*25 +1);
        temp.append(QPoint(coordX,coordY));
    }

    qDebug() << "temp: " << temp ;
    GraphicUpdate(superScene, temp);
}


bool BoardManger::GameLoop(){
    bool gameON;
    while(xxx){
    }
    qDebug() << "Hello" ;
    return gameON;
}

void BoardManger::msleep(int msec)
{
    QEventLoop loop;

    QTimer::singleShot(msec, &loop, &QEventLoop::quit);

    loop.exec();
}

/*
QList<QString *> BoardManger::getBoard() {
    return gameBoard;
}

void BoardManger::setBoard(QList<QString> board) {
    //gameBoard = board;
}
*/