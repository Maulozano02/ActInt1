
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

int main() {
    // Archivos a cargar
    vector<string> archivos = {
        "transmission1.txt",
        "transmission2.txt",
        "mcode1.txt",
        "mcode2.txt",
        "mcode3.txt"
    };

    // Contenido de los archivos
    vector<string> contenidos;

    // Verificar y cargar los archivos
    if (!verificarArchivos(archivos, contenidos)) {
        return 1;
    }

    // Dividir el contenido en variables
    string transmission1 = contenidos[0];
    string transmission2 = contenidos[1];
    vector<string> mcodes = {contenidos[2], contenidos[3], contenidos[4]};

    // Parte 1: Verificar códigos maliciosos
    cout << "Resultados para transmission1:" << endl;
    verificarCodigosMaliciosos(transmission1, mcodes);

    cout << "Resultados para transmission2:" << endl;
    verificarCodigosMaliciosos(transmission2, mcodes);

    // Parte 2: Mostrar palíndromos más largos
    cout << "Palíndromo más largo en transmission1:" << endl;
    mostrarPalindromo(transmission1);

    cout << "Palíndromo más largo en transmission2:" << endl;
    mostrarPalindromo(transmission2);

    // Parte 3: Mostrar subsecuencia común más larga
    cout << "Subsecuencia común más larga entre transmission1 y transmission2:" << endl;
    mostrarSubsecuenciaComun(transmission1, transmission2);

    return 0;
}
