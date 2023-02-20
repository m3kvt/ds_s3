#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
struct node *create(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("insufficient memory");
    }
    else
    {
        new->data = data;
        new->right = NULL;
        new->left = NULL;
    }
    return new;
}
// insertion
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = create(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
// searching
struct node *search(struct node *root, int data)
{
    if (root == NULL || data == root->data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else if (data > root->data)
    {
        return search(root->right, data);
    }
}
// traversals
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {

        printf("%3d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->data);
    }
}
// findmin
struct node *findmin(struct node *root)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->left != NULL)
    {
        return root->left = findmin(root->left);
    }
    else
    {
        return root;
    }
}

// deleting
struct node *delete(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data > data)
    {
        root->left = delete (root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        // NO CHILD
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // 1 CHILD
        else if (root->left == NULL || root->right == NULL)
        {
            struct node *temp;
            if (root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            root = temp;
            free(temp);
            return root;
        }
        else
        {
            struct node *temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}
void main()
{
    int data, ch;
    printf("enter the root data: ");
    scanf("%d", &data);
    root = create(data);
    do
    {
        printf("enter ur choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter data to be inserted: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        default:
            printf("invalid");
            break;
        case 3:
            printf("%d", root->data);
            break;
        case 4:
            printf("enter the data to be searched: ");
            scanf("%d", &data);
            struct node *ptr = search(root, data);
            if (ptr == NULL)
            {
                printf("not found\n");
            }
            else
            {
                printf("found\n");
            }
            break;
        case 5:
            preorder(root);
            printf("\n");
            break;
        case 6:
            postorder(root);
            printf("\n");
            break;
        case 7:
            printf("enter the data to be deleted: ");
            scanf("%d", &data);
            root = delete (root, data);
            break;
        }
    } while (ch != 0);
}
