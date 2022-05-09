#include"Funcionario.h"

#pragma once

class Presidente:public Funcionario{

public:
    Presidente();
    Presidente(string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaForm, string nivelFormacao);
    ~Presidente();

private:
    string areaForm, nivelFormacao;
};