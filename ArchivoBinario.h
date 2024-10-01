#ifndef ARCHIVOBINARIO_H
#define ARCHIVOBINARIO_H

#include <vector>
#include <string>

// Clase ArchivoBinario que gestiona la lectura y visualización de archivos binarios
class ArchivoBinario {
public:
    // Constructor que recibe el nombre del archivo a procesar
    ArchivoBinario(const std::string& nombre_archivo);

    // Método para leer el archivo binario y devolver su contenido como un vector de unsigned char
    std::vector<unsigned char> leer();

    // Método para mostrar la información del archivo (nombre, tamaño, etc.)
    void mostrar_informacion();

    // Método para mostrar el contenido del archivo en el formato y tamaño de grupo de bits especificado
    void mostrar_datos(const std::vector<unsigned char>& datos, const std::string& formato, int grupo_bits);

private:
    // Nombre del archivo que se va a procesar
    std::string archivo_nombre;

    // Tamaño del archivo
    std::streamsize archivo_tamaño;

    // Métodos privados para mostrar los datos en binario, octal, decimal y hexadecimal (sin grupo_bits)
    void mostrar_binario(unsigned char byte, int &contador);
    void mostrar_octal(unsigned char byte, int &contador);
    void mostrar_decimal(unsigned char byte, int &contador);
    void mostrar_hexadecimal(unsigned char byte, int &contador);
};

#endif
