#include <iostream>     // Para la entrada y salida estándar
#include "ArchivoBinario.h" // Incluimos la clase que gestiona los archivos binarios

int main(int argc, char* argv[]) {
    // Verificamos que se han pasado al menos 3 argumentos (nombre del archivo, grupo de bits y formato)
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " <archivo_entrada> <grupo_bits> <formato (binario|octal|decimal|hexadecimal)>" << std::endl;
        return 1;
    }

    // Leemos los argumentos: nombre del archivo, tamaño del grupo de bits y formato de visualización
    std::string archivo_entrada = argv[1];
    int grupo_bits = std::stoi(argv[2]); // Convertimos el tamaño del grupo de bits a un entero
    std::string formato = argv[3];

    // Validamos que el tamaño del grupo de bits sea uno de los permitidos (8, 16, 32 o 64 bits)
    if (grupo_bits != 8 && grupo_bits != 16 && grupo_bits != 32 && grupo_bits != 64) {
        std::cerr << "Error: Solo se permiten grupos de 8, 16, 32 o 64 bits." << std::endl;
        return 1;
    }

    // Validamos que el formato de visualización sea uno de los permitidos (binario, octal, decimal o hexadecimal)
    if (formato != "binario" && formato != "octal" && formato != "decimal" && formato != "hexadecimal") {
        std::cerr << "Error: Formato inválido. Usa 'binario', 'octal', 'decimal' o 'hexadecimal'." << std::endl;
        return 1;
    }

    // Creamos una instancia de la clase ArchivoBinario con el archivo de entrada
    ArchivoBinario archivo(archivo_entrada);

    // Leemos el archivo binario
    std::vector<unsigned char> datos = archivo.leer();

    // Mostramos la información del archivo (nombre y tamaño)
    archivo.mostrar_informacion();

    // Si se ha leído correctamente el archivo, mostramos los datos en el formato y tamaño de bits solicitado
    if (!datos.empty()) {
        archivo.mostrar_datos(datos, formato, grupo_bits);
    } else {
        std::cerr << "No se pudo procesar el archivo." << std::endl;
    }

    return 0; // Fin del programa
}
