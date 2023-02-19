#include <showTweetsOfUserFunc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "estructuras.h"

void showTweetsOfUser (struct tweet * currentTweet) {
    
    int numberOfCurrentTweet = 0;
    if(currentTweet->nextTweet != NULL){
        currentTweet = currentTweet->nextTweet;
    }
    
    while ( currentTweet != NULL) {
        numberOfCurrentTweet++;
        printf("Tweet number %d: %s \n", numberOfCurrentTweet, currentTweet->text);
        currentTweet = currentTweet->nextTweet;
    }
    
    if(numberOfCurrentTweet == 0){
        printf("This user does not have tweets \n");
    }
}