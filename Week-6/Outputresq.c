#include<stdio.h>
#include<stdlib.h>
#define qsize 3
int front=0,rear=-1,ch;
int item,q[10];

int isfull()
  {
   return(rear==qsize-1)?1:0;
  }
int isempty()
  {
   return(front>rear)?1:0;
  }
void insert_rear()
  {
   if(isfull())
	 {
	  printf("Queue Overflow\n");
	  return;
	 }
   rear=rear+1;
   q[rear]=item;
  }
void delete_front()
  {
   if(isempty())
	 {
	  printf("Queue is Empty\n");
	  return;
	 }
   printf("The Item Deleted is %d\n",q[(front)++]);
   if(front>rear)
	 {
	  front=0;
	  rear=-1;
	 }
  }
void insert_front()
  {
   if(front!=0)
	 {
	  front=front-1;
	  q[front]=item;
	  return;
	 }
	else if((front==0)&&(rear==-1))
	 {
	  q[++(rear)]=item;
	  return;
	 }
	else
	  printf("insertion is Not Possible\n");
  }
void display()
  {
   int i;
   if(isempty())
	 {
	  printf("queue empty\n");
	  return;
	 }
	 printf("Contents of queue:\n");
   for(i=front;i<=rear;i++)
	printf("%d\n",q[i]);
  }
int main()
 {

  for(;;)
   {
	printf("1.Insert_Rear\n2.Insert_Front\n3.Delete_Front\n4.Display\n5.Exit\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	  {
	   case 1:printf("Enter the Item\n");
			  scanf("%d",&item);
			  insert_rear();
			  break;
	   case 2:printf("Enter the Item\n");
			  scanf("%d",&item);
			  insert_front();
			  break;
	   case 3:delete_front();
			  break;
	   case 4:display();
			  break;
	   default :exit(0);
	  }
	}
	return 0;
  }

