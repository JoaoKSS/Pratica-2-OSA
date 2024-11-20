#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
using namespace std;

class Registro {
public:
    static const int TAMANHO_NOME = 40; // tamanho fixo para nome
    static const int TAMANHO_IDADE = 1; // tamanho fixo para idade 
    string nome;
    int idade;

    Registro(string n = "", int i = 0);
    string serializar() const;
    void desserializar(const string& str);
};

#endif