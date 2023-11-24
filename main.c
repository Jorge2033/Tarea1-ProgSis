#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(void) {
  struct Producto productos[50];
  struct Usuario usuarios[10];
  struct Producto producto1= {"Leche", 20, 5, 5};
  struct Producto producto2= {"Pan", 15, 5, 5};
  struct Usuario usuario1= {"Juan", "Administrador"};  
  MenuPrincipal(usuario1,producto1);
  
  
  return 0;
}
