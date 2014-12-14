#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog)
{
    ui->setupUi(this);
}

addComputerDialog::~addComputerDialog()
{
    delete ui;
}

void addComputerDialog::on_addButton_clicked()
{
    Computer c = Computer();

    c.name = ui->inputName->text().toStdString();
    c.year = ui->inputYear->text().toInt();
    c.type = ui->inputType->text().toStdString();
    c.made = ui->inputMade->text().toInt();

    computerServ.add(c);

    close();
}
