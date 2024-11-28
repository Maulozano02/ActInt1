#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Esta función busca si una secuencia maliciosa (mcode) está en la transmisión
// Regresa true o false y la posición donde está si la encuentra
bool contieneCodigo(const string &transmission, const string &mcode, size_t &pos);

// Verifica si una subcadena es un palíndromo (se lee igual al derecho y al revés)
bool esPalindromo(const string &str, int left, int right);

// Encuentra el palíndromo más largo en la transmisión y lo regresa junto con su posición
pair<pair<int, int>, string> palindromoMasLargo(const string &transmission);

// Encuentra la subsecuencia más larga en común entre dos transmisiones
pair<pair<int, int>, string> subsecuenciaComunMasLarga(const string &transmission1, const string &transmission2);

// Función para leer un archivo y retornar su contenido como string
string leerArchivo(const string& filename);

// Función para verificar la existencia de los archivos y cargarlos
bool verificarArchivos(vector<string>& archivos, vector<string>& contenidos);

// Función para verificar códigos maliciosos en una transmisión
void verificarCodigosMaliciosos(const string& transmission, const vector<string>& mcodes);

// Función para mostrar el palíndromo más largo en una transmisión
void mostrarPalindromo(const string& transmission);

// Función para mostrar la subsecuencia común más larga entre dos transmisiones
void mostrarSubsecuenciaComun(const string& transmission1, const string& transmission2);

#endif // FUNCTIONS_H
