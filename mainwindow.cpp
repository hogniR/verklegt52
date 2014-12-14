#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    getAllPersons();
    getAllComputers();

    printPerson();
    printComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printPerson()
{
    ui->tablePersons->clearContents();

    ui->tablePersons->setRowCount(correntPersons.size());

    currentlyDisplayedPersons.clear();

    for(unsigned int i = 0; i < correntPersons.size(); i++)
    {
        Person current_person = correntPersons[i];

        QString name = QString::fromStdString(current_person.name);
        QString gender = QString::fromStdString(current_person.gender);
        QString birthyear = QString::number(current_person.birthYear);
        QString deathyear = QString::number(current_person.deathYear);
        QString computer = QString::fromStdString(current_person.computer);

        int currentRow = currentlyDisplayedPersons.size();

        ui->tablePersons->setItem(currentRow, 0, new QTableWidgetItem(name));
        ui->tablePersons->setItem(currentRow, 1, new QTableWidgetItem(gender));
        ui->tablePersons->setItem(currentRow, 2, new QTableWidgetItem(birthyear));
        ui->tablePersons->setItem(currentRow, 3, new QTableWidgetItem(deathyear));
        ui->tablePersons->setItem(currentRow, 4, new QTableWidgetItem(computer));

        currentlyDisplayedPersons.push_back(current_person);

    }

    ui->tablePersons->setRowCount(currentlyDisplayedPersons.size());
}

void MainWindow::getAllPersons()
{
    int option = 1;

    QSqlQuery query = personServ.printList(option);
    while(query.next())
    {
        Person p = Person();

        p.name = query.value(0).toString().toStdString();
        p.gender = query.value(1).toString().toStdString();
        p.birthYear = query.value(2).toInt();
        p.deathYear = query.value(3).toInt();
        p.computer = query.value(5).toString().toStdString();

        correntPersons.push_back(p);
    }
}

void MainWindow::getAllComputers()
{
    int option = 1;

    QSqlQuery query = computerServ.printList(option);
    while(query.next())
    {
        Computer c = Computer();

        c.name = query.value(0).toString().toStdString();
        c.year = query.value(1).toInt();
        c.type = query.value(2).toString().toStdString();
        c.made = query.value(3).toInt();
        c.creator = query.value(5).toString().toStdString();

        correntComputers.push_back(c);
    }
}

void MainWindow::printComputers()
{
    ui->computerTable->clearContents();

    ui->computerTable->setRowCount(correntComputers.size());

    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < correntComputers.size(); i++)
    {
        Computer current_computer = correntComputers[i];

        std::string searchString = ui->search_person->text().toStdString();

        QString name = QString::fromStdString(current_computer.name);
        QString year = QString::number(current_computer.year);
        QString type = QString::fromStdString(current_computer.type);
        QString creator = QString::fromStdString(current_computer.creator);
        QString made;

        if(current_computer.made == true)
            made = "Yes";
        else
            made = "No";

        int currentRow = currentlyDisplayedComputers.size();

        ui->computerTable->setItem(currentRow, 0, new QTableWidgetItem(name));
        ui->computerTable->setItem(currentRow, 1, new QTableWidgetItem(year));
        ui->computerTable->setItem(currentRow, 2, new QTableWidgetItem(type));
        ui->computerTable->setItem(currentRow, 3, new QTableWidgetItem(made));
        ui->computerTable->setItem(currentRow, 4, new QTableWidgetItem(creator));

        currentlyDisplayedComputers.push_back(current_computer);
    }

    ui->computerTable->setRowCount(currentlyDisplayedComputers.size());
}

void MainWindow::on_addPersonButton_clicked()
{
    AddPersonDialog addperson;
    addperson.exec();
}

void MainWindow::on_addComputerButton_clicked()
{
    addComputerDialog addcomputer;
    addcomputer.exec();
}

void MainWindow::on_connectButton_2_clicked()
{
    connectDialog connectd;
    connectd.exec();

    getAllComputers();
    getAllPersons();

    printComputers();
    printPerson();
}

void MainWindow::on_connectButton_clicked()
{
    connectDialog connectd;
    connectd.exec();

    getAllComputers();
    getAllPersons();

    printComputers();
    printPerson();
}
