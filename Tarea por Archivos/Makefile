# Compilador y Flags
CC = gcc
CFLAGS = -Wall -g -pedantic -I.
TARGET = twitter
OBJ = main.o getHashFunc.o checkIfUserIsFollowedFunc.o addTweetToListFunc.o showTweetsOfUserFunc.o

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

# Limpiar
clean:
	$(RM) $(TARGET) *.o