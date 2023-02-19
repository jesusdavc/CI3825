#include "estructuras.h"
#include <addTweetToListFunc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Funcion para añadir un tweet a la lista de tweets de un usario
void addTweetToList(struct tweet * firstTweetOfUser, char newTweet[280], char userThatSentTheTweet[20]) {
    
    struct tweet *currentTweetInList = firstTweetOfUser;
    struct tweet *newTweetToAdd;
    
    if(firstTweetOfUser == NULL){
        
        newTweetToAdd->nextTweet = NULL;
        newTweetToAdd->timeOfTweet = time(0);
        strcpy(newTweetToAdd->text, newTweet);
        strcpy(newTweetToAdd->username, userThatSentTheTweet);
        
        firstTweetOfUser = newTweetToAdd;
    } else {
        
        while ( currentTweetInList != NULL && currentTweetInList->nextTweet != NULL) {
            currentTweetInList = currentTweetInList->nextTweet;
        }
        
        newTweetToAdd = (struct tweet *) malloc(sizeof(struct tweet));
        strcpy(newTweetToAdd->text, newTweet);
        strcpy(newTweetToAdd->username, userThatSentTheTweet);
        newTweetToAdd->nextTweet = NULL;
        newTweetToAdd->timeOfTweet = time(0);
        if (currentTweetInList != NULL)
            currentTweetInList->nextTweet = newTweetToAdd;
        else
            firstTweetOfUser = newTweetToAdd;
    }
}