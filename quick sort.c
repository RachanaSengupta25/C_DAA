#include<stdio.h>
void quicksort(int arr[100],int f,int l){
   int i,j,p,t;
   if(f<l){
      p=f;
      i=f;
      j=l;
      while(i<j){
         while(arr[i]<=arr[p] && i<l)
            i++;
         while(arr[j]>arr[p])
            j--;
         if(i<j){
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
         }
      }
      t=arr[p];
      arr[p]=arr[j];
      arr[j]=t;
      quicksort(arr,f,j-1);
      quicksort(arr,j+1,l);
   }
}
main(){
   int i, count,arr[100];
   printf("Number of elements");
   scanf("%d",&count);
   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);
   quicksort(arr,0,count-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf("%d\t",arr[i]);
}
