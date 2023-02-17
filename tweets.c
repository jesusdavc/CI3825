#include <stdio.h>
#include <stdlib.h>





// Tweet creation with Node struct
struct Node {
  int data;
  char tweet[280];
  struct Node* next;
  struct Node* prev;
};

char tweetString[280]

// insert node at the front
void insertFront(struct Node** head, int data, char tweet[280]) {
  // allocate memory for newNode
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // assign data to newNode
  newNode->data = data;

  newNode->tweet = tweet;

  // make newNode as a head
  newNode->next = (*head);

  // assign null to prev
  newNode->prev = NULL;

  // previous of head (now head is the second node) is newNode
  if ((*head) != NULL)
    (*head)->prev = newNode;

  // head points to newNode
  (*head) = newNode;
}


// insert a newNode at the end of the list
void insertEnd(struct Node** head, int data, char tweet[280]){
  // allocate memory for node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // assign data to newNode
  newNode->data = data;

  newNode -> tweet;

  // assign null to next of newNode
  newNode->next = NULL;

  // store the head node temporarily (for later use)
  struct Node* temp = *head;

  // if the linked list is empty, make the newNode as head node
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  // if the linked list is not empty, traverse to the end of the linked list
  while (temp->next != NULL)
    temp = temp->next;
  // now, the last node of the linked list is temp

  // assign next of the last node (temp) to newNode
  temp->next = newNode;
  // assign prev of newNode to temp
  newNode->prev = temp;
}

// print the doubly linked list
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}



