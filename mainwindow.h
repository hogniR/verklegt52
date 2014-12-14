#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personservice.h"
#include "computerservice.h"
#include "addpersondialog.h"
#include "addcomputerdialog.h"
#include "connectdialog.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_addPersonButton_clicked();

    void on_addComputerButton_clicked();

    void on_connectButton_2_clicked();

    void on_connectButton_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<Person> correntPersons;
    std::vector<Person> currentlyDisplayedPersons;

    std::vector<Computer> correntComputers;
    std::vector<Computer> currentlyDisplayedComputers;

    personService personServ;
    computerService computerServ;

    void getAllPersons();
    void getAllComputers();
    void printPerson();
    void printComputers();
};

#endif // MAINWINDOW_H
