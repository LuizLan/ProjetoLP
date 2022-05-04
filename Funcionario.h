#include<iostream>
#include<string>

#pragma once

using namespace std;

class Funcionario{

public:
    Funcionario();
    ~Funcionario();

private:

    string nome, endereco, telefone, dataIni, designacao;
    double salario;

};