#include "FolhaDePagamento.h"
#include <iostream>
#include <ctime>
#include "GerenciadorFuncionarios.h"
#include "Funcionario.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "TrataErros.h"
#include <iomanip>
#include <Windows.h>

using namespace std;

FolhaDePagamento::FolhaDePagamento():GerenciadorFuncionarios(){

}

FolhaDePagamento::~FolhaDePagamento()
{
    //dtor
}

TrataErros Trata; // chamada da classe com a função de tratar todos os tipos de erros possíveis do programa

int FolhaDePagamento::geraDias(){
    int dias;

    srand((unsigned) time(0));
    dias = (rand()%23);

    return dias;
}

int FolhaDePagamento::geraHorasExtras(){
    int horas;

    srand((unsigned) time(0));
    horas = (rand()%41);
    if(horas%2 == 0){
        return horas;
    }else{
        return 0;
    }
}

double FolhaDePagamento::calculaSalarioBruto(int dias, int horas, int indice, vector<Funcionario*> listaFuncionarios){
    double bruto, valorHoraExtra;

    valorHoraExtra = listaFuncionarios.at(indice)->getSalario()*2;
    bruto = (listaFuncionarios.at(indice)->getSalario()*8*dias);
    bruto += valorHoraExtra*horas;

    return bruto;
}

double FolhaDePagamento::descontaINSS(double bruto){
    double valor;

    if(bruto <= 1212.00){
        valor = bruto*0.075;
    }else if(bruto <= 2427.35){
        valor = 90.9 + ((bruto-1212)*0.09);
    }else if(bruto <= 3641.03){
        valor = 90.9 + 109.38 + ((bruto-2427.35)*0.12);
    }else if(bruto <= 7087.22){
        valor = 90.9 + 109.38 + 145.64 + ((bruto-3641.03)*0.14);
    }else{
        valor = 90.9 + 109.38 + 145.64 + 482.47;
    }
    return valor;
}

double FolhaDePagamento::descontaIR(double bruto, double inss){
    double valor;

    if(bruto <= 1903.98){
        valor = 0;
    }else if(bruto <= 2826.65){
        valor = (bruto-inss)*0.075 - 142.80;
    }else if(bruto <= 3751.05){
        valor = (bruto-inss)*0.15 - 354.80;
    }else if(bruto <= 4664.68){
        valor = (bruto-inss)*0.225 - 636.13;
    }else{
        valor = (bruto-inss)*0.275 - 869.36;
    }

    return valor;
}

void FolhaDePagamento::calculaFolhaMensal(vector<Funcionario*> listaFuncionarios){
    fstream fs;
    string dataFolha, mes, ano;
    int dias, horas, m, a, mesA, anoA; //m = mes, a = ano. Serão utilizados para verificar se o funcionário já estava trabalhando na data selecionada.
    double bruto, liquido, inss, ir, totalBruto = 0, totalLiquido = 0;

    cout << "____MENU DO CALCULO DA FOLHA DE PAGAMENTO____" << "\n\n";

    cout << "Digite o mes que sera calculado(01-12): " << endl;
    getline(cin, mes);
    cout << "Digite o ano que sera calculado(AAAA): " << endl;
    getline(cin, ano);

    dataFolha = mes + ano + "pagamento.txt";
    fs.open(dataFolha, fstream::in);

    if(fs.is_open()){
        cout << "Folha de pagamento desse mes anteriormente realizada. Voltando ao menu..." << endl;
        fs.close();
        Sleep(5);
        system("cls");
    }else{
        fs.open(dataFolha, fstream::out);

        if(!fs.is_open()){
            std::cout << "Erro ao abrir arquivo. Voltando ao menu...\n";
            Sleep(5);
            system("cls");
            return;
        }

        fs << "FOLHA DE PAGAMENTO DO MES " << mes << " E ANO " << ano << endl;

        mesA = stoi(mes); 
        anoA = stoi(ano);

        for(int i = 0; i < listaFuncionarios.size(); i++){
           
            m = stoi(listaFuncionarios.at(i)->getDataIni().substr(3, 4)); // terceira e quarta posição da string dd/>mm</aaaa
            a = stoi(listaFuncionarios.at(i)->getDataIni().substr(6)); // da posição 6 e adiante da string dd/mm/>aaaa<
            
            if(a <= anoA){         //Caso o funcionário não esteja ativo nesse ano.
                if(m <= mesA){     //Caso o funcionário não esteja ativo nesse mês.

                    dias = geraDias();
                    horas = geraHorasExtras();
                    bruto = calculaSalarioBruto(dias, horas, i, listaFuncionarios);
                    inss = descontaINSS(bruto);
                    ir = descontaIR(bruto, inss);
                    liquido = bruto - inss - ir;

                    totalBruto += bruto;
                    totalLiquido += liquido;

                    fs << listaFuncionarios.at(i)->getCodigo() << endl;
                    fs << listaFuncionarios.at(i)->getNome() << endl;
                    fs << setprecision(2) << fixed << bruto << endl;
                    fs << setprecision(2) << fixed << inss << endl;
                    fs << setprecision(2) << fixed << ir << endl;
                    fs << setprecision(2) << fixed << liquido << endl;

                }        
                
            }
           
        }
            fs << "=========" << endl;
            fs << totalBruto << endl;
            fs << totalLiquido << endl;

            fs.close();
            cout << "Folha de pagamento calculada com suceso. Retornando ao menu..." << endl;
            Sleep(5000);
            system("cls");
    }
}

