#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char string[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", string);

    for(i = 0; i < strlen(string); i++)
    {
        push(string[i]);
    }

    for(i = 0; i < strlen(string); i++)
    {
        string[i] = pop();
    }

    printf("Reversed String = %s", string);

    return 0;
}