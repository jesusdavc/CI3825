#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
	char tweet;
	struct Nodo *nextInLine;
};

struct Nodo *getNewTweet(const char tweet) 
{
    printf("Tengo en age: %s", tweet);
    struct Nodo *newTweet = NULL;
    newTweet = malloc(sizeof(struct Nodo));
    char temp[280] = "h";
    strcpy(temp, tweet);
    printf("Llegue aqui\n");
    if (newTweet != NULL)
    {
        newTweet->nextInLine = NULL;
        strcpy(newTweet->tweet, temp);
        printf("created new person at %p\n", newTweet);
    }
	else
	{
		printf("Allocation Failure!! \n");
	}
    return newTweet;
}

void printTweet(const struct Nodo *storedTweet, const char *comment)
{
    if (storedTweet == NULL)
    {
        printf("%s is NULL\n", comment);
    }
    else
    {
       printf("%s: tweet:%s address:%p nextInLine:%p\n", 
            comment,
            storedTweet->tweet, 
            storedTweet,
            storedTweet->nextInLine);
    }
    
}

void PrintList(const struct Nodo *list)
{
	printf("Printing List:\n");
	const struct Nodo *t;
	t = list;
    if(t == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(t)
        {
            printTweet(t, "t");
            t = t->nextInLine;
        }
    }
}


int main() 
{
	printf("\n\n** START **\n\n");

    struct Nodo *first = NULL;
    struct Nodo *added = NULL;

    char command[280];
	char tweet[280] = "h";

    while(1)
    {
        printf( "Enter a command or value : ");
		fgets(command, 280, stdin);
		if (strcmp("q\n", command) == 0) 
		{
			printf("Quitting..\n");
			break;
		}
		else if (strcmp("print\n", command) == 0) 
        {
            printf("Printing..\n");
            PrintList(first);
        }
        else /*if(sscanf(command, "%d", &tweet) != 0)*/
        {
            printf("Texto introducido: %s", command);
            strcpy(tweet, command);
            printf("Texto introducido en tweet: %s", tweet);
            //printf("Adding %s\n", tweet);
            
            if (first == NULL)
            {
                
                first = getNewTweet(tweet);

                if(first != NULL)
                {
                    added = first;
                }
            }
            else
            {
                
                added->nextInLine = getNewTweet(tweet);
                if(added->nextInLine != NULL)
                {
                    added = added->nextInLine;
                }
            }
            printf("Llegue a crear el nodo");
            
        }
    }

	return 0;
}