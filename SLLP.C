
#include<stdio.h>
#include<conio.h>
typedef struct node
{
 int data;
 char ch;
 struct node * next;
}NODE;
NODE *newnode,*start,*tptr,*prev;
void addNode(int input)
{
// int *  ptr=(int*)malloc(noe*sizeof(int));
      newnode=(NODE*)malloc(1*sizeof(NODE));
      newnode -> data = input;
      newnode->next = NULL;
 if(start==NULL)
   start=newnode;
 else
 {
  for(prev=NULL,tptr = start;tptr!=NULL && tptr->data < newnode->data;
      prev=tptr, tptr=tptr->next);
  if(tptr==start) //begin
   {
   newnode->next =tptr;
   start= newnode;
   }
   else//mid or end
   {
     newnode->next =tptr;
     prev->next = newnode;
   }

 }
SLLdisplay();
}
SLLdisplay()
{
  for(printf("\n\t"),tptr = start;tptr!=NULL; tptr=tptr->next)
    printf("%d ",tptr->data);
//  getch();
}
void SLLreverse()
{
  NODE * curr,*left , *safe;
  curr=start;
  left=NULL;
  while(curr)
  {
   safe = curr->next;
   curr->next = left;
   left = curr;
   curr=safe;
  }
  start=left;
}
int loop()
{
 NODE * slow,*fast,*first;
 fast = slow= start;
 do
 {
   fast =fast->next;
   if(fast)
     fast=fast->next;
   if(fast==NULL)
     break;
   slow= slow->next;
 }while(slow!=fast);
 if(slow == fast)
 {
   first =start;

   while(slow!=first)
   {
   prev =slow;
   slow=slow->next;
   first= first->next;
   }
   prev->next=NULL;
   printf("\n\tLoop found and removed");
 }
 else
  printf("\n\tNot Found");


}
int findMP()
{
 NODE * slow,*fast;
 fast = slow= start;
 while(1)
 {
   fast =fast->next;
   if(fast)
     fast=fast->next;
   if(fast==NULL)
     break;
   slow= slow->next;
 }
 return slow->data;
}
int main()
{
 clrscr();
 addNode(80);
 addNode(30);
 addNode(20);
 addNode(50);
 addNode(10);
 addNode(90);
 addNode(70);
 addNode(60);
 addNode(100);
 // SLLreverse();
 // SLLdisplay();
// printf("\n\t Mid Value : %d",findMP());
  for(tptr=start; tptr -> next !=NULL; tptr= tptr->next);
  tptr->next = start->next->next->next->next;
 loop();
 SLLdisplay();
 getch();
 return 0 ;
}
