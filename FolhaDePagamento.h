#include"GerenciadorFuncionarios.h"

#pragma once

class FolhaDePagamento{

public:
    FolhaDePagamento();
    virtual ~FolhaDePagamento();

    void calcularFolhaDePagamento(GerenciadorFuncionarios gerenciador);

protected:

private:
    vector<double> folhaDePagamento;
};