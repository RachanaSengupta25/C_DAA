#include<stdio.h>
int RecursiveBsearch(int A[], int start, int end, int element) {
	int i,j,t;
	for(i=0;i<end+1;i++)
	{
		for(j=0;j<(end+1)-1;j++)
		{
			if(A[j]>A[j+1])
			{
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
   if(start>end) 
   return -1;
      int mid = (start+end)/2;
   if( A[mid] == element ) return mid;
   else if( element < A[mid] )
      RecursiveBsearch(A, start, mid-1, element);
   else
      RecursiveBsearch(A, mid+1, end, element);
}
int main() {
	int i,k,n;
	printf("\nEnter the range of the array");
	scanf("%d",&k);
	int A[k];
	printf("\nEnter the elements of the array");
	for(i=0;i<k;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("\nEnter the element that you want to search");
	scanf("%d",&n);
   printf("%d is found at Index %d \n",n,RecursiveBsearch(A,0,k-1,n));
   printf("\nThe sorted array is");
   for(i=0;i<n;i++)
   {
   	printf("%d ",A[i]);
   }
   return 0;
}
