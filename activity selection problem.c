#include<stdio.h>
struct activity
{
	int i;
	int start,finish;
};
int partition(struct activity a[],int l,int r)
{
	int pivot=a[r].finish,i=l-1,j;
	struct activity temp;
	for(j=l;j<=r-1;j++)
	{
		if(a[j].finish<pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}
void quicksort(struct activity a[],int l,int r)
{
	if(l<r)
	{
		int pi=partition(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
}
void selection(struct activity activity[],int n)
{
	int j,c=0;
	printf("\nThe solution set is\n");
    printf("%d  ",activity[0].i);
    for(j=1;j<n;j++)
    {
    	if (activity[j].start >= activity[c].finish && activity[j].start<=activity[j].finish) 
		{
            printf("%d  ",activity[j].i);
            c=j;
        }
	}
}
main()
{
	int n,j;
	printf("\nEnter the number of activities\n");
	scanf("%d",&n);
	struct activity activity[n];
	for (j = 0; j < n; j++) {
      activity[j].i=j+1;
   }
	for (j = 0; j < n; j++) {
      printf("\nEnter starting time and finishing time : ");
      scanf("%d", &activity[j].start);
      scanf("%d", &activity[j].finish);
   }
   quicksort(activity,0,n-1);
   printf("\nSorted index\n");
   for(j=0;j<n;j++)
   {
   	printf("%d\t",activity[j].i);
   }
   printf("\nSorted starting time\n");
   for(j=0;j<n;j++)
   {
   	printf("%d\t",activity[j].start);
   }
   printf("\nSorted finishing time\n");
   for(j=0;j<n;j++)
   {
   	printf("%d\t",activity[j].finish);
   }
   selection(activity,n);
}
