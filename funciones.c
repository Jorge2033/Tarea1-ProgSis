#include <stdio.h>
#include <string.h>
#include "funciones.h"
struct Usuario crearUsuario() {
  struct Usuario usuario;
  printf("Ingrese el cargo del usuario: ");
  scanf("%s", usuario.cargo);
  printf("Ingrese la clave del usuario: ");
  scanf("%s", usuario.clave);
  return usuario;
}
void actualizarUsuario(struct Usuario usuario) {
  printf("Ingrese el nuevo cargo del usuario: ");
  scanf("%s", usuario.cargo);
  printf("Ingrese la nueva clave del usuario: ");
  scanf("%s", usuario.clave);
}
struct Producto crearProducto() {
  struct Producto producto;
  printf("Ingrese el nombre del producto: ");
  scanf("%s", producto.nombre);

  printf("Ingrese la categoria del producto: ");
  scanf("%s", producto.categoria);

  printf("Ingrese la marca del producto: ");
  scanf("%s", producto.marca);

  printf("Ingrese el codigo del producto: ");
  scanf("%d", &producto.codigo);

  printf("Ingrese la cantidad del producto: ");
  scanf("%d", &producto.cantidadProducto);

  printf("Ingrese el precio del producto: ");
  scanf("%f", &producto.precioCompra);
  
  printf("Ingrese la bodega del producto: ");
  scanf(" %c", producto.bodega);
  producto.cantidadProducto++;
  return producto;
}
void actualizarProducto(struct Producto producto) {
  printf("Ingrese el nuevo nombre del producto: ");
  scanf("%s", producto.nombre);
  printf("Ingrese la nueva categoria del producto: ");
  scanf("%s", producto.categoria);
  printf("Ingrese la nueva marca del producto: ");
  scanf("%s", producto.marca);
  printf("Ingrese el nuevo codigo del producto: ");
  scanf("%d", &producto.codigo);
  printf("Ingrese la nueva cantidad del producto: ");
  scanf("%d", &producto.cantidadProducto);
  printf("Ingrese el nuevo precio del producto: ");
  scanf("%f", &producto.precioCompra);
  printf("Ingrese la nueva bodega del producto: ");
  scanf(" %s", producto.bodega);
}
/*int MenuPrincipal(struct Usuario usuarios[], struct Producto productos[]) {
  char opcion[30];
  struct Usuario usuario;
  printf("Bienvenido al sistema\n");
  printf("Ingrese su cargo (administrador, bodeguero, vendedor): ");
  scanf("%s", opcion);
  if (strcmp(opcion, "administrador") == 0) {
    printf("Opción seleccionada: Administrador\n");
    printf("1. Crear usuario\n");
    printf("2. Actualizar usuario\n");
    int seleccion;
    scanf("%d", &seleccion);
    switch (seleccion) {
      case 1:
        usuario= crearUsuario();
        int cantidadElementos = 0;
        for (int i = 0; i < sizeof(usuarios) / sizeof(usuarios[0]); ++i) {
            cantidadElementos++;
        }
        usuarios[cantidadElementos]=usuario;
        printf("Usuario : %s\n", usuarios[cantidadElementos].cargo);
        printf("1. crear otro usuario\n");
        printf("2. salir\n");
        int seleccion2;
        scanf("%d",&seleccion2);
        switch(seleccion2){
          case 1:
          crearUsuario();
          break;
          case 2:
          MenuPrincipal(usuarios,productos);
          break;
        }
        break;
      case 2:
        actualizarUsuario(usuario);
        printf("1. actualizar otro usuario\n");
        printf("2. crear usuario\n");
        printf("3. salir\n");
        int seleccion3;
        scanf("%d",&seleccion3);
        switch(seleccion3){
          case 1:
          actualizarUsuario(usuario);
          break;
          case 2:
          crearUsuario();
          break;
          case 3:
          MenuPrincipal(usuarios,productos);
          break;
        break;
      }
  } }else if (strcmp(opcion, "bodeguero") == 0) {
    printf("Opción seleccionada: Bodeguero\n");
    printf("1. Crear usuario\n");
    printf("2. Actualizar usuario\n");
    int option;
    scanf("%d", &option);
    switch (option) {
      case 1:
        crearUsuario();
        printf("1.salir\n");
        printf("2.crear otro usuario\n");
        int opcion;
        scanf("%d",&opcion);
        switch(opcion){
          case 1:
          //MenuPrincipal(usuario,producto);
          break;
          case 2:
          crearUsuario();
          break;
          default:
          printf("Opción inválida\n");
           // MenuPrincipal(usuario,producto);
          break;
        }
        break;
      case 2:
        actualizarUsuario(usuario);
        printf("1.salir\n");
        printf("2.modificar otro usuario\n");
        int eleccion;
        scanf("%d",&eleccion);
        switch(eleccion){
          case 1:
         // MenuPrincipal(usuario,producto);
          break;
          case 2:
            actualizarUsuario(usuario);
          break;
          
        break;
      default:
        printf("Opción inválida\n");
          //MenuPrincipal(usuario,producto);
    }
    }
  } else if (strcmp(opcion, "vendedor") == 0) {
    printf("Opción seleccionada: Vendedor\n");
    printf("1. vender producto\n");
    printf("2. Salir\n");    
    int posibilidad;
    scanf("%d", &posibilidad);
    switch (posibilidad) {
      case 1:
        //venderProducto(producto);
        printf("1.vender otro producto\n");
        printf("2.salir\n");
        int choice;
        scanf("%d",&choice);
        switch (choice){
          case 1:
          //venderProducto(producto);
          break;
          case 2:
         // MenuPrincipal(usuario,producto);
          break;
        }
        break;
      case 2:
     // MenuPrincipal(usuario,producto);
      break;
      
      default:
         printf("Opción inválida\n");
        break;
    }
  } else {
    printf("Opción inválida\n");
   // MenuPrincipal(usuario,producto);
  }
  return 0;
}*/
struct Venta venderProducto(struct Producto producto) {
  struct Venta venta;

