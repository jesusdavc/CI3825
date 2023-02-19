#include <showTweetsOfUserFunc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "estructuras.h"

// Funcion para mostrar los tweets de un usuario
void showTweetsOfUser (struct tweet * currentTweet) {
    
    int numberOfCurrentTweet = 0;
    if(currentTweet->nextTweet != NULL){
        currentTweet = currentTweet->prevTweet;
    }
    
    while ( currentTweet != NULL) {
        numberOfCurrentTweet++;
        printf("Tweet number %d: %s \n", numberOfCurrentTweet, currentTweet->text);
        currentTweet = currentTweet->prevTweet;
    }
}