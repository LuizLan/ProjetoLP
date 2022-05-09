#include"Funcionario.h"

#pragma once

class Gerente:public Funcionario{

public:
    Gerente();
    Gerente(string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup);
    ~Gerente();

private:
    string areaSup;
};