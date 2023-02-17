//
//  main.c
//  sistemas
//
//  Created by Jhonaiker Blanco on 16/2/23.
//  Copyright © 2023 Jhonaiker Blanco. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define HASH_SIZE 20

int getHash(char text[20]){
    int counter = 0;
    
    for(int i = 0; i < strlen(text); i++){
        counter = counter + text[i];
    }
    return counter % 50;
}


int main(int argc, const char * argv[]) {

    typedef struct user {
        char username[20];
        char description[100];
        int password;
        char *tweets[5][280];
        struct user *followers[20];
    } user;
    
    char action[10];
    char newUsername[20];
    char newPassword[20];
    char description[100];
    char username[20];
    char password[20];
    int currentHashValue = 0;
    
    struct user usersInProgam[50][4];
    int amountOfUsersByHash[50];
    int amountOfUsersInCurrentHash = 0;
    
    int positionInHashOfUser = 0;
    
    int userTaken = 0;


    
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
                printf("Username already taken");
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
                    char userToLogin[20] = "";
                    
                    //int amountOfUsersByHash[50];
                    int amountOfUsersInCurrentHash = 0;
                    
                    
                    while(strcmp("logout", nextAction) != 0){
                        printf("WHAT’S HAPPENING? \n");
                        scanf("%s", nextAction);
                        
                        if(strcmp("+", nextAction) == 0){
                            printf("You can write a new tweet \n");
                        } else if(strcmp("@", nextAction) == 0){
                            
                            
                            char userToCheck[20];
                            printf("Check a user: ");
                            scanf("%s", userToCheck);
                            
                            currentHashValue = getHash(userToCheck);
                            amountOfUsersInCurrentHash = amountOfUsersByHash[currentHashValue];
                            
                            int userExists = 0;
                            int positionInHashOfUser = 0;
                            
                            for(int i = 0; i < amountOfUsersInCurrentHash; i++){
                                if(strcmp(usersInProgam[currentHashValue][i].username, userToCheck) == 0){
                                    userExists = 1;
                                    positionInHashOfUser = i;
                                    break;
                                }
                            }
                            if(userExists){
                                printf("The user exists! \n");
                                printf("Its description is: %s \n", usersInProgam[currentHashValue][positionInHashOfUser].description);
                                
                            } else {
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
