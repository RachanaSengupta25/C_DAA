#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
int n,adj[MAX][MAX],state[MAX],stack[MAX],top=-1; 
void push(int v)
{
        if(top==MAX-1)
        {
                printf("\nStack Overflow\n");
                return;
        }
        top=top+1;
        stack[top] = v;
}
void DFS(int v)
{
        int i;
        push(v);
        while(!Empty())
        {
                v = pop();
                if(state[v]==initial)
                {
                        printf("V%d ",v);
                        state[v]=visited;
                }
                for(i=n;i>=1;i--)
                {
                        if(adj[v][i]==1 && state[i]==initial)
                                push(i);
                }
        }
}
void DFSTraversal()
{
        int v;
        for(v=1; v<=n; v++)
        state[v]=initial;
        DFS(1);
        printf("\n");
}
int pop()
{
        int v;
        if(top == -1)
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        else
        {
                v = stack[top];
                top=top-1;
                return v;
        }
}
int Empty( )
{
  if(top == -1)
          return 1;
  else
          return 0;
}
main()
{
   int i,j;
   printf("Enter number of vertices : ");
   scanf("%d",&n);
   printf("\nEnter the adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
   	for(j=1;j<=n;j++)
   	{
   		printf("%d to %d ",i,j);
   		scanf("%d",&adj[i][j]);
	}
   }
   printf("\nADJACENCY MATRIX\n");
   for(i=1;i<=n;i++)
   {
   	for(j=1;j<=n;j++)
   	{
   		printf("%d  ",adj[i][j]);
	}
	printf("\n");
   }
DFSTraversal();
}  
