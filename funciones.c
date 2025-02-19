#include <stdio.h>
#include <string.h>
#include "funciones.h"

char inventario[PRODUCTOS][CADENA][LONGITUD];
int x = 0;

int validarlet(char cadena[]) {
    return 1; 
}
int validar(char cadena[]) {
    return 1;
}
int validarpunto(char cadena[]) {
    return 1; 
}
void ingresar_producto(void) {
    int desicion;
    for (int y = 0; y < CADENA; y++) {
        switch (y) {
            case 0:
                do {
                    printf("\nNombre del producto: ");
                    scanf("%s", inventario[x][y]);
                    desicion = validarlet(inventario[x][y]);
                } while (desicion == 0);
                break;
            case 1:
                do {
                    printf("Unidades del producto: ");
                    scanf("%s", inventario[x][y]);
                    desicion = validar(inventario[x][y]);
                } while (desicion == 0);
                break;
            case 2:
                do {
                    printf("Precio del producto por unidad: ");
                    scanf("%s", inventario[x][y]);
                    desicion = validarpunto(inventario[x][y]);
                } while (desicion == 0);
                break;
            case 3:
                do {
                    printf("Codigo del producto : ");
                    scanf("%s", inventario[x][y]);
                    desicion = validarpunto(inventario[x][y]);
                } while (desicion == 0);
                break;
            case 4:
                printf("Lote del producto: ");
                scanf("%s", inventario[x][y]);
                desicion = validarpunto(inventario[x][y]);
                break;
        }
    }
    x += 1;
}

void editar_producto(void) {
    char respuesta[2];
    int indice, desicion;

    printf("\nPara editar un producto debe conocer el indice de dicho producto\nDesea continuar?(si/no)\n");
    scanf("%s", respuesta);
    if (strcmp(respuesta, "SI") == 0 || strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        printf("Ingrese el indice del producto a editar\n");
        scanf("%i", &indice);
        indice -= 1;
        if (indice >= 0 && indice < x) {
            printf("Indice\tNombre\tCantidad\tPrecio\tCodigo\tLote");
            printf("\n%d", indice + 1);
            for (int j = 0; j < CADENA; j++) {
                printf("\t%s", inventario[indice][j]);
            }
            for (int y = 0; y < CADENA; y++) {
                switch (y) {
                    case 0:
                        do {
                            printf("\nNuevo nombre del producto: ");
                            scanf("%s", inventario[indice][y]);
                            desicion = validarlet(inventario[indice][y]);
                        } while (desicion == 0);
                        break;
                    case 1:
                        do {
                            printf("Nueva cantidad del producto: ");
                            scanf("%s", inventario[indice][y]);
                            desicion = validar(inventario[indice][y]);
                        } while (desicion == 0);
                        break;
                    case 2:
                        do {
                            printf("Nuevo precio unitario del producto: ");
                            scanf("%s", inventario[indice][y]);
                            desicion = validarpunto(inventario[indice][y]);
                        } while (desicion == 0);
                        break;
                    case 3:
                        printf("Nuevo codigo del producto: ");
                        scanf("%s", inventario[indice][y]);
                        break;
                    case 4:
                        printf("Nuevo lote del producto: ");
                        scanf("%s", inventario[indice][y]);
                        break;
                }
            }
        } else {
            printf("Indice invalido, ingrese de nuevo.\n");
        }
    }
}

void eliminar_producto(void) {
    char respuesta[2];
    int indice;

    printf("\nPara eliminar un producto debe conocer el indice de dicho producto\nDesea continuar?(si/no)\n");
    scanf("%s", respuesta);
    if (strcmp(respuesta, "SI") == 0 || strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
        printf("Ingrese el indice del producto a eliminar\n");
        scanf("%i", &indice);
        printf("Indice\tNombre\tCantidad\tPrecio\tCodigo");
        printf("\n%d", indice);
        indice -= 1;
        for (int j = 0; j < CADENA; j++) {
            printf("\t%s", inventario[indice][j]);
        }
        printf("\nEsta seguro de querer eliminar este producto?(si/no)\n");
        scanf("%s", respuesta);
        if (strcmp(respuesta, "SI") == 0 || strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 0) {
            for (int i = indice; i < x - 1; i++) {
                for (int j = 0; j < CADENA; j++) {
                    strcpy(inventario[i][j], inventario[i + 1][j]);
                }
            }
            x -= 1;
        }
    }
}

void listar_productos(void) {
    printf("\nIndice\tNombre\tCantidad\tPrecio\tCodigo\tLote");
    for (int i = 0; i < x; i++) {
        printf("\n %d", i + 1);
        for (int j = 0; j < CADENA; j++) {
            printf("\t%s", inventario[i][j]);
        }
    }
}

void buscar_producto(void) {
    int sub_opcion;
    char buscar[LONGITUD];
    int encontrado = 0;

    printf("\nBuscar producto\n1. Por Codigo (Ingrese 1 para seguir): ");
    scanf("%d", &sub_opcion);

    switch (sub_opcion) {
        case 1:
            printf("Ingrese el codigo del producto: ");
            scanf("%s", buscar);
            for (int i = 0; i < x; i++) {
                if (strcmp(inventario[i][3], buscar) == 0) {
                    printf("Producto encontrado: \n");
                    printf("Indice\tNombre\tCantidad\tPrecio\tCodigo\tLote\n");
                    printf("%d\t%s\t%s\t%s\t%s\t%s\n", i + 1, inventario[i][0], inventario[i][1], inventario[i][2], inventario[i][3], inventario[i][4]);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Producto con codigo %s no encontrado.\n", buscar);
            }
            break;
        default:
            printf("Opcion invalida.\n");
            break;
    }
}
