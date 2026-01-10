#include <stdio.h>
#include <ctype.h>

#define MAX 50

/* Stack structure */
struct Stack {
    int data[MAX];
    int top;
};

/* Initialize stack */
void initStack(struct Stack *s) {
    s->top = -1;
}

/* Push operation */
void push(struct Stack *s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = x;
}

/* Pop operation */
int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int main() {
    struct Stack S;
    char P[MAX];
    int i;
    int A, B, VALUE;

    initStack(&S);

    printf("Enter postfix expression ending with ): ");
    scanf("%s", P);

    /* Scan postfix expression */
    for (i = 0; P[i] != ')'; i++) {

        /* If operand */
        if (isdigit(P[i])) {
            push(&S, P[i] - '0');
        }

        /* If operator */
        else {
            A = pop(&S);
            B = pop(&S);

            switch (P[i]) {
                case '+': push(&S, B + A); break;
                case '-': push(&S, B - A); break;
                case '*': push(&S, B * A); break;
                case '/': push(&S, B / A); break;
            }
        }
        for (int i = S.top; i >= 0; i--){
        printf("%d ", S.data[i]);
        }
        printf("\n");

    }

    VALUE = pop(&S);

    printf("VALUE = %d\n", VALUE);

    return 0;
}

/*
1. struct Stack S;        → stack created
2. initStack(&S);        → stack initialized
3. push(&S, x);          → stack used
4. pop(&S);              → stack modified
*/
