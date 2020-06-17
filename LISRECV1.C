#include<stdio.h>
#include<conio.h>
#include<limits.h>
int max=0;
void fun(int * arr , int size , int curr_ind,int prev ,int count)
{
 int ind;
 if(curr_ind==size)//base condition
 {
  if(count >max)
    max=count;
  return;
 }
   fun(arr,size,curr_ind+1,prev,count);  //excluding
   if(arr[curr_ind] > prev)
   {
    prev=arr[curr_ind];//inlcuding
    fun(arr,size,curr_ind+1,prev,count+1);
   }
}
int main()
{
 int arr[]={3,1,2,4,5};
 int size,prev=INT_MIN;
 clrscr();
 size= sizeof arr / sizeof arr[0];
 fun(arr,size,0,prev,0);
 printf("\t%d",max);
 getch();
 return 0 ;
}
