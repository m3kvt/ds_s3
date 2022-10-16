#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} spm;

int main()
{ 
    spm sparse_matrix[100];
    int m, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[20][20];
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int non_zero = 0;
    sparse_matrix[0].row = m;
    sparse_matrix[0].col = n;
    int z = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                non_zero++;
                sparse_matrix[z].row = i;
                sparse_matrix[z].col = j;
                sparse_matrix[z].value = matrix[i][j];
                z++;
            }
        }
    sparse_matrix[0].value = non_zero;
    int i=0,j=0;
    for(i=0;i<=non_zero;i++)
    {
        printf("%d %d %d ",sparse_matrix[i].row,sparse_matrix[i].col,sparse_matrix[i].value);
        printf("\n");
    }
    
    float sparsity = (float)(non_zero)/(m*n);
    printf("Sparsity = %0.3f\n", sparsity);


}
