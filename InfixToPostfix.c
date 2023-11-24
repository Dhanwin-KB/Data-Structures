#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
char stack[SIZE];
int top = -1;
void push(char value) 
{
    if (top == SIZE - 1) 
    {
        printf("\nStack is Full! Insertion is not possible!");
    } 
    else 
    {
        top++;
        stack[top] = value;
        printf("\nInsertion Success!");
    }
}
char pop() 
{
    if (top == -1) 
    {
        printf("\nStack is Empty! Deletion is not possible");
        return '\0';
    } 
    else 
    {
        char popped = stack[top];
        top--;
        return popped;
    }
}
void display() 
{
    if (top == -1) 
    {
        printf("\nStack is empty!");
    } 
    else 
    {
        printf("\nStack elements are: ");
        for (int i = 0; i <= top; i++) 
        {
            printf("%c ", stack[i]);
        }
    }
}
int chkPrecedence(char op) 
{
    switch (op) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void convert(char input[], char output[]) 
{
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) 
    {
        char letter = input[i];
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) 
        {
            output[j++] = letter;
        } 
        else if (letter == '(') 
        {
            push(letter);
        } 
        else if (letter == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                output[j++] = pop();
            }
            if (top != -1) 
            {
                pop();
            }
        } 
        else 
        {
            while (top != -1 && chkPrecedence(stack[top]) >= chkPrecedence(letter)) 
            {
                output[j++] = pop();
            }
            push(letter);
        }
    }
    while (top != -1) 
    {
        output[j++] = pop();
    }
    output[j] = '\0';
}
int main() 
{
    char input[SIZE], output[SIZE];
    printf("\n\n***** INFIX TO POSTFIX *****\n\n");
    printf("\nEnter Expression : ");
    scanf("%s", input);
    convert(input, output);
    printf("\nPostfix Expression : %s\n", output);
    return 0;
}
