#include<stdio.h>
#include<stdlib.h>                    
struct node{
    int coeff;
    int exp;
    struct node*next;
};
struct node*head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*head5=NULL;
struct node* create(int coeff,int exp){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL){
        printf("memory insufficient");
    }
    new->coeff=coeff;
    new->exp=exp;
    new->next=NULL;
    return (new);
}
struct node *ptr;
struct node *insert(int coeff,int exp,struct node*head){
    struct node* new=create(coeff,exp);
    
    if(head==NULL){
        head=new;
        ptr=head;
    }
    else{  
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new;
        ptr=ptr->next;
        new->next=NULL;
    }     
    return head;
}
struct node* polynomial(int n,struct node *head){
    int c,e;
    struct node*temp=head;
    for(int i=0;i<n;i++){
        printf("coeff:");
        scanf("%d",&c);
        printf("exp:");
        scanf("%d",&e);
        head=insert(c,e,head);
    }
    return head;
}
struct node *polyadd(struct node*head1,struct node*head2,struct node*head3){
    struct node*ptr1=head1;
    struct node *ptr2=head2;
    struct node*ptr3=head3;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exp==ptr2->exp){
            int coeff=ptr1->coeff+ptr2->coeff;
            head3=insert(coeff,ptr1->exp,head3);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp>ptr2->exp){
            head3=insert(ptr1->coeff,ptr1->exp,head3);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp<ptr2->exp){
            head3=insert(ptr2->coeff,ptr2->exp,head3);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        head3=insert(ptr1->coeff,ptr1->exp,head3);
        ptr1=ptr1->next;
    }while(ptr2!=NULL){
        head3=insert(ptr2->coeff,ptr2->exp,head3);
        ptr2=ptr2->next;
    }
    return head3;
} 
struct node *multiply(){
    struct node*ptr1=head1;
    struct node *ptr2=head2;
    struct node*ptr4=head4;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            int coeff,exp;
            coeff=ptr1->coeff*ptr2->coeff;
            exp=ptr1->exp+ptr2->exp;
            head4=insert(coeff,exp,head4);
            ptr2=ptr2->next;
        }
        ptr2=head2;
        ptr1=ptr1->next;
    }
    return head4;
}
void display(struct node *head){
    ptr=head;
    while(ptr->next!=NULL){
     printf("%dx^%d + ",ptr->coeff,ptr->exp);
        ptr=ptr->next;
    }
    printf("%dx^%d\n",ptr->coeff,ptr->exp);  
}
struct node*subtract(){
    struct node*ptr1=head1;
    struct node*ptr2=head2;
    struct node*ptr5=head5;
    while(ptr1!=NULL && ptr2!=NULL){
       if(ptr1->exp==ptr2->exp){
            int coeff=ptr1->coeff-ptr2->coeff;
            head5=insert(coeff,ptr1->exp,head5);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp>ptr2->exp){
            head5=insert(ptr1->coeff,ptr1->exp,head5);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp<ptr2->exp){
            head5=insert(-ptr2->coeff,ptr2->exp,head5);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        head5=insert(ptr1->coeff,ptr1->exp,head5);
        ptr1=ptr1->next;
    }while(ptr2!=NULL){
        head5=insert(-ptr2->coeff,ptr2->exp,head5);
        ptr2=ptr2->next;
    }
    return head5;
}
void main(){
    int n1,n2;
    struct node*ptr1;
    printf("enter the number of terms in poly1");
    scanf("%d",&n1);
    head1=polynomial(n1,head1);
    printf("enter the number of terms in poly2");
    scanf("%d",&n2);
    head2=polynomial(n2,head2);
    printf("polynomial 1: ");
    display(head1);
    printf("polynomial 2: ");
    display(head2);
    printf("polynomial addition: ");
    head3=polyadd(head1,head2,head3);
    display(head3);    
    printf("poly multiplication: ");
    head4=multiply(head4);
    display(head4);
    printf("poly subtraction: ");
    head5=subtract(); 
    display(head5);   
}     
