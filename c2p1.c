#include <stdio.h>

typedef struct
{
    int coeff;
    int expo;
} polynomial;

int main()
{
    int size1, size2;
    polynomial p1[20], p2[20], sum[40];
    printf("Enter the no. of terms of 1st polynomial: ");
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++){
        printf("Enter coefficient :");
        scanf("%d", &p1[i].coeff);
        printf("Enter power :");
        scanf("%d", &p1[i].expo);
    }
    printf("Enter the no. of terms of 2nd polynomial: ");
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++){
        printf("Enter coefficient :");
        scanf("%d", &p2[i].coeff);
        printf("Enter power :");
        scanf("%d", &p2[i].expo);
    }
    
    printf("\nPolynomial 1  = %dx^%d", p1[0].coeff,p1[0].expo);
    for (int i = 1; i < size1; i++)
        printf("+ %dx^%d", p1[i].coeff, p1[i].expo);
    printf("\nPolynomial 2  = %dx^%d", p2[0].coeff,p2[0].expo);
    for (int i = 1; i < size2; i++)
        printf("+%dx^%d ", p2[i].coeff, p2[i].expo);
    printf("\n");
    

    int i = 0, j = 0, z = 0;
    while (i < size1 && j < size2)
    {
        if (p1[i].expo > p2[j].expo)
        {
            sum[z].expo = p1[i].expo;
            sum[z].coeff = p1[i].coeff;
            i++;
            z++;
        }
        else if (p1[i].expo < p2[j].expo)
        {
            sum[z].expo = p2[j].expo;
            sum[z].coeff = p2[j].coeff;
            j++;
            z++;
        }
        else
        {
            sum[z].expo = p1[i].expo;
            sum[z].coeff = p1[i].coeff + p2[j].coeff;
            z++;
            i++;
            j++;
        }
    }
    while (i < size1)
    {
        sum[z].expo = p1[i].expo;
        sum[z].coeff = p1[i].coeff;
        i++;
        z++;
    }
    while (j < size2)
    {
        sum[z].expo = p2[j].expo;
        sum[z].coeff = p2[j].coeff;
        j++;
        z++;
    }
    printf("\nPolynomial expression after additon  = %dx^%d", sum[0].coeff,sum[0].expo);
    for (int i = 1; i < z; i++)
        printf("+ %dx^%d", sum[i].coeff, sum[i].expo);
    printf("\n");

    return 0;
}