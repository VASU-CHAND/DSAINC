#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
int main(){
    struct Node*n1=(struct Node*)malloc(sizeof(struct Node));
 
    struct Node*n2=(struct Node*)malloc(sizeof(struct Node));
    
    n1->data=10;
    n1->next=n2;
    n2->data=20;
    n2->next=NULL;
    struct Node*temp=n1;
      while(temp!=NULL){
        printf("Element:%d\n",temp->data);
        temp=temp->next;
    }
    free(n1);
    free(n2);
    free(temp);
    return 0;

}
