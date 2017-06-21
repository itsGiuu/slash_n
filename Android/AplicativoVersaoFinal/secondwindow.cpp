#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    QString aux;
    aux.setNum(aluno.getCreditsCard(),'g', 1);
    ui->labelCreditsCard->setText(aux);
    aux.setNum(aluno.getCreditsMobile(),'g', 1);
    ui->labelCreditsMobile->setText(aux);

    ui->warningLabelRU->clear();

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
        registerCard->show();
    }
}

void SecondWindow::on_pushButton_clicked()
{
    if(!addCreditsMobile->isVisible() ){
        addCreditsMobile->setIsCard(false);
        addCreditsMobile->setCartao(getCard());
        addCreditsMobile->show();
    }
}

void SecondWindow::on_pushButton_2_clicked()
{
    if(!addCreditsCard->isVisible()){
        addCreditsCard->setIsCard(true);
        addCreditsCard->setCartao(getCard());
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

void SecondWindow::setLedInput(int aux)
{
    ledInput = aux;
}

void SecondWindow::setAluno(AlunoApp aux)
{
    aluno = aux;
}

int SecondWindow::getLedInput()
{
    return ledInput;
}

AlunoApp SecondWindow::getAluno()
{
    return aluno;
}

void SecondWindow::on_pushButton_3_clicked()
{
    char ledInputAux [6];
    int i = 0, ledAux2;

    ledInputAux[0] = ui->LED0->isChecked();
    ledInputAux[1] = ui->LED1->isChecked();
    ledInputAux[2] = ui->LED2->isChecked();
    ledInputAux[3] = ui->LED3->isChecked();
    ledInputAux[4] = ui->LED4->isChecked();
    ledInputAux[5] = ui->LED5->isChecked();

    for (i = 0; i < 6; i++)
    {
        ledAux2 = (ledInputAux[i] - '0')*2^i;
    }

    setLedInput(ledAux2);

    QString Error;
    bool ok;
    socketESP.requestAccess(aluno.getMatricula(), getLedInput(), &Error, ok);

    if(ok == true)
    {
        aluno.setCreditsMobile(aluno.getCreditsMobile()-1.5);
        ui->warningLabelRU->clear();
    }
    else{
        ui->warningLabelRU->setText("Algo deu errado!");
    }

}
