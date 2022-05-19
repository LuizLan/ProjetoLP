#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

#pragma once

using namespace std;

class Funcionario{

public:
    Funcionario();
    Funcionario(int tipo,string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario); //construtor base para adicionar funcionarios
    ~Funcionario();

    int getTipo();
    string getCodigo();
    string getNome();
    string getEndereco();
    string getTelefone();
    string getDataIni();
    string getDesignacao();
    double getSalario();

    void setTipo(int T);
    void setCodigo(string C);
    void setNome(string N);
    void setEndereco(string E);
    void setTelefone(string T);
    void setDataIni(string D);
    void setDesignacao(string D);
    void setSalario(float S);

    virtual string getAreaSup();
    virtual string getAreaForm();
    virtual string getNivelFormacao();
    virtual void setAreaSup(string A);
    virtual void setAreaForm(string A);
    virtual void setNivelFormacao(string N);

private:

    string codigo, nome, endereco, telefone, dataIni, designacao;
    double salario;
    int tipo;

};