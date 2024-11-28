#include "../src/functions.h"
#include <fstream>

// Implementación de leerArchivo
string leerArchivo(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error abriendo el archivo: " << filename << endl;
        return "";
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

// Implementación de verificarArchivos
bool verificarArchivos(vector<string>& archivos, vector<string>& contenidos) {
    for (const auto& archivo : archivos) {
        string contenido = leerArchivo(archivo);
        if (contenido.empty()) {
            cerr << "Error: Archivo no encontrado o vacío -> " << archivo << endl;
            return false;
        }
        contenidos.push_back(contenido);
    }
    return true;
}

// Implementación de verificarCodigosMaliciosos
void verificarCodigosMaliciosos(const string& transmission, const vector<string>& mcodes) {
    size_t pos;
    for (const auto& mcode : mcodes) {
        cout << (contieneCodigo(transmission, mcode, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    }
}

// Implementación de mostrarPalindromo
void mostrarPalindromo(const string& transmission) {
    auto resultado = palindromoMasLargo(transmission);
    cout << resultado.first.first << " " << resultado.first.second << " " << resultado.second << endl;
}

// Implementación de mostrarSubsecuenciaComun
void mostrarSubsecuenciaComun(const string& transmission1, const string& transmission2) {
    auto resultado = subsecuenciaComunMasLarga(transmission1, transmission2);
    cout << resultado.first.first << " " << resultado.first.second << " " << resultado.second << endl;
}

// Implementaciones previas de contieneCodigo, esPalindromo, palindromoMasLargo, y subsecuenciaComunMasLarga permanecen iguales
