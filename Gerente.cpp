#include "Gerente.h"

Gerente::Gerente(){

}
Gerente::Gerente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup):
Funcionario(2, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaSup = areaSup;
    this->areaForm = "0";
    this->nivelFormacao = "0";
}
Gerente::~Gerente(){

}