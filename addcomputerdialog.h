#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "computerservice.h"

namespace Ui {
class addComputerDialog;
}

class addComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addComputerDialog(QWidget *parent = 0);
    ~addComputerDialog();

private slots:
    void on_addButton_clicked();

private:
    Ui::addComputerDialog *ui;
    computerService computerServ;
};

#endif // ADDCOMPUTERDIALOG_H
