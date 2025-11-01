#include <stdio.h>
#define MAX 5
void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main()
{
    int stack[MAX];
    int top = -1;
    int choice;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, &top, MAX);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            peek(stack, top);
            break;
        case 4:
            display(stack, top);
            break;
        case 5:
            printf("Exiting program..\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void push(int stack[], int *top, int maxSize)
{
    int value;
    if (*top == maxSize - 1)
    {
        printf("stack overflow !! cannot add more element");
    }
    else
    {
        printf("enter value to push:");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("%d is pushed into stack", value);
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("stack is underflow !! no element to pop");
    }
    else
    {
        printf("popped element is: %d", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("stack is empty!!");
    }
    else
    {
        printf("top element is %d", stack[top]);
    }
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("stack is empty!!");
    }
    else
    {
        printf("stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}
