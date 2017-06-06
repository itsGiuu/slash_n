#include "addcredits.h"
#include "ui_addcredits.h"

AddCredits::AddCredits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCredits)
{
    ui->setupUi(this);
}

AddCredits::~AddCredits()
{
    delete ui;
}

void AddCredits::on_pushButton_2_clicked()
{
    QString storeAux = ui->lineEdit->text();
    bool ok;
    amount.setAmount(storeAux.toFloat(&ok));
    hide();
}

void AddCredits::on_pushButton_clicked()
{
    hide();
}
