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
void delete_rear()
  {
   if(isempty())
	 {
	  printf("queue is empty\n");
	  return;
	 }
   printf("item deleted is %d\n",q[(rear)--]);
   if(front>rear)
	 {
	  front=0;
	  rear=-1;
	 }
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
	printf("1.Insert_Rear\n2.Delete_Rear\n3.Delete_Front\n4.Display\n5.Exit\n");
	printf("Enter the Choice\n");
	scanf("%d",&ch);
	switch(ch)
	  {
	   case 1:printf("enter the item\n");
			  scanf("%d",&item);
			  insert_rear();
			  break;
	   case 2:delete_rear();
			  break;
	   case 3:delete_front();
			  break;
	   case 4:display();
			  break;
	   default:exit(0);
	  }
	}
	return 0;
  }
