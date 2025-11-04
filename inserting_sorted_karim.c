#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[100];
    struct Node *next;
};

void Traverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *add_faruk(struct Node *head, char s[100])
{
    struct Node *ptr = head;
    struct Node *pvr = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, s);
    newNode->next = NULL;

    while (ptr != NULL)
    {
        if (strcmp(ptr->data, s) > 0)
        {
            if (pvr == NULL)
            { // insert at head
                newNode->next = head;
                head = newNode;
            }
            else
            { // insert between pvr and ptr
                pvr->next = newNode;
                newNode->next = ptr;
            }
            return head;
        }
        pvr = ptr;
        ptr = ptr->next;
    }
    // insert at end if not inserted yet
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
    char str[100];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->data, str);
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

    printf("Enter a string to insert:\n");
    scanf("%s", str);
    head = add_faruk(head, str);

    printf("After insertion:\n");
    Traverse(head);

    return 0;
}
