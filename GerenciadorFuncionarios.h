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

    int cadastrarFuncionario(int tipo);
    
    int editarFuncionario();

    void exibirFuncionarios();


protected:

private:
    vector<Funcionario*> listaFuncionarios;

};