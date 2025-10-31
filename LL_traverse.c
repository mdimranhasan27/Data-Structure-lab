#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data ;
	struct Node *next;
};

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

int main()
{ 
	struct Node *head = NULL,*temp = NULL,*newNode = NULL;
	printf("Enter element number : ");
	int element;
	scanf("%d",&element);
	int value;
	for(int i = 0; i < element; i++){
		scanf("%d",&value);
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = value;
		newNode->next = NULL;

		if(head==NULL){
			head = newNode;
			temp = head;
		}
		else{
			temp->next = newNode;
			temp = temp->next;
		}
	}
	Traverse(head);

	
	return 0;
}