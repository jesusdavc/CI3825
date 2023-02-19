#ifndef ESTRUCTURAS
#define ESTRUCTURAS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Lista enlazada que sirve para guardar los usuarios seguidos por alguien
struct userFollowed {
    char username[20];
    struct userFollowed* nextUserFollowed;
};

// Lista enlazada que guarda tweets
struct tweet {
    char text[280];
    time_t timeOfTweet;
    struct tweet* prevTweet;
    struct tweet* nextTweet;
    char username[20];
};

// Estructura enlazada que guarda datos de un usuario
struct userElement {
    char username[20];
    char description[100];
    int password;
    struct tweet nextTweet;
    struct userFollowed nextUserFollowed;
};

#endif