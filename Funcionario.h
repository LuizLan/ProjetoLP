#include<iostream>
#include<string>

#pragma once

using namespace std;

class Funcionario{

public:
    Funcionario();
    Funcionario(string nome, string endereco, string telefone, string dataIni, string designacao, double salario);
    ~Funcionario();

private:

    string nome, endereco, telefone, dataIni, designacao;
    double salario;

};