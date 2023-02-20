#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *front=NULL,*rear=NULL;
struct node* create(int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL){
        printf("memory insufficient");
        exit(0);
    }
    new->data=data;
    new->next=NULL;
    return (new);
}
void enqueueatR(int data){
    struct node *new,*temp;
    new=create(data);
    if(rear==NULL){
        front=new;
        rear=new;
    }
    else {
        rear->next=new;
        rear=new;
    }
}
void dequeueatf(){
    if(front==NULL){
        printf("cannot delete node");
    }
    else{
        printf("popped element %d",front->data);
        struct node*temp=front;
        front=front->next;
        free(temp);
        if(front==NULL){
            rear=NULL;
        }
    }
}
void display(){
    struct node *ptr;
    if(front==NULL){
        printf("no elements");
    }
    else{
        ptr=front;
        while(ptr!=rear){
            printf("%3d",ptr->data);
            ptr=ptr->next;
        }
        printf("%3d",ptr->data);
    }
}
void main(){
    int ch;int data;
    printf("1.push\n2.pop\n3.display\n");
    do{
        printf("enter ur choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("ENTER DATA: ");
            scanf("%d",&data);
            enqueueatR(data);
            break;
            case 2:dequeueatf();
            printf("\n");
            break;
            case 3:printf("elements are:\n");
            display();
            printf("\n");
            break;
            default:break;
        }
    }while(ch<4);
}
