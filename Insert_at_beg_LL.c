#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    
};
void Traverse(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node *insertAtFront(struct Node *head, int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));;
    newNode->data=x;
    newNode->next =head;
    return newNode;
}
int main(){
    struct Node *head=NULL,*temp=NULL,*newNode=NULL,*tail=NULL;
    int i,value,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       scanf("%d",&value);
       newNode=(struct Node*)malloc(sizeof(struct Node));
       newNode->data=value;
       newNode->next=NULL;
       if(head==NULL){
             head=newNode;
             temp=head;
       }
       else{
           temp->next=newNode;
           temp=temp->next;
       }

    }
    printf("Traverse List : \n");
    Traverse(head);
    printf("Which element do you want to add at the beg:  \n");
    int x;
    scanf("%d",&x);
    head = insertAtFront(head, x);
    printf("Traverse List : \n");
    Traverse(head);
    printf("How many element you want do add beg : \n");
    int elm;
    scanf("%d",&elm);
    for(int i=0;i<elm;i++){
        int z;
        scanf("%d",&z);
        head = insertAtFront(head, z);
    }
    printf("Traverse List : \n");
    Traverse(head);


    return 0;

}