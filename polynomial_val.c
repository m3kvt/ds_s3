#include <stdio.h>
#include <math.h>

typedef struct
{
    int coeff;
    int expo;
} polynomial;

int main()
{
    int n, x, result = 0;
    polynomial p[20];
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        printf("Enter coefficient :");
        scanf("%d", &p[i].coeff);
        printf("Enter power :");
        scanf("%d", &p[i].expo);
    }
    printf("The polynomial is ");
    printf(" %dx^%d", p[0].coeff, p[0].expo);
    for (int i = 1; i <= n; i++)
        printf("+ %dx^%d", p[i].coeff, p[i].expo);
    printf("\n");
    printf("Enter a value of x: ");
    scanf("%d", &x);
    for (int i = 0; i <= n; i++)
        result += p[i].coeff * pow(x, p[i].expo);
    printf("Result of evaluvation = %d\n", result);

    return 0;
}
