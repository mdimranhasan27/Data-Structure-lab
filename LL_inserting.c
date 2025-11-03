#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void insert_sorted(struct Node **head,int target){
    struct Node *ptr= *head;
    struct Node *pvr=NULL;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=target;
    newNode->next=NULL;
    while(ptr!=NULL){
        if(ptr->data>=target) {
            newNode->next = ptr;
            pvr->next = newNode;
            break;
        }
        pvr=ptr;
        ptr=ptr->next;
}
    if(ptr==NULL){
        pvr->next=newNode;
        newNode->next=NULL;
    }
}
void Traverse(struct Node *head){
	printf("Traverse LinkList: \n");
	struct Node *ptr =head ;
	    if(ptr==NULL){
			printf("There is no element in the LL\n");
		}
		else {
	    while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->next;
    	}
	}
}
int main(){
    struct Node *head=NULL,*newNode=NULL,*temp=NULL;
    int i,value,n;
    printf("Enter the number of element : \n" );
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
    int target ;
    
    printf("\nwhich element do you want to insert a sorted array\n");
    scanf("%d",&target);
    insert_sorted(&head,target);
    Traverse(head);



    return 0;
}