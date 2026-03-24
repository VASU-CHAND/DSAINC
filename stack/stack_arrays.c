#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
void empty(struct stack* ptr){
    if(ptr->top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
        return ;
    }
    }
void full(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        printf("stack is full\n");
    }
    else{
        printf("stack is not full\n");
        return ;
    }
}
void push(struct stack* ptr,int val){
if(ptr->top==ptr->size-1){
    printf("stack is full\n");
    return;
}
ptr->top++;
ptr->arr[ptr->top]=val;

}
void pop(struct stack* ptr){
    if(ptr->top==-1){
        printf("stack is empty\n");
        return;
    }
    ptr->top--;

}
void display(struct stack* ptr){
    if(ptr->top==-1){
        printf("stack is empty\n");
        return;
    }
    else{
        for(int i=ptr->top;i>=0;i--){
            printf("%d\n",ptr->arr[i]);
    }
}
}
    

int main(){
   struct stack *s=(struct stack*)malloc(sizeof(struct stack));
   s->size=10;
   s->top=-1;
   s->arr=(int*)malloc(s->size*sizeof(int));
   // as integer store kar rahe hain
  push(s,12);
  push(s,13);
  push(s,20);
  push(s,45);
  display(s);
  pop(s);
  pop(s);
  printf(" \n");
  display(s);
  return 0;

}