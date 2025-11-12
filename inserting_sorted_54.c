#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data[100];
    struct Node *next;
};
void Traverse(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%s ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node *add_faruk(struct Node *head,){
    struct Node *ptr=head;
    while(ptr!=NULL){
        if(ptr->data>)
    }

}

int main(){
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;
    int i,n;
    scanf("%d",&n);
    char str[100];
    for(int i=0;i<n;i++){
        scanf("%s",str);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        strcpy(newNode->data, str);
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
    printf("Traverse list: \n");
    Traverse(head);

    return 0;
}