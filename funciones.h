#include <stdio.h>
#include <string.h>

struct Producto {
  char nombre[20];
  char categoria[20];
  char marca[20];
  int codigo;
  int cantidadProducto;
  float precioCompra;
  char bodega[20];
};

struct Usuario {
  char cargo[30];
  char clave[30];
};

struct Venta {
  char local[20];
  char vendedor[20];
  char fechaVenta[70];
  float precioVenta;
  int cantidadProducto;
};

struct Usuario crearUsuario();
void actualizarUsuario(struct Usuario);
struct Producto crearProducto();
void actualizarProducto(struct Producto);
struct Venta venderProducto(struct Producto);
int MenuPrincipal(struct Usuario usuarios[], struct Producto productos[]);
void leerUsuarios(struct Usuario usuarios[]);
void escribirUsuarios(struct Usuario usuarios[]);
void leerProductos(struct Producto productos[]);
void escribirProductos(struct Producto productos[]);
void leerVentas(struct Venta ventas[]);
void escribirVentas(struct Venta ventas[]);