int FolhaDePagamento::menuExibe(vector<Funcionario*> listaFuncionarios){
    string tipo;
    int opcao;

    while(1){

        cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO____\n\n";

        cout << "Digite o tipo de folha desejada: " << endl <<
                "1 - folha salarial mensal (funcionario)." << endl <<
                "2 - folha salarial mensal (empresa)." << endl <<
                "3 - folha salarial anual (empresa)." << endl <<
                "0 - voltar ao menu principal" << endl;
        cout << "-> ";
        getline(cin, tipo);

        if(tipo == "0"){ // caso o usuario digite "0", ele é levado ao menu
            cout << "\nVoltando...\n";
            system("cls");
            return 0;
        }else{
            system("cls");
            if(Trata.VerificaSeTemLetras(tipo)){ // chamada da função pertencente a classe TrataErros, que verifica se há alguma letra na entrada
                opcao = stoi(tipo); // converte o a variável string para int em outra variável caso a função acima confirme que não há letras na entrada
                if(Trata.VerificaNumero(opcao, 3)){ // chamada da função que verifica caso o valor digitado seja válido no menu
                    break;
                }
            }
        }
    }

    switch(opcao){
    case 1:
        system("cls");
        exibeFolhaSalario(listaFuncionarios);
        break;
    case 2:
        system("cls");
        exibeFolhaMensal();
        break;
    case 3:
        system("cls");
        exibeFolhaAnual();
        break;
    }

    return 0;
}

