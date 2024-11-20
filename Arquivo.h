#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <vector>
#include "Registro.h"
#include "Buffer.h"
using namespace std;

class Arquivo {
public:
    vector<Registro> lerCSV(const string& filename);
    void escreverBinario(const string& filename, const vector<Registro>& registros);
    void lerBinario(const string& filename);
};

#endif