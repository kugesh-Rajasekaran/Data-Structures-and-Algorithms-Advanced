#include<stdio.h>
#include<conio.h>
#include<limits.h>//inlcuding
//int n=0,n_arr[10];
void fun(int * arr , int size , int curr_ind,int prev ,int*seq,int s_ind)
{
 int ind;
 if(curr_ind==size)//base condition
 {
  /*   if(n<s_ind){
        for(ind=0;ind<s_ind;ind++)
            n_arr[ind]=seq[ind];
        n=s_ind;
     }*/
  for(printf("\n\t"),ind= 0 ;ind < s_ind ; ind++)
     printf("%d ",seq[ind]);
  return;
 }
   fun(arr,size,curr_ind+1,prev,seq,s_ind);  //excluding
   if(arr[curr_ind] > prev)
   {
    prev= seq[s_ind++]=arr[curr_ind];//inlcuding
    fun(arr,size,curr_ind+1,prev,seq,s_ind);
   }
}
int main()
{
 int arr[]={3,1,2,4,5};
 int size,prev=INT_MIN;
 int seq[5];
 size= sizeof arr / sizeof arr[0];
 fun(arr,size,0,prev,seq,0);
/*for(int ind=0;ind<n;ind++)
    printf("%d ",n_arr[ind]);*/
 getch();
 return 0 ;
}
