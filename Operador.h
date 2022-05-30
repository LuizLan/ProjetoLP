#include"Funcionario.h"

#pragma once

class Operador:public Funcionario{ //herda a classe funcionario

public:
    Operador();
    Operador(string codigo, string nome, string endereco, string telefone, string dataIni, string designacao, double salario); // construtor para adiconar operador
    ~Operador();

    void concederAumento(); // aumento de 5%
    
private:

};