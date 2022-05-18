#include "Funcionario.h"

Funcionario::Funcionario(){

}
Funcionario::Funcionario(int tipo,string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario){
    this -> tipo = tipo;
    this->codigo = codigo;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone=telefone;
    this->dataIni = dataIni;
    this->designacao = designacao;
    this->salario = salario;
}
Funcionario::~Funcionario(){

}

string Funcionario::getCodigo(){
    return codigo;
}
string Funcionario::getNome(){
    return nome;
}
string Funcionario::getEndereco(){
    return endereco;
}
string Funcionario::getTelefone(){
    return telefone;
}
string Funcionario::getDataIni(){
    return dataIni;
}
string Funcionario::getDesignacao(){
    return designacao;
}
double Funcionario::getSalario(){
    return salario;
}