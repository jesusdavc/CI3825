# Compilador y Flags
CC = gcc
CFLAGS = -Wall -g -pedantic
TARGET = twitter
FUENTE = main


# Archivos
all: $(TARGET)

$(TARGET): $(FUENTE).c
	$(CC) $(CFLAGS) -o $(TARGET) $(FUENTE).c

# Limpiar
clean:
	$(RM) $(TARGET)