#include <stdio.h>
#define MAX 10

int Stack[MAX];
int top = -1;
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow...");
        return;
    }
    top++;
    Stack[top] = item;
    
}
int main()
{
    push(5);
    push(10);
    push(8);

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", Stack[i]);

    return 0;
}