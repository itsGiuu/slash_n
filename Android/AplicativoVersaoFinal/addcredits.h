#ifndef ADDCREDITS_H
#define ADDCREDITS_H

#include "creditstoadd.h"
#include <QDialog>
#include <QLineEdit>
#include <QString>

namespace Ui {
class AddCredits;
}

class AddCredits : public QDialog
{
    Q_OBJECT

public:
    explicit AddCredits(QWidget *parent = 0);
    ~AddCredits();
    CreditsToAdd amount;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddCredits *ui;

};

#endif // ADDCREDITS_H
