#include<stdio.h>
#define MAX 10
int Stack[MAX];
int top=-1;
void push(int item){
    if(top==MAX-1){
        printf("Overflow");
        return;
    }
    Stack[++top];
}
void pop(){
    if(top==-1){
        printf("Undeflow");
        return -1;
    }
    Stack[top--];
}

int main(){
    return 0;
}