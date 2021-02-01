#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int top = -1, front = 0;
int stack[MAX];

void push(char item)
{
    top++;
    stack[top]=item;
}

void pop()
{
    top--;
}

int main()
{
	char s[MAX],b;
    int i,choice;
    for(;;)
    {
        printf("1:Enter the String\n2:Exit\n");
        printf("Enter your Choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            scanf("%s", s);
            for (i = 0;s[i] != '\0';i++)
            {
                b = s[i];
                push(b);
            }
            for (i = 0;i < (strlen(s) / 2);i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("Both the Students Spelled Out the Different Word \n");
                    break;
                }
            }
            if ((strlen(s) / 2)==front)
                printf("Both the Students Spelled Out the Same Word: %s\n",s);
            front  =  0;
            top  =  -1;
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
