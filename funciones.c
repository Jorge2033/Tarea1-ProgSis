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
  scanf(" %c", &producto.bodega);
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

int MenuPrincipal(struct Usuario usuario, struct Producto producto) {
  char opcion[30];
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
        crearUsuario();
        printf("1. crear otro usuario\n");
        printf("2. salir\n");
        int seleccion2;
        scanf("%d",&seleccion2);
        switch(seleccion2){
          case 1:
          crearUsuario();
          break;
          case 2:
          MenuPrincipal(usuario,producto);
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
          MenuPrincipal(usuario,producto);
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
          MenuPrincipal(usuario,producto);
          break;
          case 2:
          crearUsuario();
          break;
          default:
          printf("Opción inválida\n");
            MenuPrincipal(usuario,producto);
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
          MenuPrincipal(usuario,producto);
          break;
          case 2:
            actualizarUsuario(usuario);
          break;
          
        break;
      default:
        printf("Opción inválida\n");
          MenuPrincipal(usuario,producto);
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
        venderProducto(producto);
        printf("1.vender otro producto\n");
        printf("2.salir\n");
        int choice;
        scanf("%d",&choice);
        switch (choice){
          case 1:
          venderProducto(producto);
          break;
          case 2:
          MenuPrincipal(usuario,producto);
          break;
        }
        break;
      case 2:
      MenuPrincipal(usuario,producto);
      break;
      
      default:
         printf("Opción inválida\n");
        break;
    }
  } else {
    printf("Opción inválida\n");
    MenuPrincipal(usuario,producto);
  }
  return 0;
}


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
