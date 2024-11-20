#include "Arquivo.h"
#include "Registro.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Registro> Arquivo::lerCSV(const string& filename) {
    vector<Registro> registros;
    ifstream file(filename);
     if (!file) {
        cerr << "Erro ao abrir o arquivo CSV: " << filename << endl;
        return registros;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nome;
        int idade;
        if (getline(ss, nome, ',') && (ss >> idade)) {
            registros.emplace_back(nome, idade);
        }
    }
    if (registros.empty()) {
        cerr << "Arquivo CSV está vazio ou não foi possível ler os registros." << endl;
    }
    return registros;
}

void Arquivo::escreverBinario(const string& filename, const vector<Registro>& registros) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Erro ao abrir o arquivo binário para escrita: " << filename << endl;
        return;
    }
    Buffer buffer;
    for (const auto& reg : registros) { 
        while(!buffer.escreverRegistro(file, reg)) {
            cerr << "Erro ao escrever registro no arquivo binário." << endl;
            return;
        }     
    }
    cout << "Arquivo binário '" << filename << "' escrito com sucesso!" << endl;
}

void Arquivo::lerBinario(const string& filename) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo binário para leitura." << endl;
        return;
    }

    Registro reg;
    cout << "\nRegistros lidos do arquivo binário:" << endl;

    while (true) {
        string bufferData(Registro::TAMANHO_NOME + sizeof(int), '\0'); // aloca o buffer para leitura

        inputFile.read(&bufferData[0], bufferData.size());
        
        if (inputFile.eof()) break; // verifica se chegou ao final do arquivo
        
        // verifica se o próximo caractere é uma nova linha 
        if (inputFile.peek() == '\n') {
            inputFile.get(); // le e descarta a nova linha
        }

        reg.desserializar(bufferData); // Desserializa o registro
        cout << "Nome: " << reg.nome << ", Idade: " << reg.idade << endl; 
    }

    inputFile.close();
}
