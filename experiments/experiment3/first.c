#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    
    if(top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = x;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
}

int main()
{
   push(12);
   printf( "%d\n" ,stack[0]);
   push(13);
push(20);
push(45);
      display();
    pop();
    pop();
    display();
    return 0;
}
