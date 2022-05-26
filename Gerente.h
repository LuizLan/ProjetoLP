#include"Funcionario.h"

#pragma once

class Gerente:public Funcionario{

public:
    Gerente();
    Gerente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup); //construtor para adicionar gerente, area de supervisao como informação adicional
    ~Gerente();

    void concederAumento();

    string getAreaSup();
    void setAreaSup(string A);

private:
};