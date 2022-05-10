#include "Diretor.h"

Diretor::Diretor(){

}
Diretor::Diretor(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaSup, string areaForm):
Funcionario(codigo, nome, endereco, telefone, dataIni, designacao, salario){
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

void Diretor::exibirFuncionario(){
    cout << "Exibindo operario: " << getCodigo() << " de nome: " << getNome() << endl;
    cout << "-Endereco: " << getEndereco() << endl;
    cout << "-Telefone: " << getTelefone() << endl;
    cout << "-Data de ingresso: " << getDataIni() << " -Designação: " << getDesignacao() << endl;
    cout << "-Area de supervisão: " << getAreaSup() << " -Area de formação: " << getAreaForm() << endl;
    cout << "-Salário: R$ " << getSalario() << endl;
}