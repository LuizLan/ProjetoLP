#include "Operador.h"

Operador::Operador(){

}
Operador::Operador(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario):
Funcionario(1, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    
}
Operador::~Operador(){

}

void Operador::concederAumento(){
    double salario;

    salario = getSalario()*1.05;
    setSalario(salario);
}