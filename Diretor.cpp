#include "Diretor.h"

Diretor::Diretor(){

}
Diretor::Diretor(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup, string areaForm):
Funcionario(3, codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaForm = areaForm;
    this->areaSup = areaSup;
}
Diretor::~Diretor(){

}

string Diretor::getAreaSup(){
    return areaSup;
}
string Diretor::getAreaForm(){
    return areaForm;
}
