#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // for sin() function

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

// Function to find maximum value
int findMax(struct Node *head) {
    int max = head->data;
    struct Node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data > max)
            max = ptr->data;
        ptr = ptr->next;
    }
    return max;
}

// Function to find minimum value
int findMin(struct Node *head) {
    int min = head->data;
    struct Node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data < min)
            min = ptr->data;
        ptr = ptr->next;
    }
    return min;
}

// Function to find total sum
int findSum(struct Node *head) {
    int sum = 0;
    struct Node *ptr = head;
    while (ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

// Function to calculate and display sine value of each node
void showSinValues(struct Node *head) {
    struct Node *ptr = head;
    printf("Sine values of each element:\n");
    while (ptr != NULL) {
        double radians = ptr->data * M_PI / 180.0; // convert degree to radian
        printf("sin(%d°) = %.4f\n", ptr->data, sin(radians));
        ptr = ptr->next;
    }
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int i, value;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    traverse(head);

    int max = findMax(head);
    int min = findMin(head);
    int total = findSum(head);
    double avg = total / 5.0;  // average = total / number of elements

    printf("\nMaximum Value: %d\n", max);
    printf("Minimum Value: %d\n", min);
    printf("Total Value (Sum): %d\n", total);
    printf("Average Value: %.2f\n", avg);

    showSinValues(head);

    return 0;
}
