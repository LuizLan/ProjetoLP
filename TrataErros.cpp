#include "TrataErros.h"
#include<fstream>

TrataErros::TrataErros(){}
TrataErros::~TrataErros(){}

bool TrataErros::VerificaSeTemLetras(string str) { //função para verificar se uma string possui letras, usada para tratamento de excessão

    if(str.size() == 0){
        cout << "Entrada Invalida\nTente Novamente\n\n";
        return false;
    }

    for (int i = 0; i < str.size(); i++){
        if (std::isdigit(str[i]) == 0){
            cout << "\nEssa entrada não permite nenhum tipo de letras!!\nTente Novamente\n\n";
            return false;
        }
    }
        return true;
}

bool TrataErros::VerificaNumero(int tipo, int tam){ //função para verificar se uma opção de menu é válida

    if(tipo < 1 || tipo > tam){
        cout << "\nEsse número não é válido!\nTente Novamente\n\n";
        return false;
    }

    return true;
}

bool TrataErros::VerificaCEP(string CEP){

    string linha, url, mensagem = "O CEP está incorreto, verifique se digitou corretamente"; // mensagem de erro
    fstream fs;
    string verificaErro;
    int i = 0;

    if(CEP.size() < 8 || CEP.size() > 9){
        cout << mensagem << endl;
        return false;
    }

    for(int i = 0; i < CEP.size(); i++){

        if(CEP.size() == 9){
            if(CEP[5] != '-'){
                cout << mensagem << endl;
                return false;
            }
            else{
                if (std::isdigit(CEP[i]) == 0 && i != 5){
                    cout << mensagem << endl;
                    return false;
                }
            }
        }
        else{
            if (std::isdigit(CEP[i]) == 0){ // verifica se em qualquer posição da string data há algum caractere que não seja um número
                cout << mensagem << endl; // caso não haja número em qualquer posição da string data, uma mensagem de erro retorna ao usuário
                return false;
            }
        }
    }

    url = "https://viacep.com.br/ws/" + CEP +"/json/";

    system(("wget -q -O cep.txt " + url).c_str());

    fs.open("cep.txt", fstream::in);

    if (!fs.is_open()){
        cout << "Erro\n";
        return false;
    }

    while(!fs.eof()){
        getline(fs, linha);
        if(i == 1 || i == 2 || i == 4 || i == 5 || i== 6){

            verificaErro = linha.substr(3, linha.size()-12);

            if(verificaErro == "erro"){
                cout << mensagem << endl;
                return false;
            }
            else{
                return true;
            }
        }
        i++;
    }
    fs.close();
    return true;
}

bool TrataErros::VerificaSeDataExiste(int dia, int mes, int ano){ // função que verifica se o dia, mês, ou ano inserido existe, caso não, o usuário recebe uma mensagem de erro

    string mensagem = "A data está incorreta, verifique se digitou corretamente"; // mensagem de erro

    if (ano > 9999 || ano < 1940){ // 9999 a data maxima que um usuario pode ser cadastrado e 1940 a data minima, pois ultrapassa a idade de trabalho
        cout << "Você ultrapassou a idade para trabalhar.\nTente digitar uma data acima de 1940\n";
        return false; // e o programa entra novamente no laço de repetição pedindo ao usuário que digite uma data válida, se aplicando a todos os "return false" desta função
    }
    if (mes < 1 || mes > 12){ // verifica se o mês inserido está entre 1 e 12
        cout << mensagem << endl;
        return false;
    }
    if (dia < 1 || dia > 31){ // verifica se o dia inserido está entre 0 e 31
        cout << mensagem << endl;
        return false;
    }
    if (mes == 2){ // caso o mês inserido seja, fevereiro, o programa não permite dias acima do valor 28
        if(dia > 28){
            cout << mensagem << endl;
            return false;
        }
    }
    else if(mes == 1 || mes == 3|| mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ // todos os meses com dias até 31
        if(dia > 31){
            cout << mensagem << endl;
            return false;
        }
    }
    else{ // como todos os outros meses fora fevereiro, possuem dia até no máximo 31, os outros meses possuem dias até 30
        if(dia > 30){
            cout << mensagem << endl;
            return false;
        }
    }
    return true;
}

bool TrataErros::AnalisaDataValida(string data){
    while(1){ // laço de repetição para verificar se a data inserida é inválida

        string mensagem = "Data inválida, por favor digite a data no seguinte formato: DD/MM/AAAA\n"; // mensagem de erro

        if(data.size() != 10){ // if para verificar se a data foi inserida da meneira correta DD/MM/AAAA = 10 caracteres
            cout << mensagem; // mensagem de erro que sera transmitida ao usuário caso a data seja inserida incorretamente
            return false; // e o programa entra novamente no laço de repetição pedindo ao usuário que digite uma data válida, se aplicando a todos os "return false" desta função
        }
        else{
            for(int i = 0; i < data.size(); i++){

                if(i == 2 || i == 5){ // caso exista '/' na posição 2 e 5 dd/mm/aaaa, esse caractere é pulado para a verificação abaixo
                    i++; // incrementa o valor de "i" no laço for
                }
                if (std::isdigit(data[i]) == 0){ // verifica se em qualquer posição da string data há algum caractere que não seja um número
                    cout << mensagem << endl; // caso não haja número em qualquer posição da string data, uma mensagem de erro retorna ao usuário
                    return false;
                }
            }
            if(data[2] == '/' && data[5] == '/'){ // pra verificar se a "/" está colocada de maneira correta na data inserida
                    return true; // caso sim, o programa funciona normalmente
            }
            else{
                cout << mensagem; // caso não, a mensagem de erro é passada
                return false;
            }
        }
    }
}


bool TrataErros::VerificaFuncionario(int quantidade){ //função para verificar se existem funcionarios na empresa, caso nao exista o usuario volta ao menu

    if(quantidade == 0){
        cout << "\nNão existem funcionarios disponiveis\n"
                          "Redirecionando ao Menu...\n\n";
        return true;
    }
    else
        return false;;
}

bool TrataErros::TrataSalario(string salario){
    for(int i = 0; i < salario.size(); i++){
        if (std::isdigit(salario[i]) == 0 && salario[i] != ','){
            if(salario[i] == '.'){
                cout << "Caso haja casas decimais após o salário utilize ',' e não '.'\n";
                return false;
            }
            else{
                cout << "Salário inválido, tente digitar um salário válido!" << endl;
                return false;
            }
        }
    }
    return true;
}

bool TrataErros::VerificaTamanho(string str){
    if(str.size() == 0){
        cout << "Entrada Invalida\nTente Novamente\n\n";
        return false;
    }
    else{
        return true;
    }
}

bool TrataErros::VerificaTelefone(string telefone){
    if(telefone.size() < 11){
        cout << "Digite a data nesse formato DDD9XXXXXXXX ex: 83912345678\n";
        return false;
    }
    else
        return true;
}
