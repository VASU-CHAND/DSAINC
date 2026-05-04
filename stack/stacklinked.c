#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};
// Top pointer
struct Node* top = NULL;
// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    
    printf("%d pushed to stack\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    
    struct Node* temp = top;
    printf("%d popped from stack\n", temp->data);
    
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Display stack
void display() {
    struct Node* temp = top;
    
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    
    peek();
    
    pop();
    display();
    
    return 0;
}