#include<stdio.h>
#include<conio.h>
struct node
{
  int data;
  struct node* prev;
  struct node* next;
};
typedef struct node NODE;
void addNode(NODE**stptr,NODE**endptr,int input)
{
 NODE * newnode=NULL,*tptr=NULL;
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->data= input;
 newnode-> prev= newnode->next= NULL;

 if(*stptr == NULL || *endptr== NULL)
  *stptr = *endptr = newnode;

 else
 {
 for(tptr=*stptr; tptr&&tptr->data< newnode->data; tptr= tptr->next);
 if(tptr==*stptr)
 {
   newnode->next = *stptr;
   (*stptr)->prev = newnode;
   *stptr = newnode;
 }
 else if(tptr==NULL)
 {
   newnode->prev = *endptr;
   (*endptr)->next = newnode;
   *endptr = newnode;
 }
 else
 {
  newnode->next = tptr;
  newnode->prev = tptr->prev;
  tptr->prev->next = newnode;
  tptr->prev = newnode;
 }
}
}
void displayDLL(NODE * st, NODE *ed)
{
 NODE * tptr=NULL;
 for(printf("\n\t FOR : "),tptr=st; tptr ; printf("%2d ->",tptr->data),tptr=tptr->next);
 for(printf("\n\t REV : "),tptr=ed; tptr ; printf("%2d ->",tptr->data),tptr=tptr->prev);
 getch();
}
int main()
{
 NODE *start=NULL,*end=NULL;
 clrscr();
 addNode(&start,&end,40);
 displayDLL(start,end);
 addNode(&start,&end,20);
 displayDLL(start,end);
 addNode(&start,&end,10);
 displayDLL(start,end);
 addNode(&start,&end,30);
 displayDLL(start,end);
 addNode(&start,&end,50);
 displayDLL(start,end);

 getch();
 return 0 ;
}
