#include "connectdialog.h"
#include "ui_connectdialog.h"
#include <QMessageBox>

connectDialog::connectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectDialog)
{
    ui->setupUi(this);
}

connectDialog::~connectDialog()
{
    delete ui;
}

void connectDialog::on_connectButton_clicked()
{
    string person = ui->inputPerson->text().toStdString();
    string computer = ui->inputComputer->text().toStdString();

    QMessageBox msgBox;


    if(personServ.connect(person, computer))
    {
        msgBox.setText("Connected.");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("Not connected.");
        msgBox.exec();
    }

    close();
}
