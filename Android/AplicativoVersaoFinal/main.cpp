#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AlunoApp aluno;

    aluno.setMatricula(14101336);
    aluno.setSenha(1010);

    w.getAluno(aluno);

    w.show();

    return a.exec();
}
