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

    vector<Funcionario*> getListaFuncionarios();

    int cadastrarFuncionario();    
    int editarFuncionario();
    int excluirFuncionario();

    void exibirFuncionario(int indice);
    void exibirTodosFuncionarios();
    void buscarFuncionario(int menu);

    void concederAumento();
    void calcularFolhaDePagamento(int mes);
    void exibirFolhaDePagamento();

protected:

private:
    vector<Funcionario*> listaFuncionarios;
    int folhasFeitas[15] = {};
};