#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *tail;
int length = 0;
struct node *create(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("memory insufficient");
    }
    else
    {
        new->data = data;
        new->next = NULL;
    }
}
void insertf(int data)
{
    struct node *new = create(data);
    if (tail == NULL)
    {
        tail = new;
        tail->next = new;
    }
    else
    {
        new->next = tail->next;
        tail->next = new;
    }
    length++;
}
void inserte(int data)
{
    struct node *new = create(data);
    if (tail == NULL)
    {
        tail = new;
        tail->next = new;
    }
    else
    {
        new->next = tail->next;
        tail->next = new;
        tail = new;
    }
    length++;
}
void insertpos(int data)
{
    int pos, i = 1;
    printf("enter the position to be inserted");
    scanf("%d", &pos);
    if (pos < 0 || pos > length + 1)
    {
        printf("invalid");
    }
    else if (pos == 1)
    {
        insertf(data);
        length++;
    }
    else if (pos == length + 1)
    {
        inserte(data);
        length++;
    }
    else
    {
        struct node *new = create(data);
        struct node *ptr = tail->next;
        while (i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }
        new->next = ptr->next;
        ptr->next = new;
        length++;
    }
}
void deleteend()
{
    struct node *ptr;
    if (tail == NULL)
    {
        printf("cannot delete");
    }
    else
    {
        ptr = tail->next;
        while (ptr->next != tail)
        {
            ptr = ptr->next;
        }
        printf("popped element is %d", tail->data);
        ptr->next = tail->next;
        tail = ptr;
        length--;
    }
}
void deletef()
{
    struct node *temp;
    if (tail == NULL)
    {
        printf("no elements");
    }
    else
    {
        printf("popped element is %d", tail->next->data);
        tail->next = tail->next->next;
        length--;
    }
}

void deletepos()
{
    int pos;
    printf("enter the position to be deleted: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletef();
        length--;
    }
    else if (pos == length + 1)
    {
        deleteend();
        length--;
    }
    else if (pos < 0 || pos > length + 1)
    {
        printf("cannot delete");
    }
    else
    {
        struct node *ptr = tail->next;
        int i = 1;
        while (i < pos - 1)
        {
            ptr = ptr->next;
        }
        printf("the popped element is %d", ptr->next->data);
        ptr->next = ptr->next->next;
        length--;
    }
}
void display()
{
    struct node *ptr;
    if (tail == NULL)
    {
        printf("no elements");
    }
    else
    {
        ptr = tail->next;
        while (ptr != tail)
        {
            printf("%3d", ptr->data);
            ptr = ptr->next;
        }
        printf("%3d", ptr->data);
    }
}
void main()
{
    int data;
    int ch;
    printf("1.push at f\n2.push at e\n3.pop at f\n4.pop at e\n5.display\n");
    do
    {
        printf("enter ur choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("ENTER DATA: ");
            scanf("%d", &data);
            insertf(data);
            break;
        case 2:
            printf("ENTER DATA: ");
            scanf("%d", &data);
            inserte(data);
            break;
        case 3:
            deletef();
            printf("\n");
            break;
        case 4:
            deleteend();
            printf("\n");
            break;
        case 5:
            printf("elements are:\n");
            display();
            printf("\n");
            break;
        case 6:
            printf("ENTER DATA: ");
            scanf("%d", &data);
            insertpos(data);
            break;
        case 7:
            deletepos();
            printf("\n");
            break;
        default:
            break;
        }
    } while (ch < 8);
}
