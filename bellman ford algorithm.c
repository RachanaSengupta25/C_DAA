#include<stdio.h>
#include<conio.h>
#include<math.h>
BellmanFord(int p, int* A, int* c, int n){
    int i,j;
    for(i=0;i<n;i++)
	{
        *(c+(p+1)*n+i)=*(c+p*n+i);
        for(j=0;j<n;j++)
		{
            if(*(c+(p+1)*n+i)>*(c+p*n+j)+*(A+*(c+j)*n+*(c+i)))
                *(c+(p+1)*n+i)=*(c+p*n+j)+*(A+*(c+j)*n+*(c+i));
        }
    }
    if(p<n)
        BellmanFord(p+1,A,c,n);
}
main()
{
    int n,i,j,k,a;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    int A[n][n],B[n+2][n];
    printf("\nenter the value of Adjacency Matrix:\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("enter the value of A%d%d:",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nPrinting the adjacency Matrix:\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("\t%d",A[i][j]);
        }
    }
    printf("\nPlease enter the Source vertex number:");
    scanf("%d",&a);
    B[0][0]=a-1;
    B[1][0]=0;
    for(j=1;j<n;j++){
        if(j>a-1)
            B[0][j]=j;
        else
            B[0][j]=j-1;
    }
    for(j=1;j<n;j++)
        B[1][j]=999;
    BellmanFord(1,*A,*B,n);
    printf("\nThe Recursive Iterations are:");
    for(i=2;i<n+1;i++){
        printf("\n\n");
        for(j=0;j<n;j++){
            
            if(B[i][j]>900){
              printf("\tI\t");
      }
      else{
        printf("\t%d\t",B[i][j]);
      }
        } 
    }
    for(i=0;i<n;i++){
        if(B[n+1][i]!=B[n][i]){
            printf("\nThere is a negative edge-cycle in this graph");
            return 0;
        }
    }
    printf("\nThe answer is:\n");
    for(i=1;i<n;i++)
        printf("\nWeight of vertex no.%d is %d",B[0][i]+1,B[n+1][i]);
}
