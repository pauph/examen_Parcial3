#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxcolumnas 3200
#define maxfilas 50
#define maxlongitud 65001
#define inicial 988
#define final 1037

int main() {
    FILE *archivoentrada = fopen("emails.csv", "r");
    if (!archivoentrada) {
        perror("Error al abrir el archivo CSV");
        return 1;
    }

    char buffer[maxlongitud];
    char *columnas[maxcolumnas];
    int conteos[maxcolumnas] = {0};
    int id = 988;

    if (fgets(buffer, sizeof(buffer), archivoentrada)) {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < maxcolumnas) {
            columnas[columna] = strdup(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    int filaActual;

    for (filaActual = 1; filaActual < inicial && fgets(buffer, sizeof(buffer), archivoentrada); ++filaActual) {
    }
    
    
    for (filaActual = inicial; filaActual <= final && fgets(buffer, sizeof(buffer), archivoentrada); ++filaActual) {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < maxcolumnas) {
            conteos[columna] += atoi(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(archivoentrada);
    int i;

    FILE *archivosalida = fopen("180988.txt", "w");
    if (!archivosalida) {
        perror("Error al abrir el archivo de salida");
        for (i = 0; i < maxcolumnas; i++) {
            free(columnas[i]);
        }
        return 1;
    }

    for (i = 0; i < maxcolumnas && columnas[i] != NULL; i++) {
        fprintf(archivosalida, "%s, %d\n", columnas[i], conteos[i]);
        free(columnas[i]);
    }

    fclose(archivosalida);
    printf("Archivo creado, el nombre es 180988.txt\n");

    return 0;
}

