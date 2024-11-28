
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
    ifstream transmission1File("transmission1.txt");
    ifstream transmission2File("transmission2.txt");
    ifstream mcode1File("mcode1.txt");
    ifstream mcode2File("mcode2.txt");
    ifstream mcode3File("mcode3.txt");

    if (!transmission1File || !transmission2File || !mcode1File || !mcode2File || !mcode3File) {
        cerr << "Error abriendo los archivos" << endl;
        return 1;
    }

    string transmission1((istreambuf_iterator<char>(transmission1File)), istreambuf_iterator<char>());
    string transmission2((istreambuf_iterator<char>(transmission2File)), istreambuf_iterator<char>());
    string mcode1((istreambuf_iterator<char>(mcode1File)), istreambuf_iterator<char>());
    string mcode2((istreambuf_iterator<char>(mcode2File)), istreambuf_iterator<char>());
    string mcode3((istreambuf_iterator<char>(mcode3File)), istreambuf_iterator<char>());

    size_t pos;
    cout << (contieneCodigo(transmission1, mcode1, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission1, mcode2, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission1, mcode3, pos) ? "true " + to_string(pos + 1) : "false") << endl;

    cout << (contieneCodigo(transmission2, mcode1, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission2, mcode2, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (contieneCodigo(transmission2, mcode3, pos) ? "true " + to_string(pos + 1) : "false") << endl;

    pair<pair<int, int>, string> pal1 = palindromoMasLargo(transmission1);
    pair<pair<int, int>, string> pal2 = palindromoMasLargo(transmission2);

    cout << pal1.first.first << " " << pal1.first.second << " " << pal1.second << endl;
    cout << pal2.first.first << " " << pal2.first.second << " " << pal2.second << endl;

    pair<pair<int, int>, string> subseq = subsecuenciaComunMasLarga(transmission1, transmission2);
    cout << subseq.first.first << " " << subseq.first.second << " " << subseq.second << endl;

    return 0;
}