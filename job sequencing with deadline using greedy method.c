#include<stdio.h>
valid(int arr[],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]<=i) //invalid condition
		c++;
	}
	if(c>0)
	return 1;
	else
	return 2;
}
main()
{
	int n,t,i,j,max,s=0,e;
	printf("\nEnter the range");
	scanf("%d",&n);
	int job[n],p[n],d[n];
	for(i=0;i<n;i++)
	{
		job[i]=i+1;
	}
	printf("\nEnter the deadlines\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("\nEnter the profit\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(p[j]<p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				
				t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
				
				t=job[j];
				job[j]=job[j+1];
				job[j+1]=t;
			}
		}
	}
	max=d[0];
	for(i=0;i<n;i++)
	{
		if(d[i]>=max)
		{
			max=d[i];
		}
	}
	
	for(i=0;i<max;i++)
	{
		s=s+p[i];
	}
	
	for(i=0;i<max;i++)
	{
		for(j=0;j<max-1;j++)
		{
			if(d[j]>d[j+1])
			{
				t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
				
				t=job[j];
				job[j]=job[j+1];
				job[j+1]=t;
			}
		}
	}
	e=valid(d,max);
	if(e==1)
	{
		printf("\nInvalid\n");
	}
	if(e==2)
	{
	printf("\nProfit=%d\n",s);
	
	printf("\nJob processing sequence\n");
	for(i=0;i<max;i++)
	{
		printf("%d ",job[i]);
	}
    }
}
