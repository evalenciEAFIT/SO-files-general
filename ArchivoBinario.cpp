#include "ArchivoBinario.h"
#include <iostream>     // Para la entrada y salida estándar
#include <fstream>      // Para la gestión de archivos
#include <bitset>       // Para representar y manipular los bits
#include <iomanip>      // Para la manipulación del formato de salida

// Constructor que inicializa el nombre del archivo
ArchivoBinario::ArchivoBinario(const std::string& nombre_archivo)
    : archivo_nombre(nombre_archivo), archivo_tamaño(0) {}

// Método para leer el archivo binario y devolver su contenido como un vector de unsigned char
std::vector<unsigned char> ArchivoBinario::leer() {
    // Abrimos el archivo en modo binario y obtenemos su tamaño
    std::ifstream archivo(archivo_nombre, std::ios::binary | std::ios::ate);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo_nombre << std::endl;
        return {};
    }

    // Obtenemos el tamaño del archivo
    archivo_tamaño = archivo.tellg();
    archivo.seekg(0, std::ios::beg);

    // Creamos un buffer para almacenar los datos leídos
    std::vector<unsigned char> buffer(archivo_tamaño);

    // Leemos el contenido del archivo en el buffer
    if (!archivo.read(reinterpret_cast<char*>(buffer.data()), archivo_tamaño)) {
        std::cerr << "Error al leer el archivo." << std::endl;
        return {};
    }

    // Cerramos el archivo después de la lectura
    archivo.close();
    return buffer;
}

// Método para mostrar la información del archivo (nombre y tamaño)
void ArchivoBinario::mostrar_informacion() {
    std::cout << "Nombre del archivo: " << archivo_nombre << std::endl;
    std::cout << "Tamaño del archivo: " << archivo_tamaño << " bytes" << std::endl;
}

// Método para mostrar los datos en el formato y tamaño de grupo de bits especificado
void ArchivoBinario::mostrar_datos(const std::vector<unsigned char>& datos, const std::string& formato, int grupo_bits) {
    int contador = 0; // Contador para llevar la cuenta de cuántos bytes se han mostrado
    int agrupador = grupo_bits / 8;  // Calcula cuántos bytes corresponden al tamaño del grupo de bits

    // Iteramos sobre cada byte del archivo
    for (auto byte : datos) {
        // Mostramos los datos en el formato especificado (binario, octal, decimal o hexadecimal)
        if (formato == "binario") {
            mostrar_binario(byte, contador);
        } else if (formato == "octal") {
            mostrar_octal(byte, contador);
        } else if (formato == "decimal") {
            mostrar_decimal(byte, contador);
        } else if (formato == "hexadecimal") {
            mostrar_hexadecimal(byte, contador);
        }

        // Insertamos un separador cada vez que se completa el tamaño del grupo de bits
        if (contador % agrupador == 0) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl; // Nueva línea al final
}

// Método para mostrar los datos en binario
void ArchivoBinario::mostrar_binario(unsigned char byte, int &contador) {
    std::bitset<8> bits(byte); // Convertimos el byte a bits usando bitset
    std::cout << bits << " ";  // Mostramos los bits
    contador++; // Incrementamos el contador de bytes
}

// Método para mostrar los datos en octal
void ArchivoBinario::mostrar_octal(unsigned char byte, int &contador) {
    std::cout << std::oct << std::setw(3) << std::setfill('0') << static_cast<int>(byte) << " "; // Mostramos en octal
    contador++; // Incrementamos el contador de bytes
}

// Método para mostrar los datos en decimal
void ArchivoBinario::mostrar_decimal(unsigned char byte, int &contador) {
    std::cout << std::dec << std::setw(3) << static_cast<int>(byte) << " "; // Mostramos en decimal
    contador++; // Incrementamos el contador de bytes
}

// Método para mostrar los datos en hexadecimal
void ArchivoBinario::mostrar_hexadecimal(unsigned char byte, int &contador) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " "; // Mostramos en hexadecimal
    contador++; // Incrementamos el contador de bytes
}
