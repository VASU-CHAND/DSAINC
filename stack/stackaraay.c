#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Overflow\n");
    else {
        stack[++top] = x;
    }
}

int pop() {
    int m=stack[top];
    if (top == -1)
        printf("Underflow\n");
    else
         top--;
         printf("Popped: %d\n", m);
        return m;
       
}

void peek() {
    if (top != -1)
        printf("Top: %d\n", stack[top]);
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    peek();

    return 0;
}