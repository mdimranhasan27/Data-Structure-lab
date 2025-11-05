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

struct Node *add_number(struct Node *head, int s)
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

struct Node *add_number_pos(struct Node *head, int number, int pos)
{
    struct Node *ptr = head;
    struct Node *pvr = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        if (pos == cnt)
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
    head = add_number(head, str);

    printf("After insertion:\n");
    Traverse(head);
    printf("Give me number and position : \n");
    int f, number;
    scanf("%d%d", &number, &f);
    head = add_number_pos(head, number, f);
    printf("After insertion:\n");
    Traverse(head);

    return 0;
}
