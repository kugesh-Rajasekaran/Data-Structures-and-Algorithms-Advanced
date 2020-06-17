#include<stdio.h>
#include<conio.h>

int main()
{
 int *ptr=NULL;
 int noe,ind;
 clrscr();
 printf("\n\tEnter no of ele: ") ;
 scanf("%d",&noe);

 ptr=(int*)calloc(noe,sizeof(int));
// ptr=(int*)malloc(noe*sizeof(int));
 for(ind = 0 ; ind< noe; ind++)
   printf("%d ",ptr[ind]);
 free(ptr);
  getch();
 return 0 ;
}
