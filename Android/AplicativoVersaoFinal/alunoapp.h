#ifndef ALUNOAPP_H
#define ALUNOAPP_H

#include "aluno.h"

class AlunoApp : public Aluno
{
    int Senha;
public:
    AlunoApp();

    void setSenha(int senhaAux);
    int getSenha();
};

#endif // ALUNOAPP_H
