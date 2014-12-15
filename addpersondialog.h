#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>
#include "personservice.h"

namespace Ui
{
    class AddPersonDialog;
}

class AddPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonDialog(QWidget *parent = 0);
    ~AddPersonDialog();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddPersonDialog *ui;

    personService personServ;
};

#endif // ADDPERSONDIALOG_H
