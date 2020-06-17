#include<stdio.h>
#include<conio.h>
typedef struct node
{
 int data;
 struct node* left;
 struct node *right;
}NODE;
void addNode(NODE ** rootptr, int input)
{
 NODE*newnode=NULL,*tptr=NULL,*prev=NULL;
 newnode = (NODE*)malloc(sizeof(NODE));
 newnode->data = input;
 newnode->left = newnode->right= NULL;
 if(*rootptr==NULL)//no tree
   *rootptr=newnode;
 else
 {
 /*   tptr=*rootptr;
   prev=NULL;
   while(tptr)
   {
   prev=tptr;
   if(newnode->data < tptr->data )
      tptr = tptr->left;
   else
    tptr = tptr->right;
   }
*/
 for( tptr=*rootptr,prev=NULL;tptr;
   prev=tptr,tptr= (newnode->data < tptr->data)?tptr->left:tptr->right);
   if(newnode->data < prev->data)
     prev->left = newnode;
   else
     prev->right= newnode;
 }
}


void display(NODE * gptr)
{
  if(gptr==NULL)
   return;
  display(gptr->left);
  printf("%2d ",gptr->data);
  display(gptr->right);
}
struct queue
{
 NODE*tadd;
 struct queue * qnext;
};
typedef struct queue QNODE;
//void addNode(NODE ** stptr,NODE ** endptr,int input)
void enQ(QNODE **fptr , QNODE**rptr,NODE * tptr )
{
   QNODE* newQnode=NULL;
   newQnode=(QNODE*)malloc(sizeof(QNODE));
   newQnode->tadd = tptr;
   newQnode->qnext = NULL;
   if(*fptr==NULL || *rptr==NULL)
      *fptr=*rptr = newQnode;
   else
    {
     (*rptr)->qnext= newQnode;
     *rptr = newQnode;
     }
}
//void deleteNode(NODE**endptr, int delData)
NODE * deQ(QNODE **fptr , QNODE**rptr)
{
  NODE * toReturn=NULL;
  QNODE * toFree=NULL;
  if(*fptr==NULL)//empty queue
  return toReturn;
  toFree= *fptr;
  toReturn = (*fptr)->tadd;
  (*fptr)= (*fptr)->qnext;
  free(toFree);
  return toReturn;
}

void levelOrderDisplay(NODE * nptr)
{
 QNODE*front=NULL,*rear=NULL;
 NODE * tptr=NULL;
 enQ(&front,&rear,nptr);
 while(1)
 {
  tptr = deQ(&front,&rear);
  if(tptr==NULL) break;
  printf(" %d",tptr->data);
  if(tptr->left)
  enQ(&front,&rear,tptr->left);
  if(tptr->right)
  enQ(&front,&rear,tptr->right);
 }

}


int main()
{
 NODE * root=NULL;
 clrscr();
 addNode(&root,50);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,30);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,70);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,60);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,20);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,80);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,40);
 printf("\n\t INORDER :");
 display(root);
 getch();
 addNode(&root,35);
 printf("\n\t INORDER :");
 display(root);
 printf("\n LEVEL order :");
 levelOrderDisplay(root);
 getch();
 return 0 ;
}
