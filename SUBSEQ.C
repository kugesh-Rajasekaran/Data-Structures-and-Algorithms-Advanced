#include<stdio.h>
#include<conio.h>
#include<limits.h>//inlcuding
void fun(int * arr , int size , int curr_ind,int*seq,int s_ind)
{
 int ind;
 if(curr_ind==size)//base condition
 {
  for(printf("\n\t"),ind= 0 ;ind < s_ind ; ind++)
     printf("%d ",seq[ind]);
  return;
 }
    fun(arr,size,curr_ind+1,seq,s_ind);  //excluding
    seq[s_ind++]=arr[curr_ind];//inlcuding
    fun(arr,size,curr_ind+1,seq,s_ind);
}
int main()
{
 int arr[]={3,1,2};
 int size,prev=INT_MIN;
 int seq[5];

 size= sizeof arr / sizeof arr[0];
 fun(arr,size,0,seq,0);
 getch();
 return 0 ;
}
