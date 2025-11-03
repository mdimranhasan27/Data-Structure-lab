#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node *next;
};

void Traverse(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void sortList(struct Node *head) {
    struct Node *i, *j;
    char temp[100];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->data, j->data) > 0) {
                strcpy(temp, i->data);
                strcpy(i->data, j->data);
                strcpy(j->data, temp);
            }
        }
    }
}

int main() {
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;
    int i,n;
    char value[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",value);
        newNode=(struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->data,value);
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }

    }
    printf("Before sorting:\n");
    Traverse(head);

    sortList(head);
    
    printf("After sorting:\n");
    Traverse(head);

    return 0;
}
