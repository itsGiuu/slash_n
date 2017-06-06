#include "alunoapp.h"

AlunoApp::AlunoApp()
{
    Nome = "Empty";
    Matricula = 10;
    creditsCard = 0;
    creditsMobile = 0;
    Senha = 1010;
}

void AlunoApp::setSenha(int senhaAux)
{
    Senha = senhaAux;
}

int AlunoApp::getSenha()
{
    return Senha;
}
