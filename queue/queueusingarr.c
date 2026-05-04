#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct queue* ptr){
    if(ptr->front==ptr->rear){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue* ptr){
    if(ptr->rear==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue* ptr,int val){
    if(isFull(ptr)){
        printf("queue is full\n");
        return;
    }
    ptr->rear++;
    ptr->arr[ptr->rear]=val;
}
int dequeue(struct queue* ptr){
    if(isEmpty(ptr)){
        printf("queue is empty\n");
        return -1;
    }
    ptr->front++;
}