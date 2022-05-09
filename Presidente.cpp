#include "Presidente.h"

Presidente::Presidente(){

}
Presidente::Presidente(string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaForm, string nivelFormacao):
Funcionario( nome, endereco, telefone, dataIni, designacao, salario){
    this->areaForm = areaForm;
    this->nivelFormacao = nivelFormacao;
}
Presidente::~Presidente(){

}