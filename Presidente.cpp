#include "Presidente.h"

Presidente::Presidente(){

}
Presidente::Presidente(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario, string areaForm, string nivelFormacao):
Funcionario(codigo, nome, endereco, telefone, dataIni, designacao, salario){
    this->areaForm = areaForm;
    this->nivelFormacao = nivelFormacao;
}
Presidente::~Presidente(){

}

string Presidente::getAreaForm(){
    return areaForm;
}
string Presidente::getNivelFormacao(){
    return nivelFormacao;
}

void Presidente::exibirFuncionario(){
    cout << "Exibindo operario: " << getCodigo() << " de nome: " << getNome() << endl;
    cout << "-Endereco: " << getEndereco() << endl;
    cout << "-Telefone: " << getTelefone() << endl;
    cout << "-Data de ingresso: " << getDataIni() << " -Designação: " << getDesignacao() << endl;
    cout << "-Area de formação: " << getAreaForm() << " -Nivel de formação: " << getNivelFormacao() << endl;
    cout << "-Salário: R$ " << getSalario() << endl;
}