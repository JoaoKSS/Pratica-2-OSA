#include "Buffer.h"

bool Buffer::lerRegistro(ifstream& in, Registro& reg) {
    string buffer(Registro::TAMANHO_NOME + sizeof(int), '\0');
    if (!in.read(reinterpret_cast<char*>(&buffer[0]), buffer.size())) return false;
    reg.desserializar(buffer);
    return true;
}

bool Buffer::escreverRegistro(ofstream& out, const Registro& reg) {
    string buffer = reg.serializar();
    out.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
    out.put('\n');
    return out.good();  // retorna true se a operação foi sucedida
}
