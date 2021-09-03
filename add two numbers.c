#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *start1=NULL;
struct node *start2=NULL;

create_l1()
{
	struct node *newnode,*ptr;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=newnode;
				newnode->next=NULL;
			}
			printf("\nEnter the data");
			scanf("%d",&num);
		}

}
create_l2()
{
	struct node *newnode,*ptr;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		if(start1==NULL)
		{
			newnode->next=NULL;
			start1=newnode;
		}
		else
		{
			ptr=start1;
			while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=newnode;
				newnode->next=NULL;
			}
			printf("\nEnter the data");
			scanf("%d",&num);
		}
}
int numberconversion_l1(struct node *start)
{
	struct node *t=start;
	int i,p=0,c,r,s=0;
	while(t!=NULL)
	{
		c=t->data;
		p=p+c;
		p=p*10;
		t=t->next;
	}
	p=p/10;
	while(p!=0)
 {
 	r=p%10;
 	s=s+r;
 	s=s*10;
 	p=p/10;
	 }
	 s=s/10;
	 printf("%d",s);
	 return s;
}
/*int reverse(int p)
{
 int s=0,r;
 while(p!=0)
 {
 	r=p%10;
 	s=s+r;
 	s=s*10;
 	r=r/10;
	 }
	 s=s/10;
	 return s;	
}*/
int numberconversion_l2(struct node *start1)
{
	struct node *t=start1;
	int i,p=0,c,r,s=0;
	while(t!=NULL)
	{
		c=t->data;
		p=p+c;
		p=p*10;
		t=t->next;
	}
	p=p/10;
		while(p!=0)
 {
 	r=p%10;
 	s=s+r;
 	s=s*10;
 	p=p/10;
	 }
	 s=s/10;
	 return s;
}
int ele()
{
int a=numberconversion_l1(struct node *start);
while(a!=0)
{
	r=a%10
	}	
}
void create_l3(int e)
{
	struct node *newnode,*ptr;
	int num;
	while(e>0)
	{
		//num=e%10;
		num=ele(start)
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		if(start2==NULL)
		{
			newnode->next=NULL;
			start2=newnode;
		}
		else
		{
			ptr=start2;
			while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=newnode;
				newnode->next=NULL;
			}
			e=e/10;
	}		
}
displayl3()
{
	struct node *ptr;
	ptr=start2;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
displayl1()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
displayl2()
{
	struct node *ptr;
	ptr=start1;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
main()
{
int c,r,d,e;
create_l1();
printf("\nThe first linked list\n");
displayl1();
printf("\n");
create_l2();
c=numberconversion_l1(start);
d=numberconversion_l2(start1);
e=c+d;
printf("\nThe second linked list is\n");
displayl2();
printf("\n");
create_l3(e);
printf("\n");
printf("\nThe required output\n");
displayl3();	
}
