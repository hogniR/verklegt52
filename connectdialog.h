#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include "personservice.h"

namespace Ui
{
    class connectDialog;
}

class connectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectDialog(QWidget *parent = 0);
    ~connectDialog();

private slots:
    void on_connectButton_clicked();

private:
    Ui::connectDialog *ui;

    personService personServ;
};

#endif // CONNECTDIALOG_H
