#include <checkIfUserIsFollowedFunc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Funcion que revisa si un usiario sigue a otro, regresa 1 si lo sigue, regresa 0 si no lo sigue
int checkIfUserIsFollowed (struct userFollowed* userFollowedToCheck, char userToCheckIfItsFollowed[20]) {
    int result = 0;
    
    while (userFollowedToCheck != NULL) {
        if(strcmp(userFollowedToCheck->username,userToCheckIfItsFollowed) == 0){
            result = 1;
            break;
        }
        userFollowedToCheck = userFollowedToCheck->nextUserFollowed;
    }
    
    return result;
}