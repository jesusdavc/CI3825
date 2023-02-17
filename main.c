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
    int amountOfUsersInCurrentHash;
    
    int positionInHashOfUser = 0;
    
    int userTaken = 0;


    
    while(strcmp("leave", action) != 0){
        printf("DON’T MISS WHAT’S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
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
                
                //printf("username %s \n", usersInProgam[currentHashValue][amountOfUsersInCurrentHash].username);
                //printf("description %s \n", usersInProgam[currentHashValue][amountOfUsersInCurrentHash].description);
                //printf("password %d \n", usersInProgam[currentHashValue][amountOfUsersInCurrentHash].password);
                //printf("hashValue: %d \n",currentHashValue);
                //printf("currentHash: %d \n",amountOfUsersByHash[currentHashValue]);
            }
            
            
        } else if(strcmp("login", action) == 0){
            
            printf("Username: ");
            scanf("%s", username);
            
            currentHashValue = getHash(username);
            amountOfUsersInCurrentHash = amountOfUsersByHash[currentHashValue];
            
            
            userTaken = 0;
            
            for(int i = 0; i < amountOfUsersInCurrentHash; i++){
                //printf("struct data: %s \n",usersInProgam[amountOfUsersInCurrentHash][i].username);
                //printf("variable: %s \n",username);
                if(strcmp(usersInProgam[currentHashValue][i].username, username) == 0){
                    userTaken = 1;
                    positionInHashOfUser = i;
                    break;
                }
            }
            
            if(userTaken == 1){
                
                printf("Password: \n");
                scanf("%s", password);
                
                if(usersInProgam[currentHashValue][positionInHashOfUser].password == getHash(password)){
                    printf("Login successfully \n");
                    char nextAction[20];
                    while(strcmp("logout", nextAction) != 0){
                    
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
