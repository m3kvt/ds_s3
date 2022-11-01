#include <stdio.h>
#define max_terms 101
typedef struct
{
    int row;
    int col;
    int value;
} matrix;

void fast_transpose(matrix a[], matrix b[], int size)
{
    int row_terms[max_terms];
    int starting_pos[max_terms];
    int num_cols = a[0].col, num_terms = a[0].value;
    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if (num_terms > 0)
    {
        for (int i = 0; i < num_cols; i++)
            row_terms[i] = 0;
        for (int i = 1; i <= num_terms; i++)
            row_terms[a[i].col]++;
        starting_pos[0] = 1;
        for (int i = 1; i < num_cols; i++)
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
        for (int i = 1; i <= num_terms; i++)
        {
            int j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
    printf("Transpose of sparse matrix representation\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }
}

int main()
{
    int size;
    printf("Enter the number of non zero elements: ");
    scanf("%d", &size);

    matrix m[30], t_m[30];
    m[0].value = size;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m[0].row, &m[0].col);

    printf("Enter the sparse matrix representation: ");
    for (int i = 1; i <= size; i++)
    {
        scanf("%d %d %d", &m[i].row, &m[i].col, &m[i].value);
    }

    printf("Sparse matrix representation\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%d %d %d\n", m[i].row, m[i].col, m[i].value);
    }
    
    fast_transpose(m, t_m, size);
}
