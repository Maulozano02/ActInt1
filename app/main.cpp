
// Mauricio Lozano Zarate A00833216
// Aleksandra Stupiec A00835071
// Enrique Macías López A01641402

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "config.hpp"
#include "../src/functions.h"


using namespace std;

// Función para leer un archivo y retornar su contenido
string leerArchivo(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error abriendo el archivo: " << filename << endl;
        return "";
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

// Función para verificar códigos maliciosos en una transmisión
void verificarCodigosMaliciosos(const string& transmission, const vector<string>& mcodes) {
    size_t pos;
    for (const auto& mcode : mcodes) {
        cout << (contieneCodigo(transmission, mcode, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    }
}

// Función para procesar y mostrar el palíndromo más largo
void mostrarPalindromo(const string& transmission) {
    auto resultado = palindromoMasLargo(transmission);
    cout << resultado.first.first << " " << resultado.first.second << " " << resultado.second << endl;
}

// Función para procesar y mostrar la subsecuencia común más larga entre dos transmisiones
void mostrarSubsecuenciaComun(const string& transmission1, const string& transmission2) {
    auto resultado = subsecuenciaComunMasLarga(transmission1, transmission2);
    cout << resultado.first.first << " " << resultado.first.second << " " << resultado.second << endl;
}

int main() {
    // Leer archivos
    string transmission1 = leerArchivo("transmission1.txt");
    string transmission2 = leerArchivo("transmission2.txt");

    vector<string> mcodes = {
        leerArchivo("mcode1.txt"),
        leerArchivo("mcode2.txt"),
        leerArchivo("mcode3.txt")
    };

    // Verificar si los archivos se cargaron correctamente
    if (transmission1.empty() || transmission2.empty() || mcodes[0].empty() || mcodes[1].empty() || mcodes[2].empty()) {
        cerr << "Error: Uno o más archivos no se pudieron cargar correctamente." << endl;
        return 1;
    }

    // Parte 1: Verificar códigos maliciosos
    cout << "Resultados para transmission1:" << endl;
    verificarCodigosMaliciosos(transmission1, mcodes);

    cout << "Resultados para transmission2:" << endl;
    verificarCodigosMaliciosos(transmission2, mcodes);

    // Parte 2: Palíndromos más largos
    cout << "Palíndromo más largo en transmission1:" << endl;
    mostrarPalindromo(transmission1);

    cout << "Palíndromo más largo en transmission2:" << endl;
    mostrarPalindromo(transmission2);

    // Parte 3: Subsecuencia común más larga
    cout << "Subsecuencia común más larga entre transmission1 y transmission2:" << endl;
    mostrarSubsecuenciaComun(transmission1, transmission2);

    return 0;
}
