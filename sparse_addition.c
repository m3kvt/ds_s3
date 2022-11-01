#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int value;
} spm;
void display(spm sparse[], int non_zero, int rows, int cols)
{
    
    for (int i = 1; i <= non_zero; i++)
    {
        printf("%3d%3d%3d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}
void create(spm sparse[], int non_zero, int rows, int cols)
{
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = non_zero;
    printf("Enter the elements:");
    for (int i = 1; i <= non_zero; i++)
    {
        scanf("%3d%3d%3d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
}
int main()
{
    int mat1[20][20], mat2[20][20], m, n, p, q, i, j, non_zero1, non_zero2;
    spm sparse1[50], sparse2[50], sum[100];
    // 1st matrix creation
    printf("For 1st sparse matrix representation:\n");
    printf("Enter the no of rows and columns:");
    scanf("%d%d", &m, &n);
    printf("Enter the no of non zero values:");
    scanf("%d", &non_zero1);
    create(sparse1, non_zero1, m, n);
    // 2nd matrix creation
    printf("For the 2nd sparse matrix representation:\n");
    printf("Enter the no of rows and columns:");
    scanf("%d%d", &p, &q);
    printf("Enter the no of non zero values:");
    scanf("%d", &non_zero2);
    create(sparse2, non_zero2, p, q);
    // 1st matrix display
    printf("The 1st sparse matrix representation is \n");
    printf("%3d%3d%3d\n", sparse1[0].row, sparse1[0].col, sparse1[0].value);
    display(sparse1, non_zero1, m, n);
    // 2nd matrix display
    printf("The 2nd sparse matrix representation is\n");
    printf("%3d%3d%3d\n", sparse2[0].row, sparse2[0].col, sparse2[0].value);
    display(sparse2, non_zero2, p, q);
    // sum
    if ((sparse1[0].row != sparse2[0].row) || (sparse1[0].col != sparse2[0].col))
    {
        printf("Incompatible matrix size");
    }

    else
    {
        int z = 1, x = 1, y = 1;
        for (int i = 0; i < sparse1[0].row; i++)
            for (int j = 0; j < sparse1[0].col; j++)
            {
                if (sparse1[x].row == i && sparse1[x].col == j && sparse2[y].row == i && sparse2[y].col == j)
                {
                    sum[z].row = i;
                    sum[z].col = j;
                    sum[z].value = sparse1[x].value + sparse2[y].value;
                    x++;
                    y++;
                    z++;
                }
                else if (sparse1[x].row == i && sparse1[x].col == j)
                {
                    sum[z].row = i;
                    sum[z].col = j;
                    sum[z].value = sparse1[x].value;
                    x++;
                    z++;
                }
                else if (sparse2[y].row == i && sparse2[y].col == j)
                {
                    sum[z].row = i;
                    sum[z].col = j;
                    sum[z].value = sparse2[y].value;
                    y++;
                    z++;
                }
            }
        sum[0].value = --z;
        printf("\nResultant sparse matrix representation after addition:\n");
        printf("%3d%3d%3d\n", sparse1[0].row, sparse1[0].col, z);
        display(sum, z, sum[0].row, sum[0].col);
    }
}
