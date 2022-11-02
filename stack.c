#include <stdio.h>
#define max_size 8
int stack[max_size], top, choice;
void push(){
    int element;
    if (top >= max_size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter the element to be pushed in the stack: ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
    }
}
void pop(){
    if (top <= -1)
    {
        printf(" Stack under flow\n");
    }
    else
    {
        printf(" The popped elements is %d\n", stack[top]);
        top--;
    }
}

void display(){
    if (top >= 0)
    {
        printf("\n The elements in stack are \n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
    else
    {
        printf(" The Stack is empty \n");
    }
}
void main(){
    top = -1;
    printf("1.To push elements \n");
    printf("2.To pop elements \n");
    printf("3.To display stack \n");
    printf("4.To exit \n");
    do
    {
        printf("Enter your choice(1-4):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("Exit from stack");
            break;
        }
        default:
        {
            printf("Invalid choice");
            break;
        }
        }
    } while (choice != 4);
}
