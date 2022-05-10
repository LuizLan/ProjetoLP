#include "Gerente.h"

Gerente::Gerente(){

}
Gerente::Gerente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup):
Funcionario(codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaSup = areaSup;
}
Gerente::~Gerente(){

}

string Gerente::getAreaSup(){
    return areaSup;
}

void Gerente::exibirFuncionario(){
    cout << "Exibindo operario: " << getCodigo() << " de nome: " << getNome() << endl;
    cout << "-Endereco: " << getEndereco() << endl;
    cout << "-Telefone: " << getTelefone() << endl;
    cout << "-Data de ingresso: " << getDataIni() << " -Designação: " << getDesignacao() << endl;
    cout << "-Area de supervisão: " << getAreaSup() << endl;
    cout << "-Salário: R$ " << getSalario() << endl;
}