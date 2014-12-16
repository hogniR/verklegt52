#include "addpersondialog.h"
#include "ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonDialog)
{
    ui->setupUi(this);
}

AddPersonDialog::~AddPersonDialog()
{
    delete ui;
}

void AddPersonDialog::on_addButton_clicked()
{
    Person p = Person();

    p.name = ui->inputName->text().toStdString();
    p.birthYear = ui->inputBirthyear->text().toInt();
    p.deathYear = ui->inputDeathyear->text().toInt();

    if(ui->Male_radioButton->isChecked())
        p.gender = "Male";
    else if(ui->Female_radioButton->isChecked())
        p.gender = "Female";

    personServ.add(p);

    close();
}
