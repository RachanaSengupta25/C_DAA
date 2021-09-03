#include<stdio.h>
#define MAX 10
void breadthfirst(int a[][MAX],int v[],int start)
{
	int queue[MAX],rear=-1,front=-1,i;
	queue[++rear]=start;
	v[start]=1;
	while(rear!=front)
	{
		start=queue[++front];
		/*if(start==4)
		{
			printf("5\t");
		}
		else*/
		if(start!=5)
		
			printf("%c\t",start+65);
	
		for(i=0;i<5;i++)
		{
			if(a[start][i]==1 && v[i]==0)
			{
				queue[++rear]=i;
				v[i]=1;
			}
		}
	}
}
main()
{
	int visited[MAX]={0};
	int adj[MAX][MAX],i,j;
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	breadthfirst(adj,visited,0);
	
}
