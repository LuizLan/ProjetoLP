#include "Diretor.h"

Diretor::Diretor(){

}
Diretor::Diretor(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup, string areaForm):
Funcionario(3, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaForm = areaForm;
    this->areaSup = areaSup;
    this->nivelFormacao = "0";
}
Diretor::~Diretor(){

}

void Diretor::concederAumento(){
    double salario;
    
    salario = getSalario()*1.20;

    setSalario(salario);
}