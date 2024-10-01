
# Makefile para compilar el programa orientado a objetos de lectura y visualización de archivos binarios por bits

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS =

# Nombre del ejecutable
TARGET = visualizar_archivo_binario

# Archivos fuente
SOURCES = main.cpp ArchivoBinario.cpp

# Regla para compilar el programa
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET) archivo_entrada.bin 8 binario  # Cambia el número 8 por 16 si deseas ver en grupos de 16 bits

# Limpiar archivos generados
clean:
	rm -f $(TARGET)
