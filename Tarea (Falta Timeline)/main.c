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
#include <getHashFunc.h>
#include "estructuras.h"
#include <checkIfUserIsFollowedFunc.h>
#include <addTweetToListFunc.h>
#include <showTweetsOfUserFunc.h>

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


/*void showTimeline(int amountOfUsersByHash[50],struct userElement usersInProgam[50][4],struct userFollowed * userInAccount) {
    
    struct userFollowed * userThatIsFollowed = userInAccount->nextUserFollowed;
    
    struct tweet * tweetTimeline = NULL;
    
    tweetTimeline = (struct tweet*)malloc(sizeof(struct tweet));
    
    int numberOfTweetsInTimeline = 0;
    
    while ( userThatIsFollowed != NULL) {
        
        userThatIsFollowed = userThatIsFollowed->nextUserFollowed;
        
        int positionOfCurrentUser = 0;
        int currentHash = getHash(userThatIsFollowed->username);
        int amountOfUsersWithCurrentHash = amountOfUsersByHash[currentHash];
        
        
        for(int i = 0; i < amountOfUsersWithCurrentHash; i++){
            if(strcmp(usersInProgam[currentHash][i].username, userThatIsFollowed->username)== 0){
                positionOfCurrentUser = i;
                break;
            }
        }
        
        struct tweet* currentTweetOfUser = usersInProgam[currentHash][positionOfCurrentUser].nextTweet->nextTweet;
        
        while(currentTweetOfUser != NULL)}{
            amountOfTweets++;
            createTimelimeLinkedList(tweetTimeline, currentTweetOfUser,amountOfTweets);
        }
    }
    
    
}*/

/*void createTimelimeLinkedList(struct tweet *headTimeline, struct tweet * newTweetTimeline, int amountOfTweets){
    if(amountOfTweets == 0){
        strcpy(headTimeline->text, newTweetTimeline->text);
        headTimeline->timeOfTweet = newTweetTimeline->timeOfTweet;
        strcpy(headTimeline->username, newTweetTimeline->username);
        headTimeline->nextTweet = NULL;
    } else {
        
        struct tweet * currentTweetInTimeline = (struct tweet*)malloc(sizeof(struct tweet));
        strcpy(currentTweetInTimeline->text, newTweetTimeline->text);
        currentTweetInTimeline->timeOfTweet = newTweetTimeline->timeOfTweet;
        strcpy(currentTweetInTimeline->username, newTweetTimeline->username);
        headTimeline->nextTweet = NULL;
        
        while (headTimeline != NULL) {
            if(difftime(currentTweetInTimeline->timeOfTweet,headTimeline->timeOfTweet) > 0 && headTimeline->nextTweet == NULL){
                headTimeline->nextTweet = currentTweetInTimeline;
                break;
            } else if(difftime(currentTweetInTimeline->timeOfTweet,headTimeline->timeOfTweet) > 0){
                headTimeline = headTimeline->nextTweet;
            }
            
            else {
                currentTweetInTimeline->nextTweet = headTimeline;
                headTimeline = currentTweetInTimeline;
                break;
            }
        }
        
        
    }
}*/

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
    
    
    
    while(strcmp("leave", action) != 0){
        printf("DON'T MISS WHAT’S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
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
                    int salir = 0;
                    
                    while(salir != 1){
                        printf("WHAT’S HAPPENING? \n");
                        scanf("%s", nextAction);
                        
                        if(strcmp("+", nextAction) == 0){
                            //fflush(stdin);
                            
                            char textOfNewTweet[280];
                            
                            printf("You can write a new tweet \n");
                            printf("New tweet: ");        
                            fgets(textOfNewTweet, 280, stdin);                            
                            printf("Lo que tuiteaste fue: %s", textOfNewTweet);
                            
                            addTweetToList(&usersInProgam[currentHashValue][positionInHashOfUser].nextTweet, textOfNewTweet, usersInProgam[currentHashValue][positionInHashOfUser].username);
                            
                            
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
                            salir = 1;
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