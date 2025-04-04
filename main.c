#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

// Funcion dummy temporal (solo para compilar algo)
char* pms(int *size, order *orders) {
    char *result = malloc(100);
    strcpy(result, "Pizza mas vendida: (pendiente)");
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s archivo.csv metrica1 [metrica2 ...]\n", argv[0]);
        return 1;
    }

    // A futuro: leer el archivo CSV
    int size = 0;
    order *orders = NULL; // aun no leemos nada

    // Solo 1 metrica de prueba
    if (strcmp(argv[2], "pms") == 0) {
        char *resultado = pms(&size, orders);
        printf("%s\n", resultado);
        free(resultado);
    }

    return 0;
}