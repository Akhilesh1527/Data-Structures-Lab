#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
 {
  int info;
  struct node *rlink;
  struct node *llink;
 };
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("Memory Full\n");
  exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}


NODE insert(NODE root,int item)
{
NODE temp,cur,prev;
temp=getnode();
temp->rlink=NULL;
temp->llink=NULL;
temp->info=item;
if(root==NULL)
 return temp;
prev=NULL;
cur=root;
while(cur!=NULL)
{
prev=cur;
cur=(item<cur->info)?cur->llink:cur->rlink;
}
if(item<prev->info)
 prev->llink=temp;
else
 prev->rlink=temp;
return root;
}


void display(NODE root,int i)
{
int j;
if(root!=NULL)
 {
  display(root->rlink,i+1);
  for(j=0;j<i;j++)
	  printf("  ");
   printf("%d\n",root->info);
	 display(root->llink,i+1);
 }
}


void preorder(NODE root)
{
if(root!=NULL)
 {
  printf("%d\n",root->info);
  preorder(root->llink);
  preorder(root->rlink);
  }
 }
void postorder(NODE root)
{
if(root!=NULL)
 {

  postorder(root->llink);
  postorder(root->rlink);
  printf("%d\n",root->info);
  }
 }
void inorder(NODE root)
{
if(root!=NULL)
 {
  inorder(root->llink);
  printf("%d\n",root->info);
  inorder(root->rlink);
  }
 }
void Maximum(NODE root)
{
	while(root!=NULL && root->rlink!=NULL)
	{
		root=root->rlink;
	}
	printf("\nThe Maximum value in the tree : %d",root->info);
}


void Minimum(NODE root)
{
	while(root!=NULL && root->llink!=NULL)
	{
		root=root->llink;
	}
	printf("\nThe Minimum value in the tree : %d",root->info);
}


int count(NODE root){
 int c=1;
 if(root==NULL)
    return 0;
 else{
    c+=count(root->llink);
    c+=count(root->rlink);
    return c;
    }
}


int main()
{

int item,choice,c;
NODE root=NULL;
for(;;)
{
printf("\n1.Insert\n2.Display\n3.pre-order\n4.post-order\n5.in-order\n6.Count\n7.Maximum\n8.Minimum\n9.Exit\n");
printf("Enter the Choice : ");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("Enter the Item : \n");
		 scanf("%d",&item);
		 root=insert(root,item);
		 break;
  case 2:display(root,0);
		 break;
  case 3:preorder(root);
		 break;
  case 4:postorder(root);
		 break;
  case 5:inorder(root);
		 break;
  case 6:c=count(root);
         printf("No. of nodes are: %d\n",c);
         break;
  case 7:Maximum(root);
         break;
  case 8:Minimum(root);
         break;       
  default:exit(0);
		  break;
	  }
	}
	return 0;
 }
