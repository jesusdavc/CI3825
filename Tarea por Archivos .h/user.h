typedef struct user {
        char username[20];
        char description[100];
        int password;
        char *tweets[5][280];
        char usersFollowed[200][20];
        int amountOfUsersFollowed;
    } user;