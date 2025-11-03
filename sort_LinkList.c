#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void Traverse(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
int main(){
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;
    int i,value,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=value;
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
    printf("Traverse List before sorting:\n");
    Traverse(head);
    sortList(head);
    printf("\nTraverse List after sorting:\n");
    Traverse(head);

    return 0;
}