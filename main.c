#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    do {
        printf("\n\tInicio\n1. Ingresar productos\n2. Editar productos\n3. Eliminar productos\n4. Lista de productos ingresados\n5. Buscar productos\n6. Salir\n");
        scanf("%i", &opcion);
        switch (opcion) {
            case 1:
                ingresar_producto();
                break;
            case 2:
                editar_producto();
                break;
            case 3:
                eliminar_producto();
                break;
            case 4:
                listar_productos();
                break;
            case 5:
                buscar_producto();
                break;
            case 6:
                printf("\nFinalizado\n");
                break;
            default:
                printf("\nError, Ingresa de nuevo\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
