#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data[100];
    struct Node *next;
};
void search(struct Node *head,char target[100]){
    struct Node *ptr = head ;
    int cnt=0,f=0;
    while(ptr!=NULL){
        cnt++;
        if (strcmp(ptr->data,target) == 0) 
        {
            f=1;
            printf("%s is in the list at position %d . \n",target,cnt);
            break;
        }
        ptr=ptr->next;
    }
    if(f==0)printf("%s is not in the list at any position .\n ",target);
}
void Traverse(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main(){
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
    printf("Traverse List :\n");
    Traverse(head);
    printf("which element do you want to search :\n");
    char x[100];
    scanf("%s",x);
    search(head,x);


    return 0;
}