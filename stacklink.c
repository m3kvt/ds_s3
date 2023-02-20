#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*top=NULL;
void push(int data){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    if (new==NULL){
        printf("memory insufficient");
    }
    new->data=data;
    new->next=NULL;
    struct node *ptr=top;
    if(ptr==NULL){
        top=new;
    }
    else{
        new->next=top;
        top=new;
    }
}
void pop(){
    struct node*ptr=top;
    printf("popped item is %d\n",ptr->data);
    ptr=ptr->next;
    top=ptr;
}
void display(){
    struct node *ptr=top;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    } 
}
void main(){
    int data;
    scanf("%d",&data);
    push(data);
    scanf("%d",&data);
    push(data);
    scanf("%d",&data);
    push(data);
    pop();
    display();
}
