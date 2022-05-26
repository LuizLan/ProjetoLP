#include "Presidente.h"

Presidente::Presidente(){

}
Presidente::Presidente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaForm, string nivelFormacao):
Funcionario(4, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaSup = "0";
    this->areaForm = areaForm;
    this->nivelFormacao = nivelFormacao;
}
Presidente::~Presidente(){

}
void Presidente::concederAumento(){
    double salario;
    
    salario = getSalario()*1.30;

    setSalario(salario);
}