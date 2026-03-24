#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void linkedlisttraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
// to insert element at the first
struct Node* insertatfirst(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return head;
}
    // to inset in between 
    struct Node* insertinbw(struct Node*head,int data,int index){
        struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
        struct Node*p=head;
        int i=0;
        while(i!=index-1){
            p=p->next;
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        return head;

        }
        

}
// insert in end
struct Node* insertatend(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
p->next=ptr;
ptr->next=NULL;
return head;
}
// insert after a node

int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;
    // allocate memory for nodes linked list in heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    // linking first and second nodes
    head->data=7;
    head->next=second;
    // linking second and third nodes
    second->data=11;
    second->next=third;
    // terminate the list at the third node
    third->data=66;
    third->next=NULL;
   linkedlisttraversal(head);
    head=insertatfirst(head , 21);
    printf(" \n");
    linkedlisttraversal(head);
    return 0;
}
