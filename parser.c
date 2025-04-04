#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

// Función para contar cuántas líneas tiene el archivo (cuántas ventas hay)
int contar_filas(FILE *archivo) {
    int filas = 0;
    char buffer[1024];

    while (fgets(buffer, 1024, archivo)) {
        filas++;
    }

    rewind(archivo); // volver al inicio
    return filas - 1; // menos la cabecera
}

// Función que carga los datos desde el CSV
order* parse_csv(char *filename, int *size) {
    FILE *archivo = fopen(filename, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo %s\n", filename);
        return NULL;
    }

    int cantidad = contar_filas(archivo);
    *size = cantidad;

    order *lista = malloc(sizeof(order) * cantidad);
    if (!lista) {
        printf("No se pudo asignar memoria\n");
        fclose(archivo);
        return NULL;
    }

    char buffer[1024];
    fgets(buffer, 1024, archivo); // saltar cabecera

    int i = 0;
    while (fgets(buffer, 1024, archivo)) {
        sscanf(buffer, "%[^,],%[^,],%[^,],%d,%[^,],%[^,],%f,%f,%[^,],%[^,],\"%[^\"]\",%[^\n]",
            lista[i].pizza_id,
            lista[i].order_id,
            lista[i].pizza_name_id,
            &lista[i].quantity,
            lista[i].order_date,
            lista[i].order_time,
            &lista[i].unit_price,
            &lista[i].total_price,
            lista[i].pizza_size,
            lista[i].pizza_category,
            lista[i].pizza_ingredients,
            lista[i].pizza_name
        );
        i++;
    }

    fclose(archivo);
    return lista;
}
