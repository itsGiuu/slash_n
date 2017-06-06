#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Salvando as entradas de texto
    QString storeAux = ui->lineEdit->text();
    bool okAux1, okAux2;
    this->setMatriculaDigitada(storeAux.toULong(&okAux1, 10));

    storeAux = ui->lineEdit_2->text();
    this->setSenhaDigitada(storeAux.toInt(&okAux2, 10));

    if(this->checkLogin()){
        //Abrindo a nova janela
        loggedWindow =  new SecondWindow(this);
        loggedWindow -> showMaximized();
    }
}

void MainWindow::getAluno(AlunoApp alunoAux)
{
    aluno = alunoAux;
}

void MainWindow::setSenhaDigitada(int senhaAux)
{
    senhaDigitada = senhaAux;
}

void MainWindow::setMatriculaDigitada(ulong matriculaAux)
{
    matriculaDigitada = matriculaAux;
}

bool MainWindow::checkLogin()
{
    bool returnAux;

    if (senhaDigitada == aluno.getSenha() && matriculaDigitada == aluno.getMatricula())
        returnAux = true;
    else
        returnAux = false;

    return returnAux;
}
