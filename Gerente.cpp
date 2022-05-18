#include "Gerente.h"

Gerente::Gerente(){

}
Gerente::Gerente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup):
Funcionario(2, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaSup = areaSup;
}
Gerente::~Gerente(){

}

string Gerente::getAreaSup(){
    return areaSup;
}