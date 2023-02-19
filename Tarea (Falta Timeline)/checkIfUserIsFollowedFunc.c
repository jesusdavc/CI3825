#include <checkIfUserIsFollowedFunc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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