#include <stdio.h>
int partition(int start[],int finish[] ,int beg, int end);  
void quickSort(int a[], int finish[],int beg, int end);  
void main()  
{  
    int i;  
    int start[11]={14,13,12,11,10,9,8,7,6,5,4};
	int finish[11]={11,2,8,8,6,5,3,5,0,3,1}; 
    quickSort(start,finish, 0, 10);  
    printf("\n The sorted array is: \n");  
    for(i=0;i<11;i++) 
	{
	printf(" %d\t", start[i]); 
	 }
	 printf("\n The sorted array is: \n");
	 for(i=0;i<11;i++) 
	{
	printf("%d\t",finish[i]); 
	 }  
     
}  
int partition(int start[],int finish[] ,int beg, int end)  
{  
    int left, right, temp, loc, flag;     
    loc = left = beg;  
    right = end;  
    flag = 0;
	 
    while(flag != 1)  
    {  
        while((start[loc] <= start[right]) && (loc!=right))  
        right--;  
        if(loc==right)  
        flag =1;  
        else if(start[loc]>start[right])  
        {  
            temp = start[loc];  
            start[loc] =start[right];  
            start[right] = temp;  
            loc = right; 
			
			temp = finish[loc];  
            finish[loc] =finish[right];  
            finish[right] = temp;  
            loc = right; 
			 
        }  
        if(flag!=1)  
        {  
            while((start[loc] >= start[left]) && (loc!=left))  
            left++;  
            if(loc==left)  
            flag =1;  
            else if(start[loc] < start[left])  
            {  
                temp = start[loc];  
                start[loc] = start[left];  
                start[left] = temp;  
                loc = left;
				
				temp = finish[loc];  
                finish[loc] = finish[left];  
                finish[left] = temp;  
                loc = left; 
            }  
        }  
    }  
    return loc;  
}  
void quickSort(int start[],int finish[], int beg, int end)  
{  
    int loc;  
    if(beg<end)  
    {  
        loc = partition(start,finish, beg, end);  
        quickSort(start,finish, beg, loc-1);  
        quickSort(start,finish, loc+1, end);  
    }  
} 
