# Compilador y Flags
CC = gcc
CFLAGS = -Wall -g -pedantic -I.
TARGET = twitter backend
OBJ = main.o getHashFunc.o cleanBufferFunc.o checkIfUserIsFollowedFunc.o addTweetToListFunc.o showTweetsOfUserFunc.o showFollowersOfUserFunc.o 
OBJBack = mainBackend.o getHashFunc.o cleanBufferFunc.o checkIfUserIsFollowedFunc.o addTweetToListFunc.o

# Por defecto si solo se hace make entonces se compila el progama principal "twitter" y el backend en "backend".
all: $(TARGET)

# Programa principal. Se corre usando "./twitter" 
twitter: $(OBJ)
	$(CC) -o twitter $(OBJ) $(CFLAGS)

# Solo compilar Backend
backend:	$(OBJBack)
	$(CC) -o backend $(OBJBack) $(CFLAGS)

# Limpiar
clean:
	$(RM) $(TARGET) *.o
