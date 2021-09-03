#include<stdio.h>
#include<stdbool.h>
#define MAX 100
int n;
int min(int key[],bool vi[])
{ 
    int min=999,min_index;
    int v;
    for(v=0;v<n;v++) 
	{ 
        if (vi[v]==false && key[v] < min) 
		{ 
        	min = key[v];
			min_index = v;  
        }
    }
    return min_index;  
}    
int print(int parent[MAX], int cost[MAX][MAX], int n)
{  
    int minCost=0;
	printf("Edge \tWeight\n"); 	
	int i; 
    for (i = 1; i< n; i++) 
	{
		printf("%d-%d\t%d\n",parent[i]+1,i+1,cost[i][parent[i]]);  
		minCost+=cost[i][parent[i]];
    }
    
	printf("Total cost is: %d",minCost);
}
void prims(int cost[MAX][MAX], int n)
{
	int i, k, u;
	int parent[n], key[n];
    bool vi[n];   
	for(i=0;i<n;i++)
	{
		parent[i]=-1;
		key[i]=999;
		vi[i]=false;	
	}	
	key[0]=0;
	parent[0]=-1;
	for(k=0;k<n-1;k++)
	{
		u=min(key,vi);
		vi[u]=true;
		int v;
		for(v=0;v<n;v++)
		{
			if(cost[u][v]!=0 && vi[v] == false && cost[u][v] < key[v])
			{
				parent[v]=u;
				key[v]=cost[u][v];
			}
		}
	}
	print(parent,cost,n);
}
main()
{
	printf("\nEnter number of vertices\n");
	scanf("%d",&n);	
	int i,j,cost[MAX][MAX];	
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{			
				printf("from %d to %d   ",i+1,j+1);
				scanf("%d",&cost[i][j]);
		}
	}
	printf("\nThe Adjacency matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{			
				printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
	prims(cost,n);
}
