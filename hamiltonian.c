#include<stdio.h>
#include<stdbool.h>
#define MAX 20
void next(int g[MAX][MAX],int k,int n)
{
	int i;
	while(true)
	{
		z[k]=(z[k]+1)%(m+1);
		if(z[k]==0)
			return;			
		if (g[z[k-1]][x[k]]!=0)
		{
			for(i=1;i<=k-1;i++)
			{
				if(z[i]==z[k])
				break;
			}
		}
	}
}
void hamiltonian(int g[MAX][MAX],int k,int n)
{
	while(true)
	{
		next(g,k);		
		if(z[k]==0)
			return;
		if(k==n)
		{
			write(n);
		}
		else
		{
			hamiltonian(g,k+1,n);
		}
	}
}
main()
{
	int i,j;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j=n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("\nThe adjacency matrix\n")
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
		}
		prinrf("\n");
	}
	hamiltonian(g,1,n);
}
