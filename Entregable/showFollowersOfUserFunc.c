#include <showFollowersOfUserFunc.h>

// Funcion para mostrar los seguidores de un usuario
void showFollowersOfUser (struct userFollowed * currentUser) {
    
    int numberOfCurrentFollowers = 0;
    if(currentUser->nextUserFollowed != NULL){
        currentUser = currentUser->nextUserFollowed;
    }
    
    while ( currentUser != NULL) {
        numberOfCurrentFollowers++;
        printf("Follower %d: %s \n", numberOfCurrentFollowers, currentUser->username);
        currentUser = currentUser->nextUserFollowed;
    }    
}