// Mauricio Lozano Zarate A00833216
// Aleksandra Stupiec A00835071
// Enrique Macías López A01641402

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Esta función busca si una secuencia maliciosa (mcode) está en la transmisión
// Regresa true o false y la posición donde está si la encuentra
bool contieneCodigo(const string &transmission, const string &mcode, size_t &pos) {
    pos = transmission.find(mcode);
    return pos != string::npos;
}

// Verifica si una subcadena es un palíndromo (se lee igual al derecho y al revés)
bool esPalindromo(const string &str, int left, int right) {
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // No es palíndromo si los extremos no coinciden
        }
        left++;
        right--;
    }
    return true;
}

// Encuentra el palíndromo más largo en la transmisión y lo regresa junto con su posición
pair<pair<int, int>, string> palindromoMasLargo(const string &transmission) {
    int n = transmission.size();
    int maxLength = 1, start = 0;

    // Recorre todas las posibles subcadenas para ver cuál es un palíndromo
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (esPalindromo(transmission, i, j) && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    // Regresa la posición (en formato que empieza en 1) y el palíndromo
    return make_pair(make_pair(start + 1, start + maxLength), transmission.substr(start, maxLength));
}

// Encuentra la subsecuencia más larga en común entre dos transmisiones
pair<pair<int, int>, string> subsecuenciaComunMasLarga(const string &transmission1, const string &transmission2) {
    int m = transmission1.size();
    int n = transmission2.size();
    int maxLength = 0, endIdx = 0;
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0)); // Matriz de DP para guardar longitudes

    // Recorremos ambas transmisiones buscando la subsecuencia más larga común
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (transmission1[i - 1] == transmission2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Si coinciden los caracteres, extendemos la subsecuencia
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIdx = i; // Guardamos hasta dónde llega la subsecuencia más larga
                }
            }
        }
    }

    // Regresamos la posición inicial y final de la subsecuencia, junto con la subsecuencia
    return make_pair(make_pair(endIdx - maxLength + 1, endIdx), transmission1.substr(endIdx - maxLength, maxLength));
}

int main() {
    // Abrir archivos de las transmisiones y secuencias maliciosas
    ifstream transmission1File("transmission1.txt");
    ifstream transmission2File("transmission2.txt");
    ifstream mcode1File("mcode1.txt");
    ifstream mcode2File("mcode2.txt");
    ifstream mcode3File("mcode3.txt");

    // Si no se puede abrir alguno de los archivos, lanzamos un error
    if (!transmission1File || !transmission2File || !mcode1File || !mcode2File || !mcode3File) {
        cerr << "Error abriendo los archivos" << endl;
        return 1;
    }

    // Leer contenido de los archivos
    string transmission1((istreambuf_iterator<char>(transmission1File)), istreambuf_iterator<char>());
    string transmission2((istreambuf_iterator<char>(transmission2File)), istreambuf_iterator<char>());
    string mcode1((istreambuf_iterator<char>(mcode1File)), istreambuf_iterator<char>());
    string mcode2((istreambuf_iterator<char>(mcode2File)), istreambuf_iterator<char>());
    string mcode3((istreambuf_iterator<char>(mcode3File)), istreambuf_iterator<char>());

    // Parte 1: Verificar si el código malicioso está contenido en las transmisiones
    size_t pos;

    // Transmission 1
    cout << (contieneCodigo(transmission1, mcode1, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission1, mcode2, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission1, mcode3, pos) ? "true " + to_string(pos + 1) : "false") << endl;

    // Transmission 2
    cout << (contieneCodigo(transmission2, mcode1, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission2, mcode2, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission2, mcode3, pos) ? "true " + to_string(pos + 1) : "false") << endl;

    // Parte 2: Encontrar el palíndromo más largo en cada archivo de transmisión
    pair<pair<int, int>, string> pal1 = palindromoMasLargo(transmission1);
    pair<pair<int, int>, string> pal2 = palindromoMasLargo(transmission2);

    cout << pal1.first.first << " " << pal1.first.second << " " << pal1.second << endl;
    cout << pal2.first.first << " " << pal2.first.second << " " << pal2.second << endl;

    // Parte 3: Encontrar la subsecuencia común más larga entre los dos archivos de transmisión
    pair<pair<int, int>, string> subseq = subsecuenciaComunMasLarga(transmission1, transmission2);
    cout << subseq.first.first << " " << subseq.first.second << " " << subseq.second << endl;

    return 0;
}
