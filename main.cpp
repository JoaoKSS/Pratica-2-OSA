#include "Registro.h"
#include "Buffer.h"
#include "Arquivo.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    //Registro r1;

    Arquivo arquivo;
    vector<Registro> registros;

    // estrutura para chamar todos Nomes_idades
    for(int i = 1; i<=5; i++){
        registros = arquivo.lerCSV("Nomes_Idades_" + to_string(i) + ".csv"); // ler arquivo .CSV
        arquivo.escreverBinario("Nomes_Idades_" + to_string(i) + ".bin", registros); // escreve arquivo .bin
        arquivo.lerBinario("Nomes_Idades_" + to_string(i) + ".bin"); //ler aquivo .bin e mostra no console a leitura
        cout << endl;
    }
   
    return 0;

}
