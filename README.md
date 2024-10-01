# Procesador de Archivos Binarios

Este programa en C++ permite abrir un archivo en modo binario, mostrar su contenido en diferentes formatos (binario, octal, decimal y hexadecimal) y visualizar la información básica del archivo, como su nombre y tamaño.

## ¿Cómo funcionan los dispositivos de almacenamiento?

Existen diferentes tipos de dispositivos de almacenamiento en los que se guardan los archivos binarios y de texto. A continuación, se describen algunos de los más comunes.

### Discos Duros Mecánicos (HDD)

Los discos duros mecánicos (HDD) utilizan un plato giratorio cubierto con un material magnético. Un cabezal de lectura/escritura se mueve sobre el plato para leer o escribir datos en diferentes ubicaciones. Los discos HDD son conocidos por su gran capacidad de almacenamiento a bajo costo, aunque son más lentos que las unidades de estado sólido (SSD).

Para más información sobre los discos mecánicos, puedes ver estos videos:

- [¿Cómo funciona un disco duro mecánico?](https://youtu.be/CxUVjbO05ms?si=YycMOeaqi0NU3XPw)
- [Explicación detallada sobre HDD](https://youtu.be/IaeF-DjLZW8?si=zsFl996aMNbmuuaW)
- [Vista interna de un disco mecánico](https://youtube.com/shorts/YkOvOwULWpA?si=znekhAfXLUTFhRSr)

### Unidades de Estado Sólido (SSD)

Las unidades SSD no tienen partes móviles, a diferencia de los discos duros mecánicos. En lugar de platos magnéticos, usan chips de memoria flash para almacenar datos. Esto hace que las SSD sean significativamente más rápidas y menos propensas a fallos físicos, aunque suelen ser más costosas por gigabyte que los discos HDD.

Para aprender más sobre cómo funcionan los discos SSD, puedes ver estos videos:

- [¿Cómo funciona un SSD?](https://youtu.be/AH7i6uIfr9o?si=6hHgrcxiUrpm6Pft)
- [Vista interna de un SSD](https://youtube.com/shorts/C38iFTYf9TY?si=0XE9V8735Cquc4QU)

### Otros tipos de almacenamiento

#### Cintas Magnéticas

Las cintas magnéticas se usaron mucho en el pasado como medio de almacenamiento y respaldo de datos. A pesar de su lentitud en comparación con los discos duros modernos, las cintas siguen siendo una opción viable para el almacenamiento a largo plazo debido a su bajo costo por gigabyte.

- [Cintas Magnéticas](https://youtu.be/nSpJmt5dn20?si=IqHIRBnWZzvFKo81)

#### Diskettes

Los diskettes fueron uno de los primeros medios de almacenamiento portátiles utilizados para transportar pequeñas cantidades de datos. Con capacidades que iban desde los 720 KB hasta 1.44 MB, fueron reemplazados por tecnologías más avanzadas como los discos ópticos y las unidades flash USB.

---

## Explicación del código

### Archivo `ArchivoBinario.h`

Este archivo define la clase `ArchivoBinario`, que maneja la lectura y visualización de los archivos binarios. A continuación se describen los principales componentes de la clase:

- **Variables privadas**:
  - `archivo_nombre`: Almacena el nombre del archivo que se va a procesar.
  - `archivo_tamaño`: Almacena el tamaño del archivo una vez que se ha leído.

- **Métodos públicos**:
  - `ArchivoBinario(const std::string& nombre_archivo)`: Constructor que inicializa el nombre del archivo.
  - `leer()`: Método que abre el archivo binario y lee su contenido.
  - `mostrar_informacion()`: Muestra información básica del archivo, como su nombre y tamaño.
  - `mostrar_datos()`: Muestra el contenido del archivo en el formato (binario, octal, decimal o hexadecimal) y grupo de bits especificado.

### Archivo `ArchivoBinario.cpp`

Este archivo contiene la implementación de los métodos definidos en `ArchivoBinario.h`:

- **`leer()`**: Abre el archivo en modo binario y devuelve un vector de bytes (`unsigned char`) con los datos leídos.
- **`mostrar_informacion()`**: Muestra en la consola el nombre del archivo y su tamaño en bytes.
- **`mostrar_datos()`**: Muestra los datos leídos del archivo en el formato y grupo de bits (8, 16, 32 o 64) solicitados. También gestiona cómo se muestran los datos en binario, octal, decimal y hexadecimal mediante funciones privadas (`mostrar_binario`, `mostrar_octal`, etc.).

### Archivo `main.cpp`

Este archivo contiene el punto de entrada del programa. Recibe los argumentos desde la línea de comandos para especificar el archivo a abrir, el formato de visualización y el tamaño del grupo de bits.

El flujo del programa es el siguiente:

1. Verifica que los argumentos ingresados por el usuario sean válidos.
2. Crea una instancia de `ArchivoBinario` con el archivo especificado.
3. Llama al método `leer()` para cargar el archivo.
4. Muestra la información del archivo mediante `mostrar_informacion()`.
5. Si el archivo se ha leído correctamente, muestra su contenido usando el método `mostrar_datos()` en el formato y tamaño especificado.

### Archivo `Makefile`

El archivo `Makefile` contiene las reglas necesarias para compilar el programa. Utiliza el compilador `g++` con las banderas `-Wall`, `-Wextra`, y `-std=c++17` para generar el ejecutable.

Las principales reglas del `Makefile` son:

- **`all`**: Compila el programa creando el ejecutable `visualizar_archivo_binario`.
- **`run`**: Ejecuta el programa con un archivo binario de ejemplo.
- **`clean`**: Elimina el archivo ejecutable generado.

## Cómo ejecutar el programa

1. **Compilar**: Ejecuta el siguiente comando para compilar el programa:

   ```bash
   make
   ```

2. **Ejecutar**: Una vez compilado, puedes ejecutar el programa con la siguiente sintaxis:

   ```bash
   ./visualizar_archivo_binario <archivo_entrada> <grupo_bits> <formato>
   ```

   - `<archivo_entrada>`: Es el nombre del archivo binario que deseas visualizar.
   - `<grupo_bits>`: Especifica cómo se agruparán los bits para la visualización. Puede ser 8, 16, 32 o 64.
   - `<formato>`: El formato en el que se mostrarán los datos (binario, octal, decimal o hexadecimal).

   Ejemplo de ejecución:

   ```bash
   ./visualizar_archivo_binario archivo.bin 16 hexadecimal
   ```

   Este comando leerá el archivo `archivo.bin` y mostrará su contenido en grupos de 16 bits y en formato hexadecimal.

## Ejemplo de salida

```
Nombre del archivo: archivo.bin
Tamaño del archivo: 1024 bytes

11110000 10101010 | 11110000 10101010 | ...
```

En este ejemplo, los datos del archivo se muestran en formato binario y en grupos de 16 bits. Cada grupo de bits se separa con un `|`.

### Limpieza

Para eliminar los archivos generados tras la compilación:

```bash
make clean
```

## Notas

Este programa es una herramienta básica para visualizar archivos binarios y comprender cómo se almacenan los datos en un sistema. Se puede expandir fácilmente para realizar otras operaciones en los archivos, como modificar bits específicos o comprimir y descomprimir datos.
