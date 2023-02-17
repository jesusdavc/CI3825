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
    int currentUser = 0;
    int iterator = 0;
    int currentHashValue = 0;
    
    struct user usersInProgam[50][4];
    int amountOfUsersByHash[50];
    int amountOfUsersInCurrentHash;
    
    int userTaken = 0;


    
    while(strcmp("leave", action) != 0){
        printf("DON’T MISS WHAT’S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        scanf("%s", action);
        
        if(strcmp("signup", action) == 0){
            
            printf("Username: \n");
            scanf("%s", newUsername);
            
            printf("Password: \n");
            scanf("%s", newPassword);
            
            printf("Description: \n");
            scanf("%s", description);
            
            currentHashValue = getHash(newUsername);
            
            amountOfUsersInCurrentHash = amountOfUsersByHash[currentHashValue];
            
            userTaken = 0;
            
            for(int i = 0; i < amountOfUsersInCurrentHash; i++){
                if(strcmp(usersInProgam[amountOfUsersInCurrentHash][i].username, newUsername) == 0){
                    userTaken = 1;
                }
            }
            
            if(userTaken == 1){
                printf("Username already taken");
            } {
                strcpy(usersInProgam[currentHashValue][amountOfUsersInCurrentHash].username, newUsername);
                strcpy(usersInProgam[currentHashValue][amountOfUsersInCurrentHash].description, description);
                usersInProgam[currentHashValue][amountOfUsersInCurrentHash].password = getHash(newPassword);
                
                amountOfUsersByHash[currentHashValue] = amountOfUsersByHash[currentHashValue] + 1;
            }
            
            
        } else if(strcmp("login", action) == 0){
            
            printf("Username: \n");
            scanf("%s", username);
            
            printf("Password: \n");
            scanf("%s", password);
            
        } else if(strcmp("leave", action) == 0){
            printf("You leaved the app\n");
        } else {
           printf("Unvalid action \n");
        }
    }

    return 0;
}

