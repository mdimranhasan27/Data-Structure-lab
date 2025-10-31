#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct Node{
	int data ;
	struct Node *next;
};
void Maximum(struct Node *head){
	struct Node *ptr=head;
	int max=0;
	while(ptr!=NULL){
		if(ptr->data>max) max=ptr->data;
		ptr=ptr->next;
	}
	printf("\nMaximum value is :  %d",max);
}
void Minimum(struct Node *head){
	struct Node *ptr=head;
	int min=10000;
	while(ptr!=NULL){
		if(ptr->data<min) min=ptr->data;
		ptr=ptr->next;
	}
	printf("\nMaximum value is :  %d",min);
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
void Total_value(struct Node *head){
	struct Node *ptr=head;
	int sum=0;
	while(ptr!=NULL){
		sum+=ptr->data;
		ptr=ptr->next;

	}
	printf("\nThe total sum is :  %d",sum);
}
void Sin_value(struct Node *head){
	struct Node *ptr = head ;
	while(ptr!=NULL){
		printf("\nThe sin value of %d is : %f",ptr->data,(3.1416/180)*(ptr->data) );
		ptr = ptr->next;
	}
}
void Average_Value(struct Node *head){
	struct Node *ptr = head;
	int sum=0,cnt=0;
	while(ptr!=NULL){
		sum+=ptr->data;
		ptr=ptr->next;
		cnt++;
    }
	float average = sum/cnt;
	printf("\nThe average value is: %f",average);
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
	Maximum(head);
	Minimum(head);
	Total_value(head);
	Average_Value(head);
	Sin_value(head);


	

	
	return 0;
}