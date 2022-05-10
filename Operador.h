#include"Funcionario.h"

#pragma once

class Operador:public Funcionario{

public:
    Operador();
    Operador(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario); // construtor para adiconar operador
    ~Operador();

    void adicionarFuncionario();
    void exibirFuncionario();

private:

};