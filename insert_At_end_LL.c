#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *insert_at_end(struct Node *head,int x){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    head->next=newNode;
    return newNode;
}
void Traverse(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}




int main(){
     struct Node *head =NULL, *Temp=NULL,*newNode = NULL,*Tail=NULL;
     int i,n,value;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
        scanf("%d",&value);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            Temp=head;
        }
        else{
            Temp->next=newNode;
            Temp= Temp->next;
        }
        Tail=newNode;
     }
     printf("which element you want to add end : \n");
     int z;
     scanf("%d",&z);
     Tail = insert_at_end(Tail, z);
     printf("Traverse List :\n");
     Traverse(head);
     printf("\n");
     printf("How many element you want to add end: \n");
     int element ;
     scanf("%d",&element);
     for(int i=0;i<element;i++){
        int g;
        scanf("%d",&g);
        Tail = insert_at_end(Tail, g);
     }
     printf("\n");
     printf("Traverse List :\n");
     Traverse(head);
     


    return 0;
}