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

struct Node *Delete_str(struct Node *head, char s[100])
{
    struct Node *ptr = head;
    struct Node *pvr = NULL;
    while (ptr != NULL)
    {
        if (strcmp(ptr->data, s) == 0)
        {
            if (pvr == NULL)
            {
                head = ptr->next;
            }
            else
            {
                pvr->next = ptr->next;
            }
            return head;
        }
        pvr = ptr;
        ptr = ptr->next;
    }
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

    printf("Enter a string to delete:\n");
    scanf("%s", str);
    head = Delete_str(head, str);

    printf("After deletation:\n");
    Traverse(head);

    return 0;
}
