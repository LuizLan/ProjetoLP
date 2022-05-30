#include"Funcionario.h"

#pragma once

class Gerente:public Funcionario{

public:
    Gerente();
    Gerente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup); //construtor para adicionar gerente, area de supervisao como informação adicional
    ~Gerente();

    void concederAumento(); //aumento de 10%

    string getAreaSup(); //get e set para as area de supervisao
    void setAreaSup(string A);
    
private:
    string areaSup; // areaSup = area de supervisao
};