#include"Funcionario.h"
#include"Operador.h"
#include"Gerente.h"
#include"Diretor.h"
#include"Presidente.h"

#pragma once

class GerenciadorFuncionarios{

public:
    GerenciadorFuncionarios();
    virtual ~GerenciadorFuncionarios();

    void cadastrarFuncionario(int tipo);

protected:

private:
    vector<Funcionario*> listaFuncionarios;

};