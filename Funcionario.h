#include<iostream> //biblioteca padrao
#include<string> //string
#include<vector> //vetor
#include<cstdlib> //num aleatorio
#include<ctime> //tempo
#include<locale.h>

#pragma once

using namespace std;

class Funcionario{

public:
    Funcionario();
    Funcionario(int tipo,string codigo, string nome, string CEP, string numeroCasa, string telefone, string dataIni, string designacao, double salario); //construtor base para adicionar funcionarios
    ~Funcionario();

    virtual void concederAumento() = 0;

    int getTipo(); //funções get
    string getCodigo();
    string getNome();
    string getCEP();
    string getNumeroCasa();
    string getTelefone();
    string getDataIni();
    string getDesignacao();
    double getSalario();

    void setTipo(int T); //funcções set
    void setCodigo(string C);
    void setNome(string N);
    void setCEP(string C);
    void setNumeroCasa(string N);
    void setTelefone(string T);
    void setDataIni(string D);
    void setDesignacao(string D);
    void setSalario(double S);

    virtual string getAreaSup(); //funcções get e set especificas para gerente+
    virtual string getAreaForm();
    virtual string getNivelFormacao();
    virtual void setAreaSup(string A);
    virtual void setAreaForm(string A);
    virtual void setNivelFormacao(string N);

protected:
    string codigo, nome, CEP, numeroCasa, telefone, dataIni, designacao; // dataIni = data inicialização, designação = operador, gerente, diretor, presidente
    double salario;
    int tipo; // 1 = operador,2 = gerente,3 = diretor,4 = presidente

private:

};