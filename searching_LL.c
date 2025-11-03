#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void search(struct Node *head,int target){
    struct Node *ptr = head ;
    int cnt=0,f=0;
    while(ptr!=NULL){
        cnt++;
        if(ptr->data==target) 
        {
            f=1;
            printf("%d is in the list at position %d. \n",target,cnt);
            break;
        }
        ptr=ptr->next;
    }
    if(f==0)printf("%d is not in the list at any position .\n ",target);
}
void Traverse(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
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
    printf("Traverse List :\n");
    Traverse(head);
    printf("which element do you want to search :\n");
    int x;
    scanf("%d",&x);
    search(head,x);


    return 0;
}