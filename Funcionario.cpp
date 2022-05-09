#include "Funcionario.h"

Funcionario::Funcionario(){

}
Funcionario::Funcionario(string nome, string endereco, string telefone, string dataIni, string designacao, double salario){
    this->nome = nome;
    this->endereco = endereco;
    this->telefone=telefone;
    this->dataIni = dataIni;
    this->designacao = designacao;
    this->salario = salario;
}
Funcionario::~Funcionario(){

}