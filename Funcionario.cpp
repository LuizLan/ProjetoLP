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

int Funcionario::getTipo(){
    return tipo;
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
vector<double> Funcionario::getFolhaDePagamentoMes(){
    return folhaDePagamentoMes;
}

void Funcionario::setTipo(int T){
    tipo = T;
}
void Funcionario::setCodigo(string C){
    codigo = C;
}
void Funcionario::setNome(string N){
    nome = N;
}
void Funcionario::setEndereco(string E){
    endereco = E;
}
void Funcionario::setTelefone(string T){
    telefone = T;
}
void Funcionario::setDataIni(string D){
    dataIni = D;
}
void Funcionario::setDesignacao(string D){
    designacao = D;
}
void Funcionario::setSalario(double S){
    salario = S;
}
void Funcionario::setFolhaDePagamentoMes(double S, int M){
    folhaDePagamentoMes.at(M) = S;
}

string Funcionario::getAreaSup(){}
string Funcionario::getAreaForm(){}
string Funcionario::getNivelFormacao(){}

void Funcionario::setAreaSup(string A){}
void Funcionario::setAreaForm(string A){}
void Funcionario::setNivelFormacao(string N){}