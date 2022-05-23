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

    int excluirFuncionario();

    void exibirFuncionario(int indice);
    void exibirTodosFuncionarios();

    void buscarFuncionario(int menu);

    void concederAumento();

protected:

private:
    vector<Funcionario*> listaFuncionarios;

};