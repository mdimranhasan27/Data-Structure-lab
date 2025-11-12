#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

void Traverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *add_faruk(struct Node *head, int s)
{
    struct Node *ptr = head;
    struct Node *pvr = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = s;
    newNode->next = NULL;

    while (ptr != NULL)
    {
        if (ptr->data > s)
        {
            if (pvr == NULL)
            { 
                newNode->next = head;
                head = newNode;
            }
            else
            { 
                pvr->next = newNode;
                newNode->next = ptr;
            }
            return head;
        }
        pvr = ptr;
        ptr = ptr->next;
    }
    if (pvr == NULL)
        head = newNode;
    else
        pvr->next = newNode;

    return head;
}

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n;
    scanf("%d", &n);
    int str;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &str);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = str;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    printf("Original list:\n");
    Traverse(head);

    printf("Enter a number to insert:\n");
    scanf("%d", &str);
    head = add_faruk(head, str);

    printf("After insertion:\n");
    Traverse(head);
    printf("How many element do you want to add :\n");
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &str);
        head = add_faruk(head, str);
    }
    printf("After inserting %d element .\n", f);
    Traverse(head);

    return 0;
}
