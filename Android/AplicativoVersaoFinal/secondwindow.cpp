#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    registerCard = new CardInfo(this);
    addCreditsMobile = new AddCredits(this);
    addCreditsCard = new AddCredits(this);
    appInfo = new ExtraInfo(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_toolButton_clicked()
{
    if(!registerCard->isVisible()){
        registerCard -> show();
    }
}

void SecondWindow::on_pushButton_clicked()
{
    if(!addCreditsMobile->isVisible()){
        addCreditsMobile -> show();
    }
}

void SecondWindow::on_pushButton_2_clicked()
{
    if(!addCreditsCard->isVisible()){
        addCreditsCard -> show();
    }
}

void SecondWindow::on_toolButton_2_clicked()
{
    if(appInfo->isVisible()){
        appInfo -> hide();
    }else{
        appInfo -> show();
    }
}

CardData SecondWindow::getCard()
{
    return cartao;
}

void SecondWindow::setCard(CardData cardAux)
{
    cartao.setCardNumber(cardAux.getCardNumber());
    cartao.setMonthDeadline(cardAux.getMonthDeadline());
    cartao.setYearDeadline(cardAux.getYearDeadline());
    cartao.setSafeCard(cardAux.getSafeCard());
}
