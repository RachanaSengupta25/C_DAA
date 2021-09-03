#include <stdio.h>
#include<stdbool.h>
int x[20],count=0,a[20][20],l=1;
bool v[20];
bool hamiltonian(int k,int n)
{
    v[k]=true;
    x[l]=k;
    l=l+1;   
    if(l==n+1)
	{
        if(a[1][x[n]]==1)
		{
		int i;
        printf("Cycle no. %d : ",++count);
        for(i=1;i<=n;i++)
		{
        printf("\t%d",x[i]);
        }
		printf("\t%d",1);
		printf("\n");
		}
        return false;
    }
    int j;    
    for(j=1;j<=n;j++)
	{
        if(a[k][j] && v[j]==false)
		{
            if(hamiltonian(j,n))
			{
                return true;
            }
            else
			{
            v[j]=false;
            x[l]=0;
            l--;
            }
        }
    }   
    return false;
}
main()
{
    int co=0,n,i,j;  
    printf("\nEnter the total number of vertex\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
		{
            printf("from %d to %d",i,j);
            scanf("%d",&a[i][j]);
        }
    }  
    printf("\nAdjacency matrix: \n");
    for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
		{
            printf("\t%d",a[i][j]);
        }
		printf("\n");
    }
	printf("\n");
  printf("\nSolution \n");
    hamiltonian(1,n);
  printf("\nTotal no of Cycles=%d",count);
}
