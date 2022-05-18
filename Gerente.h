#include"Funcionario.h"

#pragma once

class Gerente:public Funcionario{

public:
    Gerente();
    Gerente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup); //construtor para adicionar gerente, area de supervisao como informação adicional
    ~Gerente();

    string getAreaSup();

private:
    string areaSup;
};