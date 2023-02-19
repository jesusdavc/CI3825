#ifndef ESTRUCTURAS
#define ESTRUCTURAS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

#endif