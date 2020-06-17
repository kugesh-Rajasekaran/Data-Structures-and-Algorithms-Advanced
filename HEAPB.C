
#include<stdio.h>
#include<conio.h>
void maxHeapify(int * arr , int scope , int parent);
void swapper(int *arr , int ind1 , int ind2);
int main()
{
 int arr[]={5,15,10,25,55,35,75,45,95,50,70,40,60,90,3};
 int size,scope,parent,ind ;
 clrscr();
 size = sizeof arr / sizeof arr[0];
 scope =size-1;
  for(printf("\n\t") , ind= 0 ; ind <size; printf("%2d ",arr[ind++]));
/*
 while(scope)
 {
 for( parent = (scope-1)/2; parent >=0; parent--)
   maxHeapify(arr,scope,parent);
 swapper(arr,0,scope);
 scope--;
 }
*/

 for( parent = (scope-1)/2; parent >=0; parent--)
   maxHeapify(arr,scope,parent);
 swapper(arr,0,scope);
 scope--;

 while(scope)
 {
   maxHeapify(arr,scope,0);
   swapper(arr,0,scope);
   scope--;
 }

 for(printf("\n\t") , ind= 0 ; ind <size; printf("%2d ",arr[ind++]));

 getch();
 return 0 ;
}
void maxHeapify(int * arr , int scope , int parent)
{
 int left,right;
 left = parent * 2 +1;
 right =left+1;
 if(left>scope)//no child
   return;
 if(left == scope) //single child
 {
   if(arr[parent] < arr[left])
     swapper(arr,parent ,left);
 }
 else if(right <= scope)//two child
 {
  if(arr[parent]<arr[left]|| arr[parent] < arr[right])
  {
    if(arr[left] > arr[right])
    {
     swapper(arr,parent ,left);
    maxHeapify(arr,scope,left);
    }
    else
    {
	 swapper(arr,parent,right);
	 maxHeapify(arr,scope,right);
    }
  }
 }
}


void swapper(int *arr , int ind1 , int ind2)
{
 int temp;
  temp =arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] =temp;
}
