#include "Operador.h"

Operador::Operador(){

}
Operador::Operador(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario):
Funcionario(codigo, nome, endereco, telefone, dataIni, designacao, salario){

}
Operador::~Operador(){

}

void Operador::exibirFuncionario(){
    cout << "Exibindo operario: " << getCodigo() << " de nome: " << getNome() << endl;
    cout << "-Endereco: " << getEndereco() << endl;
    cout << "-Telefone: " << getTelefone() << endl;
    cout << "-Data de ingresso: " << getDataIni() << " -Designação: " << getDesignacao() << endl;
    cout << "-Salário: R$ " << getSalario() << endl;
}