void FolhaDePagamento::exibeFolhaSalario(vector<Funcionario*> listaFuncionarios){
    if(Trata.VerificaFuncionario(listaFuncionarios.size())){ //chamada de função para verificar se existem funcionarios na empresa, caso o resultado seja falso, o programa retorna ao menu
        return;
    }
    fstream fs;
    string key, codigo, mes, ano, dataFolha, line;
    int menu, encontrado = 0;

    cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO DO FUNCIONARIO____\n\n";

    cout << "Digite o mes desejado (01 - 12): " << endl;
    cout << "-> ";
    getline(cin, mes);

    cout << "Digite o ano desejado (AAAA): " << endl;
    cout << "-> ";
    getline(cin, ano);

    system("cls");

    dataFolha = mes + ano + "pagamento.txt";
    
    fs.open(dataFolha, fstream::in);

    if(!fs.is_open()){
        cout << "\nA folha salarial nesta data ainda nao foi calculada.\n" << endl;
        system("pause");
        system("cls");
        return;
    }else{
        cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO DO FUNCIONARIO____\n\n";
        while(1){
            cout << "Digite como voce deseja buscar o funcionario: " << endl <<
            "1 - Nome(sensivel a CAPS): " << endl <<
            "2 - Codigo: " << endl <<
            "0 - Voltar para o menu principal" << endl;

            cin >> menu;
            cin.ignore();

            if(menu == 0){ // caso o usuario digite "0", ele é levado ao menu
                cout << "\nVoltando...\n";
                system("cls");
                return;
            }

            switch (menu){
            case 1:{ //nome
                system("cls");
                cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO DO FUNCIONARIO____\n\n";
                cout << "Insira o nome do Funcionario a ser procurado: " << endl;
                getline(cin, key);

                while(!fs.eof()){//busca na folha de pagamento o nome lido usando .find()
                    getline(fs, line);
                    if (line.find(key) != string::npos){
                        cout << "\n=======================================" << endl;
                        cout << "Nome do funcionario: " << line << endl;
                        getline(fs, line);
                        cout << "Salario Bruto: R$ " << line << endl;
                        getline(fs, line);
                        cout << "Descontos: \n" << "   -Previdencia Social: R$ " << line << endl;
                        getline(fs, line);
                        cout << "   -Imposto de Renda: R$ " << line <<endl;
                        getline(fs, line);
                        cout << "Salario Liquido: R$ " << line << endl;
                        cout << "=======================================\n" << endl;

                        encontrado++;
                    }
                }
                if (encontrado==0){
                    cout << "nenhum funcionario encontrado" << endl;
                }
                system("pause");
                system("cls");
                return;
            }
            case 2:{
                system("cls");
                cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO DO FUNCIONARIO____\n\n";
                cout << "Insira o codigo do Funcionario a ser procurado: " << endl;
                getline(cin, key);

                while(!fs.eof()){//busca na folha de pagamento o codigo lido usando .find()
                    getline(fs, line);
                    if (line.find(key) != string::npos){
                        cout << "\n=======================================" << endl;
                        cout << "Codigo do funcionario: " << line << endl;
                        getline(fs, line);
                        cout << "Nome do funcionario: " << line << endl;
                        getline(fs, line);
                        cout << "Salario Bruto: R$ " << line << endl;
                        getline(fs, line);
                        cout << "Descontos: \n" << "   -Previdencia Social: R$ " << line << endl;
                        getline(fs, line);
                        cout << "   -Imposto de Renda: R$ " << line <<endl;
                        getline(fs, line);
                        cout << "Salario Liquido: R$ " << line << endl;
                        cout << "=======================================\n" << endl;

                        encontrado++;
                    }
                }
                if (encontrado == 0){
                    cout << "nenhum funcionario encontrado" << endl;
                }
                system("pause");
                system("cls");
                return;
            }
            }
        }
    }
}

 void FolhaDePagamento::exibeFolhaMensal(){
    string line, mes, ano, dataFolha;
    fstream fs;

    cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO DA EMPRESA (MENSAL)____\n\n";

    cout << "Digite o mes que sera exibido(01 - 12): " << endl;
    cout << "-> ";
    getline(cin, mes);

    cout << "Digite o ano que sera exibido(AAAA): " << endl;
    cout << "-> ";
    getline(cin, ano);

    dataFolha = mes + ano + "pagamento.txt";

    fs.open(dataFolha, fstream::in);

    system("cls");

    if(fs.is_open()){
        getline(fs, line);
        cout << "\n==========="<< line << "===========\n" << endl;
        getline(fs, line);

        while (!fs.eof()){
            cout << "Codigo do funcionario: " << line << endl;
            getline(fs, line);
            cout << "Nome do funcionario: " << line << endl;
            getline(fs, line);
            cout << "Salario Bruto: R$ " << line << endl;
            getline(fs, line);
            cout << "Descontos: \n" << "   -Previdencia Social: R$ " << line << endl;
            getline(fs, line);
            cout << "   -Imposto de Renda: R$ " << line <<endl;
            getline(fs, line);
            cout << "Salario Liquido: R$ " << line << endl;
            cout << "=======================================\n" << endl;
            getline(fs, line);

            if(line == "========="){
                getline(fs, line);
                cout << "Soma total dos salarios brutos pagos: R$" << line << endl;
                getline(fs, line);
                cout << "Soma total dos salarios liquidos pagos: R$" << line << endl << endl;
                break;

            }
        }
        system("pause");
        system("cls");

    }else{
        cout << "Erro ao abrir arquivo." << endl;
        system("pause");
        system("cls");
        return;
    }

    fs.close();
 }

 void FolhaDePagamento::exibeFolhaAnual(){
    string linha, ano, mes, data;
    fstream fs;
    double totalBruto = 0, totalLiquido = 0;

    cout << "____MENU DE EXIBICAO DA FOLHA DE PAGAMENTO DA EMPRESA (ANUAL)____\n\n";

    cout << "Digito o ano desejado (AAAA)" << endl;
    getline(cin, ano);

    system("cls");

    cout << "\n===========Folha de Pagamento Anual (" << ano << ")===========\n" << endl;

    for(int i = 0; i < 12; i++){

        std::stringstream out;
        out << (i+1);
        if(i < 9){
            mes = "0" + out.str();
        }else{
            mes = out.str();
        }

        data = mes + ano + "pagamento.txt";

        fs.open(data, fstream::in);

        if(fs.is_open()){
                getline(fs, linha);
                cout << linha << endl << endl;

            while(!fs.eof()){
                getline(fs, linha);
                if(linha == "========="){
                    getline(fs,linha);
                    cout << "Soma total dos salarios brutos pagos no mes: R$" << linha << endl;
                    //int n = linha.length() + 1;
                    char ar1[500];
                    strcpy(ar1, linha.c_str());
                    totalBruto += atof(ar1);

                    getline(fs,linha);
                    cout << "Soma total dos salarios liquidos pagos no mes: R$" << linha << endl <<
                    "=======================================\n" << endl;
                    //n = linha.length();
                    char ar2[500];
                    strcpy(ar2, linha.c_str());
                    totalLiquido += atof(ar2);
                }
            }

            fs.close();
        }else{
            cout << "Folha Salarial do mes " << mes << " ainda nao foi calculada." << endl <<
            "=======================================\n" << endl;
        }
    }
    cout << "\n==========Balanco Final De Pagamentos=========\n" << endl <<
    "Soma total dos salarios brutos pagos no ano de " << ano << ": R$" << totalBruto << endl <<
    "Soma total dos salarios liquidos pagos no ano de " << ano << ": R$" << totalLiquido << endl << endl;

    system("pause");
    system("cls");

    return;
}