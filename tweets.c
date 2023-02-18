#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct list_node {
   char* tweet;
   int id_tweet;
   struct list_node* previous;
   struct list_node* next;
};

typedef struct list_node node;

int count(node* head) {
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}
	return count;
}

node* get_by_index(int index, node* head) {
	int counter = count(head);
	int i = 0;
	if (index < 0 || index > counter) {
		return NULL;
	}
	for (i = 0; i <= index; i++) {
		if (i == index) {
			return head;
		}
		head = head->next;
	}
	return head;
}

node* remove_first(node* head) {
	head = head->next;
	free(head->previous);
	head->previous = NULL;
	return head;
}

int remove_last(node* head) {
	while(head) {
		if (head->next->next == NULL) {
			free(head->next);
			head->next = NULL;
			return 0;
		}
		head = head->next;
	}
	return -1;
}

node* remove_at_index(int index, node* head) {
	node* current;
	if (index == 0) {
		return remove_first(head);
	} else if ( index < 0) {
		return head;
	}
	current = get_by_index(index, head);
	if (current == NULL) {
		return head;
	}
	current->previous->next = current->next;
	if (current->next != NULL) {
		current->next->previous = current->previous;
	}
	free(current);
	return head;
}

node* add_first(char* tweet, int id_tweet, node* head) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node->tweet = tweet;
	new_node->id_tweet = id_tweet;
    new_node->next = head;
	if (head != NULL) {
		head->previous = new_node;
	}
    head = new_node;
	return head;
}

void add_after(char* tweet, int id_tweet, node* head) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node->tweet = tweet;
	new_node->id_tweet = id_tweet;
	new_node->next = head->next;
	new_node->previous = head;
	new_node->next->previous = new_node;
	head->next = new_node;
}

void add_last(char* tweet, int id_tweet, node* current) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	while(current) {
		if (current->next == NULL) {
			current->next = new_node;
			new_node->tweet = tweet;
			new_node->id_tweet = id_tweet;
			new_node->previous = current;
			return;
		}
		current = current->next;
	}
}

void print_list(node* current) {
	while(current) {
		printf("%s %d", current->tweet, current->id_tweet);
		printf(" -> ");
		current = current->next ;
	}
}

void print_list_backwards(node* current) {
	while(current) {
		printf("%s %d", current->tweet, current->id_tweet);
		printf(" <- ");
		current = current->previous ;
	}
}

int main(void) {
	node* head = NULL;
	node* tail = NULL;
	int number;
	unsigned int id_tweet = 0;
	
	/* adding the first element requires setting the head. */
	head = add_first("First Tweet by Elon Musk", id_tweet++, head);
	
	/* adding the rest as the last element. */
	add_last("Second Tweet", id_tweet++, head);
	add_last("I hate C sorry not sorry ", id_tweet++, head);
	
	print_list(head);
	return 0;
}

