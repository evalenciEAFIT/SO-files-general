
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

## Conceptos clave

### Archivos en texto plano vs archivos binarios

- **Archivos en texto plano**: Los archivos en texto plano son aquellos que almacenan información en formato legible por humanos. Por ejemplo, archivos `.txt`, `.csv` o código fuente. Estos archivos contienen caracteres de texto que pueden ser interpretados por un editor de texto. Cada carácter se representa en el archivo como un código ASCII o Unicode.
- **Archivos binarios**: A diferencia de los archivos en texto plano, los archivos binarios almacenan datos en formato no legible por humanos. Un archivo binario puede contener cualquier tipo de datos, como imágenes, videos, o archivos ejecutables, donde cada bit tiene un significado específico según el formato del archivo. Los archivos binarios no pueden ser abiertos y entendidos directamente por un editor de texto.

### Representación de los datos

Los datos almacenados en un archivo, ya sea de texto o binario, pueden ser representados de distintas formas. En este programa, mostramos la representación de los datos en:
- **Binario**: La representación en binario usa solo los valores 0 y 1. Cada byte (8 bits) se representa como una secuencia de 8 valores binarios, por ejemplo, `01101011`. Esta es la forma más básica de representar los datos en un ordenador.
- **Octal**: La representación octal utiliza 8 valores: del 0 al 7. Cada dígito octal es el equivalente de 3 bits. Por ejemplo, el valor binario `101011` se convierte a octal como `53`. La representación octal fue históricamente usada en sistemas más antiguos y en lenguajes como el ensamblador.
- **Decimal**: La representación decimal es la forma común que utilizamos en nuestra vida diaria. Los números se representan con dígitos del 0 al 9. Un byte en decimal puede tener un valor entre 0 y 255.
- **Hexadecimal**: La representación hexadecimal utiliza 16 símbolos: los números del 0 al 9 y las letras A a F para representar los valores de 0 a 15. Cada grupo de 4 bits se convierte a un dígito hexadecimal. Por ejemplo, el valor binario `11111010` se convierte en hexadecimal como `FA`.

### Relación con los archivos

Los archivos binarios son una colección de bytes (8 bits) que pueden ser interpretados de distintas maneras, dependiendo del formato del archivo. Por ejemplo:

- Un archivo de imagen `.png` almacenará píxeles y su información de color en formato binario.
- Un archivo de texto almacenará los caracteres codificados, como ASCII o UTF-8, en forma binaria.

El formato en que se visualizan estos datos es importante para entender el contenido del archivo a nivel más bajo. Dependiendo del uso que le demos a estos datos (ya sea al modificar bits, extraer información específica o procesar imágenes o video), podemos elegir visualizarlos en binario, octal, decimal o hexadecimal.

## Uso del Programa

### Compilación

Para compilar el programa, simplemente ejecuta el siguiente comando:

```bash
make
```

Esto generará el archivo ejecutable `visualizar_archivo_binario`.

### Ejecución

El programa permite visualizar un archivo en diferentes formatos y grupos de bits. Para ejecutarlo, utiliza el siguiente formato:

```bash
./visualizar_archivo_binario <archivo_entrada> <grupo_bits> <formato>
```

- `<archivo_entrada>`: Es el nombre del archivo que deseas visualizar.
- `<grupo_bits>`: El tamaño de grupo en bits (puede ser 8, 16, 32 o 64).
- `<formato>`: El formato de visualización (puede ser `binario`, `octal`, `decimal` o `hexadecimal`).

#### Ejemplo

```bash
./visualizar_archivo_binario archivo.bin 16 hexadecimal
```

Este comando mostrará el contenido del archivo `archivo.bin` en grupos de 16 bits y en formato hexadecimal.

### Información del archivo

Antes de mostrar los datos, el programa también muestra información básica del archivo, como su nombre y tamaño en bytes.

### Limpieza

Para limpiar los archivos generados después de la compilación:

```bash
make clean
```

## Notas

Este programa es una herramienta básica para visualizar archivos binarios y comprender cómo se almacenan los datos en un sistema. Se puede expandir fácilmente para realizar otras operaciones en los archivos, como modificar bits específicos o comprimir y descomprimir datos.
