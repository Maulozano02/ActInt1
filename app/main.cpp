
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

// Helper function to open a file and return its content
string leerArchivo(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error abriendo el archivo: " << filename << endl;
        return "";
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

// Function to check for malicious codes in a transmission
void verificarCodigosMaliciosos(const string& transmission, const vector<string>& mcodes) {
    size_t pos;
    for (const auto& mcode : mcodes) {
        cout << (contieneCodigo(transmission, mcode, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    }
}

// Function to find and display the longest palindrome in a transmission
void mostrarPalindromo(const string& transmission) {
    auto resultado = palindromoMasLargo(transmission);
    cout << resultado.first.first << " " << resultado.first.second << " " << resultado.second << endl;
}

// Function to find and display the longest common subsequence between two transmissions
void mostrarSubsecuenciaComun(const string& transmission1, const string& transmission2) {
    auto resultado = subsecuenciaComunMasLarga(transmission1, transmission2);
    cout << resultado.first.first << " " << resultado.first.second << " " << resultado.second << endl;
}

int main() {
    // Load transmissions and malicious codes from files
    string transmission1 = leerArchivo("transmission1.txt");
    string transmission2 = leerArchivo("transmission2.txt");

    vector<string> mcodes = {
        leerArchivo("mcode1.txt"),
        leerArchivo("mcode2.txt"),
        leerArchivo("mcode3.txt")
    };

    // Validate if all files were loaded correctly
    if (transmission1.empty() || transmission2.empty() || mcodes[0].empty() || mcodes[1].empty() || mcodes[2].empty()) {
        cerr << "Error: Uno o más archivos no se pudieron cargar correctamente." << endl;
        return 1;
    }

    // Part 1: Check for malicious codes in transmissions
    cout << "Resultados para transmission1:" << endl;
    verificarCodigosMaliciosos(transmission1, mcodes);

    cout << "Resultados para transmission2:" << endl;
    verificarCodigosMaliciosos(transmission2, mcodes);

    // Part 2: Find and display the longest palindrome in each transmission
    cout << "Palíndromo más largo en transmission1:" << endl;
    mostrarPalindromo(transmission1);

    cout << "Palíndromo más largo en transmission2:" << endl;
    mostrarPalindromo(transmission2);

    // Part 3: Find and display the longest common subsequence between two transmissions
    cout << "Subsecuencia común más larga entre transmission1 y transmission2:" << endl;
    mostrarSubsecuenciaComun(transmission1, transmission2);

    return 0;
}
