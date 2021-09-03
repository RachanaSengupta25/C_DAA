#include<stdio.h>
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void heapify(int arr[], int n, int i) {
    int max = i; 
    int l= 2*i+1;
    int r=2*i+2;
    if (l< n && arr[l]>arr[max])
      max=l;
    if (r<n && arr[r]>arr[max])
      max=r;
    if (max!=i) {
      swap(&arr[i],&arr[max]);
      heapify(arr,n,max);
    }
  }
void heapsort(int arr[],int n)
{
	int i=n/2;
	for(i=n/2-1;i>=0;i--)
	heapify(arr,n,i);
	for(i=n/2-1;i>=0;i--)
	{
		swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);
	}
}
void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
main()
{
	int i,n;
	printf("\nEnter the range of the array");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements in the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nThe original array is\n");
	display(arr,n);
	heapsort(arr,n);
	printf("\nThe sorted array is\n");
	display(arr,n);
}
