#include "Diretor.h"

Diretor::Diretor(){

}
Diretor::Diretor(string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup, string areaForm):
Funcionario( nome, endereco, telefone, dataIni, designacao, salario){
    this->areaForm = areaForm;
    this->areaSup = areaSup;
}
Diretor::~Diretor(){

}