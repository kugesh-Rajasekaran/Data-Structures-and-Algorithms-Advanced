#include<stdio.h>
#include<conio.h>
#include<bios.h>
int main()
{
 int key;
 clrscr();
 do
 {
 while(bioskey(1)==0);//wait &*watch
 key =bioskey(0); //receptionist enquire
 printf("\n\t%d",key);
 }while(key!=283);

 getch();
 return 0 ;
}
