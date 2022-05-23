#include"Funcionario.h"

#pragma once

class Presidente:public Funcionario{

public:
    Presidente();
    Presidente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaForm, string nivelFormacao);//construtor para iniciar um presidente, com as informações adicionais area de formação e nivel de formação academica
    ~Presidente();

    void concederAumento();

    string getAreaForm();
    string getNivelFormacao();
    void setAreaForm(string A);
    void setNivelFormacao(string N);

private:
    string areaForm, nivelFormacao;
};