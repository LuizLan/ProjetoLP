#include"Funcionario.h"

#pragma once

class Diretor:public Funcionario{

public:
    Diretor();
    Diretor(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup, string areaForm); //construtor para iniciar um diretor, com as informações adicionais area de supervisao e area de formação
    ~Diretor();

    string getAreaSup();
    string getAreaForm();
    

private:
    string areaSup, areaForm;
};