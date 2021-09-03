#include<stdio.h>
void knapsack(int n, float weight[],float profit[], int cap,int index[]);
int strategy1();
int strategy2();
int strategy3();
int main(){
float weight[100];
float profit[100];
float index[100];
int capacity;
int i,n,j,temp,c=0;
float ratio[100];
	int choice;
	while(c<3)
	{
	printf("\nENTER THE CHOICE\n1 for strategy 1 2 for strategy 2 and 3 for strategy 3");
	scanf("%d",&choice);
	switch(choice){
		case 1:strategy1();
		c++;
		break;
		case 2:strategy2();
		c++;
			break;
		case 3:
			strategy3();
			c++;
			break;	
	}	
	}	
}
strategy1(){
	int i,n,j,temp,capacity;
	printf("Enter no of objects: ");
	scanf("%d",&n);
float weight[n];
float profit[n];
int index[n];
	printf("\n Enter weight of objects");
	for(i=0;i<n;i++){
		scanf("%f",&weight[i]);
	}
	for(i=0;i<n;i++){
		index[i]=i;
	}
	printf("\n Enter profit: ");
	for(i=0;i<n;i++){
		scanf("%f",&profit[i]);
	}
	printf("\n Enter capacity");
	scanf("%d",&capacity);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(profit[i]<profit[j]){
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				temp=index[j];
				index[j]=index[i];
				index[i]=temp;	
			}
		}
	}
	knapsack(n, weight, profit, capacity, index);	
}
strategy2(){
	int i,n,j,temp,capacity;
	printf("Enter no of objects: ");
	scanf("%d",&n);
float weight[n];
float profit[n];
int index[n];
	printf("\n Enter weight of objects");
	for(i=0;i<n;i++){
		scanf("%f",&weight[i]);
	}
	for(i=0;i<n;i++){
		index[i]=i;
	}
	printf("\n Enter profit: ");
	for(i=0;i<n;i++){
		scanf("%f",&profit[i]);
	}
	printf("\n Enter capacity");
	scanf("%d",&capacity);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(weight[i]>weight[j]){
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;	
				temp=index[j];
				index[j]=index[i];
				index[i]=temp;	
			}
		}	
	}
	knapsack(n, weight, profit, capacity, index);
}
strategy3(){
float weight[100];
float profit[100];
float ratio[100];
int index[100];
	int i,n,j,temp,capacity;
	printf("Enter no of objects: ");
	scanf("%d",&n);
	printf("\n Enter weight of objects");
	for(i=0;i<n;i++){
		scanf("%f",&weight[i]);
	}
for(i=0;i<n;i++){
		index[i]=i;
	}
	printf("\n Enter profit: ");
	for(i=0;i<n;i++){
		scanf("%f",&profit[i]);
	}
	printf("\n Enter capacity");
	scanf("%d",&capacity);
	for (i = 0; i < n; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(ratio[i]<ratio[j]){
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;	
				temp=index[j];
				index[j]=index[i];
				index[i]=temp;	
			}
		}	
	}
	knapsack(n, weight, profit, capacity, index);
}
void knapsack(int n, float weight[],float profit[], int cap, int index[]){
   float x[20], tp = 0,d;
   int k;
   int i, j, u;
   u = cap;
   for (i = 0; i < n; i++)
   {
   	   x[i] = 0.0;
   }
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[index[i]] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
   if (i < n)
   {
      x[index[i]] = u / weight[i];
   tp = tp + (x[index[i]] * profit[i]);
   }  
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
   printf("\nMaximum profit is:- %f", tp);	
}
