#include "Presidente.h"

Presidente::Presidente(){

}
Presidente::Presidente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaForm, string nivelFormacao):
Funcionario(4, codigo, nome, endereco, telefone, dataIni, designacao, salario){
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

string Presidente::getAreaForm(){
    return areaForm;
}
string Presidente::getNivelFormacao(){
    return nivelFormacao;
}

void Presidente::setAreaForm(string A){
    areaForm = A;
}
void Presidente::setNivelFormacao(string N){
    nivelFormacao = N;
}