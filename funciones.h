#define FUNCIONES_H

#define LONGITUD 50
#define CADENA 5
#define PRODUCTOS 50

extern char inventario[PRODUCTOS][CADENA][LONGITUD];
extern int x;

int validarlet(char cadena[]);
int validar(char cadena[]);
int validarpunto(char cadena[]);
void ingresar_producto(void);
void editar_producto(void);
void eliminar_producto(void);
void listar_productos(void);
void buscar_producto(void);
