#include<iostream>
#include<string>
#include<vector>

#pragma once

using namespace std;

class Funcionario{

public:
    Funcionario();
    Funcionario(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario); //construtor base para adicionar funcionarios
    ~Funcionario();

    virtual void editarFuncionario() = 0;
    virtual void exibirFuncionario() = 0;
    virtual void excluiFuncionario() = 0;

    string getCodigo();
    string getNome();
    string getEndereco();
    string getTelefone();
    string getDataIni();
    string getDesignacao();
    double getSalario();

private:

    string codigo, nome, endereco, telefone, dataIni, designacao;
    double salario;

};