//INCOMPLETE
#include<stdio.h>
#define max_size 50
int stack[max_size],aux_stack[max_size],top=-1;auxitop=-1;
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
void pop(){
	if (top <= -1)
    {
        printf(" Stack under flow\n");
    }
    else
    {
        printf(" The popped element is %d\n", stack[top]);
        top--;
    }
}
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
void minimum(){
	
}

void main(){
	
	do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.To change stack number\n");
        printf("5.To display the minimum element ")
        printf("\n6.To exit\n");        
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d",&element);
            push(stackno,element);
            break;
        case 2:
            pop(stackno);
            break;
        case 3:
            display(stackno);
            break;
        case 4:
        		minimum();
        		break;  
        case 5:
        		printf("\nExit from the stack\n");
        		break;
        default:
        		printf("\nInvalid choice\n");
        }
    } while(choice!=5);
}