  printf("Ingrese el local: ");
  scanf("%s", venta.local);
  printf("Ingrese el vendedor: ");
  scanf("%s", venta.vendedor);
  printf("Ingrese la fecha de venta: ");
  scanf(" %c", venta.fechaVenta);
  printf("Ingrese el precio de venta: ");
  scanf("%f", &venta.precioVenta);
  printf("Ingrese la cantidad del producto vendida:\n ");
  scanf("%d", &venta.cantidadProducto);

  producto.cantidadProducto =
      producto.cantidadProducto - venta.cantidadProducto;

  return venta;
}
void leerUsuarios(struct Usuario usuarios[]) {
  FILE *file = fopen("usuarios.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  int i = 0;
  while (fscanf(file, "%s %s", usuarios[i].cargo, usuarios[i].clave) != EOF) {
    i++;
  }
// EOF - End Of File
  fclose(file);
}

void escribirUsuarios(struct Usuario usuarios[]) {
  FILE *file = fopen("usuarios.txt", "w");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (usuarios[i].cargo[0] != '\0') {
      fprintf(file, "%s %s\n", usuarios[i].cargo, usuarios[i].clave);
    }
  }

  fclose(file);
}

void leerProductos(struct Producto productos[]) {
  FILE *file = fopen("productos.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }
  // Leer los datos del archivo y llenar el arreglo de productos
  fclose(file);
}
void escribirProductos(struct Producto productos[]) {
  FILE *file = fopen("productos.txt", "w");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }
  // Escribir los datos del arreglo de productos al archivo
  fclose(file);
}
void leerVentas(struct Venta ventas[]) {
  FILE *file = fopen("ventas.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }
  // Leer los datos del archivo y llenar el arreglo de ventas
  fclose(file);
}
void escribirVentas(struct Venta ventas[]) {
  FILE *file = fopen("ventas.txt", "w");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }
  // Escribir los datos del arreglo de ventas al archivo
  fclose(file);
}
