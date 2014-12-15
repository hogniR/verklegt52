#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personservice.h"
#include "computerservice.h"
#include "addpersondialog.h"
#include "addcomputerdialog.h"
#include "connectdialog.h"
#include <vector>

namespace Ui
{
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

    void on_searchPersonButton_clicked();

    void on_searchComputerButton_clicked();

    void on_dropdownList_persons_activated(int index);

    void on_dropdownList_computers_activated(int index);

private:
    Ui::MainWindow *ui;

    std::vector<Person> correntPersons;
    std::vector<Person> currentlyDisplayedPersons;
    std::vector<Person> searchedPerson;

    std::vector<Computer> correntComputers;
    std::vector<Computer> currentlyDisplayedComputers;
    std::vector<Computer> searchedComputer;

    personService personServ;
    computerService computerServ;

    void getAllPersons(int sortBy);
    void getAllComputers(int sortBy);
    void printPerson();
    void printComputers();
    void printSearchedPerson();
    void printSearchedComputer();
};

#endif // MAINWINDOW_H
