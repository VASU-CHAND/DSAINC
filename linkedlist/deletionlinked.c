#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
 struct Node*deletehead(struct Node*head){
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;

 }
 struct Node*deleteinend(struct Node*head){
 struct Node*p=head;
 struct Node*q=head->next;
 while(q->next!=NULL){
    p=p->next;
    q=q->next;
 }
 p=q->next;
 free(q);
 return head;
 }
 struct Node*deleteinbw(struct Node*head,int index){
    struct Node*p=head;
    struct Node*q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
   p->next=q->next;
    free(q);
 }
 deletecertainvalue(struct Node*head,int value){
   struct Node*p=head;
   struct Node*q=head->next;
 }
 
 void linkedlisttraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;

}
}
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
third ->data=66;
third->next=NULL;
deleteinbw(head,1);
linkedlisttraversal(head);

return 0;



}