#include<stdio.h>
#include<conio.h>
struct node
{
  int data;
  struct node * next;
  struct node * prev;
};
typedef struct node NODE;
void addNode( NODE ** startPtr, NODE ** endPtr, int input)
{
 NODE * newnode=NULL,*tptr=NULL;
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->data = input;
 newnode->next = newnode->prev= NULL;
 if(*startPtr==NULL || *endPtr==NULL)
 {
  *startPtr=*endPtr=newnode;
 }
 else
 {
 for(tptr=*startPtr ; tptr && tptr->data < newnode->data ; tptr= tptr->next);
 if(tptr==NULL) //at end
 {
 ( *endPtr)->next = newnode;
  newnode->prev = *endPtr;
  *endPtr =newnode;
 }
 else if(tptr==*startPtr)//at begin
 {
  (*startPtr)->prev=newnode;
  newnode->next = *startPtr;
  *startPtr= newnode;
 }
 else
 {
  newnode->next = tptr;
  newnode->prev = tptr->prev;
  tptr->prev->next  =newnode;
  tptr->prev=newnode;
 }
 }
}
DLLdisplay(NODE * st , NODE *ed)
{
 NODE* tptr=NULL;
  for(printf("\n\tFOR : "),tptr=st;tptr ;
     printf("%2d -> ",tptr->data), tptr=tptr->next);
  for(printf("\n\tREV : "),tptr=ed; tptr ;
     printf("%2d -> ",tptr->data), tptr=tptr->prev);
  getch();
}
void deleteNode( NODE ** startPtr, NODE ** endPtr, int delData)
{
 NODE * tptr=NULL;
 for(tptr = *startPtr ;tptr&& tptr->data!= delData ; tptr = tptr->next);
 if(tptr==NULL)
  printf("\n\t Value not found");
 else if(tptr==*startPtr)
 {
   tptr->next->prev=NULL;
   *startPtr = tptr->next;
   free(tptr);
 }
 else if(tptr==*endPtr)
 {
   tptr->prev->next=NULL;
   *endPtr = tptr->prev;
   free(tptr);
 }
 else
 {
 tptr->prev->next = tptr->next;
 tptr->next->prev= tptr->prev;
 free(tptr);
 }

}
int main()
{
 NODE * start=NULL,*end=NULL;
 clrscr();
 addNode(&start, & end , 30);
 DLLdisplay(start,end);
 addNode(&start, & end , 40);
 DLLdisplay(start,end);
 addNode(&start, & end , 10);
 DLLdisplay(start,end);
 addNode(&start, & end , 20);
 DLLdisplay(start,end);
 addNode(&start, & end , 50);
 DLLdisplay(start,end);

 deleteNode(&start, & end , 30);
 DLLdisplay(start,end);
 deleteNode(&start, & end , 10);
 DLLdisplay(start,end);
 deleteNode(&start, & end , 50);
 DLLdisplay(start,end);
 deleteNode(&start, & end ,70);
 DLLdisplay(start,end);


 getch();
 return 0 ;
}
