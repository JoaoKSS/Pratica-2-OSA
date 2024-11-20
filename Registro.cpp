#include "Registro.h"
#include <cstring>
#include <algorithm>

Registro::Registro(string n, int i) : nome(n), idade(i) {
}

string Registro::serializar() const{
    string buffer(TAMANHO_NOME + sizeof(int), '\0'); // inicializar com '\0'
    memcpy(&buffer[0], nome.c_str(), min(nome.size(), (size_t)TAMANHO_NOME));
    memcpy(&buffer[TAMANHO_NOME], &idade, sizeof(int));
    return buffer;
}

void Registro::desserializar(const string& str) {
    nome = string(str.c_str(), TAMANHO_NOME); // limpa '\0' automaticamente
    nome.erase(remove(nome.begin(), nome.end(), '\0'), nome.end());
    memcpy(&idade, &str[TAMANHO_NOME], sizeof(int));
}