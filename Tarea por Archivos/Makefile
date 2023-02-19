# Compilador y Flags
CC = gcc
CFLAGS = -Wall -g -pedantic -I.
TARGET = twitter backend
OBJ = main.o getHashFunc.o checkIfUserIsFollowedFunc.o addTweetToListFunc.o showTweetsOfUserFunc.o showFollowersOfUserFunc.o
OBJBack = mainBackend.o getHashFunc.o checkIfUserIsFollowedFunc.o addTweetToListFunc.o showTweetsOfUserFunc.o showFollowersOfUserFunc.o

all: $(TARGET)

twitter: $(OBJ)
	$(CC) -o twitter $(OBJ) $(CFLAGS)

# Solo compilar Backend
backend:	$(OBJBack)
	$(CC) -o backend $(OBJBack) $(CFLAGS)

# Limpiar
clean:
	$(RM) $(TARGET) *.o
