#include<stdio.h>
#include<stdlib.h>
#define size 5
int front=0,rear=-1,q[size],count=0;
void insertrear(int item)
{
    if(count==size)
    {
        printf("queue overflow");
        return;
    }
    rear=(rear+1)%size;
    q[rear]=item;
    count++;
}
int deletefront()
{ 
    int item;
    if(count==0) return -1;
    item = q[front];
    front=(front+1)%size;
    count=count-1;
    return item;
}
void displayq()
{
    int f;
    if(count==0)
    {
        printf("\nqueue is empty");
        return;
    }
    f=front;
    int c=count;
    printf("\nProgram in the queue");
    while(c!=0)
    {
        printf("\nExecution time : %d",q[f]);
        f=((f+1)%size);
        c--;
    }
}
void execution()
{
    if(count==0)
    {
        printf("\nqueue is empty");
        return;
    }
    int a,flag=0;
    while(flag<5)
    {
        a=deletefront();
        if(a!=0)
        {
            a-=10;
            flag=0;
        }
        insertrear(a);
        if(a==0)
        {
            flag++;
        }
    }   
    printf("\nExecution completed");
    displayq();
    front=0,rear=-1;
}
int main()
{
    int choice,item;
    for(;;)
    {
        printf("\n1.Insert rear\n2.Delete front\n3.Display\n4.Execution\n5.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the execution time of the program :");
            scanf("%d",&item);
            insertrear(item);
            break;
            case 2:item=deletefront();
            if(item==-1)
            printf("queue is empty\n");
            else
            printf("item deleted is %d \n",item);
            break;
            case 3:displayq();
            break;
            case 4:execution();
            break;
            default:exit(0);
        }
    }
    return 0;
}
