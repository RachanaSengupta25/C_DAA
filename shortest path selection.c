#include<stdio.h>
main()
{
	int n,i,j,k,p,q,r,c;
	printf("Enter the number of vertices");
	scanf("%d",&n);
	int a[n][n];
	printf("\nEnter the cost\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d to %d",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Original matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				p=a[i][j];
				q=a[i][k]+a[k][j];
				if(p==q)
				a[i][j]=p;
				if(p<q)
				a[i][j]=p;
				if(p>q)
				a[i][j]=q;
			}
		}
		printf("\nPrinting matrix%d\n",k+1);
		for(r=0;r<n;r++)
		{
			for(c=0;c<n;c++)
			{
				printf("%d\t",a[r][c]);
			}
			printf("\n");
		}
	}
}
