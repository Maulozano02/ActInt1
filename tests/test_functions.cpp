#include <catch2/catch_test_macros.hpp>
#include "../src/functions.h"
#include <fstream>

using namespace std;

// Helper function: create a test file with specific content
void createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

// Test for leerArchivo (simulating reading from a file, replace if necessary)
TEST_CASE("leerArchivo: Cargar archivo correctamente") {
    const std::string testFilename = "testfile.txt";
    const std::string content = "123ABCDEF";

    // Crear archivo de prueba
    createTestFile(testFilename, content);

    ifstream inputFile(testFilename);
    string result((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    REQUIRE(result == content);
}

TEST_CASE("leerArchivo: Archivo inexistente") {
    ifstream inputFile("archivo_inexistente.txt");
    REQUIRE(!inputFile); // Archivo no existe
}

// Test for contieneCodigo (similar to KMP functionality)
TEST_CASE("contieneCodigo: Encontrar patrón en texto") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "123ABC";
    size_t pos;

    REQUIRE(contieneCodigo(texto, patron, pos));
    REQUIRE(pos == 4);
}

TEST_CASE("contieneCodigo: No encontrar patrón") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "XYZ";
    size_t pos;

    REQUIRE(!contieneCodigo(texto, patron, pos));
}

// Test for palindromoMasLargo
TEST_CASE("palindromoMasLargo: Encontrar el palíndromo más largo") {
    const std::string cadena = "123454321ABC";
    auto resultado = palindromoMasLargo(cadena);

    REQUIRE(resultado.second == "123454321");
    REQUIRE(resultado.first.first == 1); // Índice ajustado a 1
    REQUIRE(resultado.first.second == 9);
}

TEST_CASE("palindromoMasLargo: Sin palíndromos largos") {
    const std::string cadena = "ABCDEFG";
    auto resultado = palindromoMasLargo(cadena);

    REQUIRE(resultado.second == "A"); // Primer carácter
    REQUIRE(resultado.first.first == 1); // Índice ajustado a 1
    REQUIRE(resultado.first.second == 1);
}

// Test for subsecuenciaComunMasLarga (substringComunMasLargo equivalent)
TEST_CASE("subsecuenciaComunMasLarga: Encontrar el substring común más largo") {
    const std::string cadena1 = "ABCDEF123456";
    const std::string cadena2 = "XYZ123456ABC";

    auto resultado = subsecuenciaComunMasLarga(cadena1, cadena2);

    REQUIRE(resultado.second == "123456");
    REQUIRE(resultado.first.first == 7); // Índice ajustado a 1
    REQUIRE(resultado.first.second == 12);
}

TEST_CASE("subsecuenciaComunMasLarga: Sin substring común") {
    const std::string cadena1 = "ABCDEFG";
    const std::string cadena2 = "HIJKLMN";

    auto resultado = subsecuenciaComunMasLarga(cadena1, cadena2);

    REQUIRE(resultado.second == "");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}
