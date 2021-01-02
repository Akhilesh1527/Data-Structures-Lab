#include<stdio.h>
#include<process.h>
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
   printf("item deleted is %d\n",q[(front)++]);
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
	  printf("Insertion Not Possible\n");
  }
void delete_rear()
  {
   if(isempty())
	 {
	  printf("Queue is Empty\n");
	  return;
	 }
   printf("The Item Deleted is %d\n",q[(rear)--]);
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
	  printf("Queue is Empty\n");
	  return;
	 }
   for(i=front;i<=rear;i++)
	printf("%d\n",q[i]);
  }
int main()
 {
  for(;;)
   {
	printf("1.Insert_Rear\n2.Insert_Front\n3.Delete_Rear\n4.Delete_Front\n5.Display\n6.Exit\n");
	printf("Enter the Choice\n");
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
	   case 3:delete_rear();
			  break;
	   case 4:delete_front();
			  break;
	   case 5:display();
			  break;
	   default:exit(0);
	  }
	}
	return 0;
  }
