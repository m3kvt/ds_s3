//incomplete

#include <stdio.h>

typedef struct
{
   int row;
   int col;
   int value;
} spm;
int main(){
		int mat1[20][20],mat2[20][20],m,n,p,q,i,j,non_zero1,non_zero2;
		spm sparse1[50],sparse2[50];
		printf("Enter the 1st sparse matrix:\n");
		printf("Enter the no of rows and columns:");
		scanf("%d%d",&m,&n);
		printf("Enter the no of non zero values:");
		scanf("%d",&non_zero1);
		//create
		sparse1[0].row=m;
		sparse1[0].col=n;
		sparse1[0].value=non_zero1;
		printf("Enter the elements:");
		for(int i=1;i<=non_zero1;i++){
			scanf("%3d%3d%3d",&sparse1[i].row,&sparse1[i].col,&sparse1[i].value);
		}
		printf("Enter the 2nd sparse matrix:\n");
		printf("Enter the no of rows and columns:");
		scanf("%d%d",&p,&q);
		printf("Enter the no of non zero values:");
		scanf("%d",&non_zero2);
		//create
		sparse2[0].row=p;
		sparse2[0].col=q;
		sparse2[0].value=non_zero2;
		printf("Enter the elements:\n");
		for(int i=1;i<=non_zero2;i++){
			scanf("%3d%3d%3d",&sparse2[i].row,&sparse2[i].col,&sparse2[i].value);
		}
		//display
		printf("The 1st sparse matrix is \n");
		printf("%3d%3d%3d\n",sparse1[0].row,sparse1[0].col,sparse1[0].value);
		for(int i=1;i<=non_zero1;i++){
			printf("%3d%3d%3d\n",sparse1[i].row,sparse1[i].col,sparse1[i].value);
		}
		//display
		printf("The 2nd sparse matrix is\n");  
		printf("%3d%3d%3d\n",sparse2[0].row,sparse2[0].col,sparse2[0].value);
		for(int i=1;i<=non_zero2;i++){
			printf("%3d%3d%3d\n",sparse2[i].row,sparse2[i].col,sparse2[i].value);
		}		
}
