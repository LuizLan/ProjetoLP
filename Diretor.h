#include"Funcionario.h"

#pragma once

class Diretor:public Funcionario{

public:
    Diretor();
    Diretor(string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup, string areaForm);
    ~Diretor();

private:
    string areaSup, areaForm;
};