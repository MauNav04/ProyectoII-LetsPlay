#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QDialog>
#include <QLabel>
#include "PuzzleGrid.h"
#include "GeneticSolver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class puzzlewindow; }
QT_END_NAMESPACE

/**
 * Ventana que visualiza el rompecabezas
 */
class puzzlewindow : public QDialog
{
    Q_OBJECT

private:
    /**
     * Interfaz del rompecabezas
     */
    Ui::puzzlewindow *ui;

    /**
     * Texto que se pone en las piezas del rompecabezas
     */
    QString textLabel;

    /**
     * Rompecabezas a resolver
     */
    PuzzleGrid field = PuzzleGrid(true);

    /**
     * Solucionador del rompecabezas
     */
    GeneticSolver solver = GeneticSolver(field);

    /**
     * Solución del rompecabezas hecho con el algoritmo genético
     */
    std::array<direction, 128> solution;

    /**
     * Revisa el index del array de la solución para revisar el movimiento a hacer
     */
    int numDirection = 0;

    /**
     * Cuadros que muestran las pizas del rompecabezas
     */
    QLabel* labels[4][4];

private slots:

    /**
     * Da un paso atrás en el solucionador
     */
    void on_previousButton_clicked();

    /**
     * Da un paso adelante
     */
    void on_nextButton_clicked();

signals:
    /**
     * Utilizado para cambiar de ventana
     */
    void secondWindow();

public:

    /**
     * Constructor de la ventana que le pone etiquitas a las piezas
     * @param parent Widget de QT
     */
    explicit puzzlewindow(QWidget *parent = nullptr);

    /**
     * Destructor de la ventana
     */
    ~puzzlewindow();

    /**
     * Inicializa los labels del programa
     */
    void initLabels();

};
#endif // PUZZLEWINDOW_H
