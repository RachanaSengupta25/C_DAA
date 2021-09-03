#include<stdio.h>
main()
{
	int n,p,q,r,s,t,u,v,a[100][100],b[100][100],c[100][100],i,j;
	printf("\nEnter the elements of the first matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter the elements of the second matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    q= (a[1][0]+a[1][1])*b[0][0];
    r= a[0][0]*(b[0][1]-b[1][1]);
    s= a[1][1] * (b[1][0] - b[0][0]);
    t= (a[0][0] + a[0][1]) * b[1][1];
    u= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
    v= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
    c[0][0]=p+s-t+v;
    c[0][1]=r+t;
    c[1][0]=q+s;
    c[1][1]=p+r-q+u;
	 printf("\nFirst matrix is \n");
    for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}printf("\nSecond matrix is \n");
    for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\nAfter multiplication using Strassen's algorithm \n");
    for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}
