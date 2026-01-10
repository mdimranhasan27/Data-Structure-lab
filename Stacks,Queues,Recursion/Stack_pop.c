#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int item) {
    if(top == MAX - 1) return;
    stack[++top] = item;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    push(5);
    push(15);
    push(25);

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    return 0;
}
