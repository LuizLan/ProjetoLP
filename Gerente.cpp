#include "Gerente.h"

Gerente::Gerente(){

}
Gerente::Gerente(string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup):
Funcionario( nome, endereco, telefone, dataIni, designacao, salario){
    this->areaSup = areaSup;
}
Gerente::~Gerente(){

}