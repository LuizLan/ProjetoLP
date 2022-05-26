#include<iostream>
#include<string> //string
#include<vector> //vetor
#include<stdlib.h> //
#include<cstdlib> // num aleatorio
#include<ctime> //tempo

#pragma once

using namespace std;

class Funcionario{

public:
    Funcionario();
    Funcionario(int tipo,string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario); //construtor base para adicionar funcionarios
    ~Funcionario();

    void concederAumento();

    int getTipo();
    string getCodigo();
    string getNome();
    string getEndereco();
    string getTelefone();
    string getDataIni();
    string getDesignacao();
    double getSalario();
    vector<double> getPagamentoMes();

    void setTipo(int T);
    void setCodigo(string C);
    void setNome(string N);
    void setEndereco(string E);
    void setTelefone(string T);
    void setDataIni(string D);
    void setDesignacao(string D);
    void setSalario(double S);
    void setPagamentoMes(double S, int M);

    string getAreaSup();
    string getAreaForm();
    string getNivelFormacao();
    void setAreaSup(string A);
    void setAreaForm(string A);
    void setNivelFormacao(string N);

protected:
    string codigo, nome, endereco, telefone, dataIni, designacao, areaSup, areaForm, nivelFormacao;
    double salario;
    int tipo;

    vector<double> pagamentoMes = vector<double>(15);

private:

};