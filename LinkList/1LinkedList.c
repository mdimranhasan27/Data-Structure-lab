#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the linked list
void traverse(struct Node *head) {
    struct Node *ptr = head;
    printf("Linked List elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int i, value;

    printf("Enter 5 integers:\n");

    // Create 5 nodes
    for (i = 0; i < 5; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        // For the first node
        if (head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Traverse the list
    traverse(head);

    return 0;
}
