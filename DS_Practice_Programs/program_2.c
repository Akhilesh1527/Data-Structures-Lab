#include<stdio.h>
#include<process.h>
#define QUE_SIZE 250
int q[250];
int item;int front=0,rear=-1;
void insertrear()
{

    if(rear==QUE_SIZE-1)
    {
        printf("Registration Closed\n");
        return ;
    }
    rear=rear+1;
    q[rear]=item;
    printf("Registered successfully\n");
}
void displayQ()
{
    int i;
    if(front>rear)
    {
        printf("No registrations yet\n");
        return ;
    }
    printf("Details of registered students:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}
int main()
{
    int choice;
    for(;;)
    {
        printf("\n1:Start Registering now\n2:Details of registered students\n3:Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter your roll number\n");
            scanf("%d",&item);
            insertrear();
            break;
            case 2:displayQ();
            break;
            case 3:exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
