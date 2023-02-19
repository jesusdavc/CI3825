//
//  main.c
//  sistemas
//
//  Created by Jhonaiker Blanco on 16/2/23.
//  Copyright © 2023 Jhonaiker Blanco. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int getHash(char text[20]){
    int counter = 0;
    
    for(int i = 0; i < strlen(text); i++){
        counter = counter + text[i];
    }
    return counter % 50;
}

struct userFollowed {
    char username[20];
    struct userFollowed* nextUserFollowed;
};

struct tweet {
    char text[280];
    time_t timeOfTweet;
    struct tweet* nextTweet;
};

struct userElement {
    char username[20];
    char description[100];
    int password;
    struct tweet nextTweet;
    struct userFollowed nextUserFollowed;
};

int checkIfUserIsFollowed (struct userFollowed* userFollowedToCheck, char userToCheckIfItsFollowed[20]) {
    printf("funcion checkeado %s \n", userToCheckIfItsFollowed);
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

/* Add a new node to the bottom of a list */
struct userFollowed * addUserToFollowersList(struct userFollowed *firstUserFollowed, char newUser[20]) {
    struct userFollowed *currentUserFollowed = firstUserFollowed;
    struct userFollowed *newUserToFollow;
    while ( currentUserFollowed != NULL && currentUserFollowed->nextUserFollowed != NULL) {
        currentUserFollowed = currentUserFollowed->nextUserFollowed;
    }
    
    newUserToFollow = (struct userFollowed *) malloc(sizeof(struct userFollowed));
    strcpy(newUserToFollow->username, newUser);
    newUserToFollow->nextUserFollowed= NULL;
    if (currentUserFollowed != NULL)
        currentUserFollowed->nextUserFollowed = newUserToFollow;
    else
        firstUserFollowed = newUserToFollow;
    return firstUserFollowed;
}

void addTweetToList(struct tweet * firstTweetOfUser, char newTweet[280]) {
    
    
    struct tweet *currentTweetInList = firstTweetOfUser;
    struct tweet *newTweetToAdd;
    
    if(firstTweetOfUser == NULL){
        
        newTweetToAdd->nextTweet = NULL;
        newTweetToAdd->timeOfTweet = time(0);
        strcpy(newTweetToAdd->text, newTweet);
        
        firstTweetOfUser = newTweetToAdd;
    } else {
    
    while ( currentTweetInList != NULL && currentTweetInList->nextTweet != NULL) {
        currentTweetInList = currentTweetInList->nextTweet;
    }
    
    newTweetToAdd = (struct tweet *) malloc(sizeof(struct tweet));
    strcpy(newTweetToAdd->text, newTweet);
    newTweetToAdd->nextTweet = NULL;
    newTweetToAdd->timeOfTweet = time(0);
    if (currentTweetInList != NULL)
        currentTweetInList->nextTweet = newTweetToAdd;
    else
        firstTweetOfUser = newTweetToAdd;
    }
}

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

int main(int argc, const char * argv[]) {
    
    char action[10];
    char newUsername[20];
    char newPassword[20];
    char description[100];
    char username[20];
    char password[20];
    char wantToFollow[10];
    int currentHashValue = 0;
    
    
    struct userElement usersInProgam[50][4];
    int amountOfUsersByHash[50];
    int amountOfUsersInCurrentHash = 0;
    
    int positionInHashOfUser = 0;
    
    int userTaken = 0;
    
    int isUserFollowed = 0;
    
    //Check if user is in list
    //Add user to list
    
    
    
    while(strcmp("leave", action) != 0){
        printf("DON’T MISS WHAT’S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        strcpy(action, "");
        scanf("%s", action);
        
        if(strcmp("signup", action) == 0){
            
            printf("Username: ");
            scanf("%s", newUsername);
            
            printf("Password: ");
            scanf("%s", newPassword);
            
            printf("Description: ");
            scanf("%s", description);
            
            currentHashValue = getHash(newUsername);
            
            amountOfUsersInCurrentHash = amountOfUsersByHash[currentHashValue];
            
            userTaken = 0;
            
            for(int i = 0; i < amountOfUsersInCurrentHash; i++){
                if(strcmp(usersInProgam[amountOfUsersInCurrentHash][i].username, newUsername) == 0){
                    userTaken = 1;
                    break;
                }
            }
            
            if(userTaken == 1){
                printf("Username already taken \n");
            } else {
                strcpy(usersInProgam[currentHashValue][amountOfUsersInCurrentHash].username, newUsername);
                strcpy(usersInProgam[currentHashValue][amountOfUsersInCurrentHash].description, description);
                usersInProgam[currentHashValue][amountOfUsersInCurrentHash].password = getHash(newPassword);
                
                amountOfUsersByHash[currentHashValue] = amountOfUsersByHash[currentHashValue] + 1;
            }
            
        } else if(strcmp("login", action) == 0){
            
            printf("Username: ");
            scanf("%s", username);
            
            currentHashValue = getHash(username);
            amountOfUsersInCurrentHash = amountOfUsersByHash[currentHashValue];
            
            
            userTaken = 0;
            
            for(int i = 0; i < amountOfUsersInCurrentHash; i++){
                
                if(strcmp(usersInProgam[currentHashValue][i].username, username) == 0){
                    userTaken = 1;
                    positionInHashOfUser = i;
                    break;
                }
            }
            
            if(userTaken == 1){
                
                printf("Password: ");
                scanf("%s", password);
                
                if(usersInProgam[currentHashValue][positionInHashOfUser].password == getHash(password)){
                    printf("Login successfully \n");
                    char nextAction[10] = "";
                    
                    while(strcmp("logout", nextAction) != 0){
                        printf("WHAT’S HAPPENING? \n");
                        scanf("%s", nextAction);
                        
                        if(strcmp("+", nextAction) == 0){
                            
                            char textOfNewTweet[280];
                            
                            printf("You can write a new tweet \n");
                            printf("New tweet: ");
                            scanf("%s", textOfNewTweet);
                            
                            addTweetToList(&usersInProgam[currentHashValue][positionInHashOfUser].nextTweet, textOfNewTweet);
                            
                            
                        } else if(strcmp("@", nextAction) == 0){
                            
                            
                            char userToCheck[20];
                            printf("Check a user: ");
                            scanf("%s", userToCheck);
                            
                            int currentHashValueToCheck = getHash(userToCheck);
                            int amountOfUsersInCurrentHashToCheck = amountOfUsersByHash[currentHashValueToCheck];
                            
                            int userExists = 0;
                            int positionInHashOfUserToCheck = 0;
                            isUserFollowed = 0;
                            
                            
                            for(int i = 0; i < amountOfUsersInCurrentHashToCheck; i++){
                                if(strcmp(usersInProgam[currentHashValueToCheck][i].username, userToCheck) == 0){
                                    userExists = 1;
                                    positionInHashOfUserToCheck = i;
                                    break;
                                }
                            }
                            if(userExists){
                                
                                showTweetsOfUser(&usersInProgam[currentHashValueToCheck][positionInHashOfUserToCheck].nextTweet);
                                
                                if(strcmp(userToCheck,username) == 0){
                                    printf("You can't follow yourself \n");
                                } else {
                                    printf("The user exists! \n");
                                    printf("Its description is: %s \n", usersInProgam[currentHashValueToCheck][positionInHashOfUserToCheck].description);
                                    
                                    currentHashValue = getHash(username);
                                    for(int i = 0; i < amountOfUsersByHash[currentHashValue]; i++){
                                        if(strcmp(usersInProgam[currentHashValue][i].username, username) == 0){
                                            userExists = 1;
                                            positionInHashOfUser = i;
                                            break;
                                        }
                                    }
                                    
                                    
                                    isUserFollowed = checkIfUserIsFollowed(&usersInProgam[currentHashValue][positionInHashOfUser].nextUserFollowed, userToCheck);
                                    
                                    
                                    if(isUserFollowed == 1){
                                        printf("You already follow this user \n");
                                    } else {
                                        
                                        strcpy(wantToFollow,"");
                                        while(strcmp("no", wantToFollow) != 0 && strcmp("yes", wantToFollow) != 0){
                                            printf("Do you want to follow to this user? write 'yes' or 'no' \n");
                                            scanf("%s", wantToFollow);
                                            
                                            if(strcmp("yes", wantToFollow) == 0){
                                                printf("Now you follow this user \n");
                                                addUserToFollowersList(&usersInProgam[currentHashValue][positionInHashOfUser].nextUserFollowed, userToCheck);
                                            } else if(strcmp("no", wantToFollow) == 0){
                                                printf("You don't want to follow this user \n");
                                            } else {
                                                printf("This command does not exist \n");
                                            }
                                        }
                                    }
                                    
                                }
                            }
                            
                            else {
                                printf("This user does not exist \n");
                            }
                            
                            
                        } else if(strcmp("logout", nextAction) == 0){
                            printf("You logout from your account \n");
                        } else {
                            printf("That command does not exist \n");
                        }
                    }
                } else {
                    printf("Wrong password \n");
                }
                
            } else {
                printf("There is not a user with that username \n");
            }
            
        } else if(strcmp("leave", action) == 0){
            printf("You leaved the app\n");
        } else {
            printf("Unvalid action \n");
        }
    }
    
    return 0;
}
