#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

// linked list
Node* head = NULL;

void insertData(int data) {
	// create the node data
	Node* new = malloc(sizeof(Node));	
	if (new == NULL) {
		// failed to malloc node
		return;
	}
	new->data = data;

	// set the ptr the new node, point to the ptr of the head
	new->next = head;

	// the head ptr to the new node
	head = new;
}

void deleteData() {
	// current node (first) 
	Node* current = head;
	if (current != NULL) {
		head = current->next;

		// free the deleted node
		free(current);
	}
}

void deleteDataAtElement(int index) {
	// get the current node
	Node* current = head;
	Node* previous = NULL;
	
	// while the current node isnt a NULL pointer
	int i = 0;
	while (current != NULL) {
		if (i == index) {
			printf("deleted index %d\n", index);	
			// set the pointer to the next over ptr
			Node* next_node = current->next;
			previous->next = next_node;
			
			// free the deleted node
			free(current);

			return;
		}
		
		previous = current;
		current = current->next;
		i++;
	}
	printf("index is out of bounds\n");
}

void displayList() {
	printf("current list: \n");

	// current is the head pointer to the node
	Node* current = head;
	// is the current ptr null?
	while (current != NULL) {
		printf("%d->", current->data);
		
		// set the current to the next node
		current = current->next;
	}
	printf("\n\n");
}

void searchForIndex(int index) {
	// get the current node
	Node* current = head;
	
	// while the current node isnt a NULL pointer
	int i = 0;
	while (current != NULL) {
		if (i == index) {
			printf("index found, value: %d\n", current->data);		

			return;
		}
		
		current = current->next;
		i++;
	}
	printf("index is out of bounds\n");
}

int main() {
	// get the input of the user for the operations
	int input = -1;
	while (input != 5) {
		printf("1) insert data\n2) delete data\n3) delete at element\n4) display list\n5) search element\n6) quit\n>");
		scanf("%d", &input);
		
		if (input == 1) {
			int data = 0;
			printf("enter a number to insert: ");
			scanf("%d", &data);
			insertData(data);
		}
		if (input == 2) {
			deleteData();
		}
		if (input == 3) {
			int index = 0;
			printf("enter an index to delete: ");
			scanf("%d", &index);
			deleteDataAtElement(index);
		}
		if (input == 4) {
			displayList();
		}
		if (input == 5) {
			int index = 0;
			printf("enter an index to search: ");
			scanf("%d", &index);
			searchForIndex(index);
		}
		if (input == 6) {
			break;
		}
	}

	return 0;
}
