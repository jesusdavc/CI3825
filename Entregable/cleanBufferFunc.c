#include <stdio.h>
#include <stdlib.h>
#include <cleanBufferFunc.h>

// Esta funcion limpia el buffer
void cleanBuffer(){
    int c;
    do{
        c = getchar();
    }
    while(c != EOF && c != '\n');
}
