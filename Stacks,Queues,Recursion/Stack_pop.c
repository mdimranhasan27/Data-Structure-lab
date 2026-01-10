#include <stdio.h>
#define MAX 10
int Stack[MAX];
int top = -1;
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Overflow ");
        return;
    }
    Stack[++top]=item;
}
int Pop()
{
    if (top == -1)
    {
        printf("Undeflow ");
        return -1;
    }
    return Stack[top--];
}

int main()
{
    push(10);
    push(12);
    push(14);
    push(16);
    push(18);

    printf("Pop Element : %d\n", Pop());
    printf("Pop Element : %d\n", Pop());
    printf("Pop Element : %d\n", Pop());
    printf("Pop Element : %d\n", Pop());
    printf("Pop Element : %d\n", Pop());
    printf("Pop Element : %d\n", Pop());

    

    return 0;
}