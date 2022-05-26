#include "Operador.h"

Operador::Operador(){

}
Operador::Operador(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario):
Funcionario(1, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaSup = "0";
    this->areaForm = "0";
    this->nivelFormacao = "0";
}
Operador::~Operador(){

}

void Operador::concederAumento(){
    double salario;
    
    salario = getSalario()*1.05;

    setSalario(salario);
}