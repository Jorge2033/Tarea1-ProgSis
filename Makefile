# Makefile

# Nombre del ejecutable
TARGET = mi_proyecto

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Archivos fuente
SRCS = main.c Funciones.c

# Archivos objeto generados durante la compilación
OBJS = $(SRCS:.c=.o)

# Regla principal para construir el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar archivos fuente a archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Eliminar archivos objeto y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)
