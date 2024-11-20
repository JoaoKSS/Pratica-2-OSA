#ifndef BUFFER_H
#define BUFFER_H

#include <fstream>
#include "Registro.h"
using namespace std;

class Buffer {
public:
    bool lerRegistro(ifstream& in, Registro& reg);
    bool escreverRegistro(ofstream& out, const Registro& reg);
};

#endif