#include "cardinfo.h"
#include "ui_cardinfo.h"

CardInfo::CardInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardInfo)
{
    ui->setupUi(this);
}

CardInfo::~CardInfo()
{
    delete ui;
}
void CardInfo::on_pushButton_2_clicked()
{
    CardData cartaoAux;
    QString storeAux;

    //Salvando dados do cartão

    storeAux = ui->lineEdit_2->text();
    bool okMesAux, okYearAux, okSafeAux;
    cartaoAux.setMonthDeadline(storeAux.toShort(&okMesAux,10));

    storeAux = ui->lineEdit_4->text();
    cartaoAux.setYearDeadline(storeAux.toShort(&okYearAux,10));

    storeAux = ui->lineEdit_3->text();
    cartaoAux.setSafeCard(storeAux.toShort(&okSafeAux,10));

    hide();
}

void CardInfo::on_pushButton_clicked()
{
    hide();
}

CardData CardInfo::getCard()
{
    return cartao;
}

void CardInfo::setCard(CardData cardAux)
{
    cartao.setCardNumber(cardAux.getCardNumber());
    cartao.setMonthDeadline(cardAux.getMonthDeadline());
    cartao.setYearDeadline(cardAux.getYearDeadline());
    cartao.setSafeCard(cardAux.getSafeCard());
}
