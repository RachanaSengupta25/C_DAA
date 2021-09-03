#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int z[MAX],c=0;
void write(int n)
{
	int i;
	c++;
	printf("Solution %d:\n",c);
	for(i=1;i<=n;i++)
	{
		printf("%d  ",z[i]);
	}
	printf("\n");
}
void Next(int g[MAX][MAX],int k,int m, int n)
{
	int i;
	while(true)
	{
		z[k]=(z[k]+1)%(m+1);
		if(z[k]==0)
			return;			
		for(i=1;i<=n;i++)
		{
			if((g[k][i]!=0) && (z[k]==z[i]))
				break;
		}
		if(i==n+1)
			return;
	}
}
void Colour(int g[MAX][MAX], int k, int m, int n)
{
	while(true)
	{
		Next(g,k,m,n);		
		if(z[k]==0)
			return;
		if(k==n)
		{
			write(n);
		}
		else
		{
			Colour(g,k+1,m,n);
		}
	}
}
main()
{
	int n,i,j,m,g[MAX][MAX];
	printf("\nEnter the no of vertices\n");
	scanf("%d",&n);
	printf("\nEnter the no of colours\n");
	scanf("%d",&m);	
	printf("\nEnter adjacency matrix\n");
   	for(i=1;i<=n;i++)
	   {
		for(j=1;j<=n;j++)
		{
				printf(" %d to %d:",i,j);
   				scanf("%d",&g[i][j]);
		}
	}
	printf("\nAdjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
   				printf("%d  ",g[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Colour(g,1,m,n);
	printf("Total no of solutions: %d",c);
}
