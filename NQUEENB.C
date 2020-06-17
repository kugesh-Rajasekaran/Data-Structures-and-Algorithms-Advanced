#include<stdio.h>
#include<conio.h>
#define DIM 8

void block_path(int data[DIM+1][DIM+1], int queen_r, int queen_c)
{
  int row,col;
  data[queen_r][queen_c]=queen_r;
  //left
  for(row = queen_r, col = queen_c-1; col>0 ; col--)
    data[row][col]+= queen_r;
  //left top dia
  for(row = queen_r-1, col = queen_c-1; row>0 && col>0 ; row--,col--)
    data[row][col]+= queen_r;
  //top
   for(row = queen_r-1, col = queen_c; row>0  ; row--)
    data[row][col]+= queen_r;
  //right top dia
  for(row = queen_r-1, col = queen_c+1; row>0 && col<=DIM ; row--,col++)
    data[row][col]+= queen_r;
  //right
  for(row = queen_r, col = queen_c+1; col<=DIM ; col++)
    data[row][col]+= queen_r;
  //right down dia
  for(row = queen_r+1, col = queen_c+1; row<=DIM && col<=DIM ; row++,col++)
    data[row][col]+= queen_r;
  //down
  for(row = queen_r+1, col = queen_c; row<=DIM  ; row++)
    data[row][col]+= queen_r;
  //left down dia
  for(row = queen_r+1, col = queen_c-1; row<=DIM && col>0 ; row++,col--)
    data[row][col]+= queen_r;

}
void free_path(int data[DIM+1][DIM+1], int queen_r, int queen_c)
{
  int row,col;
  data[queen_r][queen_c]=0;
  //left
  for(row = queen_r, col = queen_c-1; col>0 ; col--)
    data[row][col]-= queen_r;
  //left top dia
  for(row = queen_r-1, col = queen_c-1; row>0 && col>0 ; row--,col--)
    data[row][col]-= queen_r;
  //top
   for(row = queen_r-1, col = queen_c; row>0  ; row--)
    data[row][col]-= queen_r;
  //right top dia
  for(row = queen_r-1, col = queen_c+1; row>0 && col<=DIM ; row--,col++)
    data[row][col]-= queen_r;
  //right
  for(row = queen_r, col = queen_c+1; col<=DIM ; col++)
    data[row][col]-= queen_r;
  //right down dia
  for(row = queen_r+1, col = queen_c+1; row<=DIM && col<=DIM ; row++,col++)
    data[row][col]-= queen_r;
  //down
  for(row = queen_r+1, col = queen_c; row<=DIM  ; row++)
    data[row][col]-= queen_r;
  //left down dia
  for(row = queen_r+1, col = queen_c-1; row<=DIM && col>0 ; row++,col--)
    data[row][col]-= queen_r;
}
void path_tracker(int data[DIM+1][DIM+1], int queen_r, int queen_c,int flag)
{
  int row,col;
  for(row= 1; row<=DIM; row++)
    for(col = 1; col<= DIM ;col++)
      if(queen_r==row|| queen_c==col||
	(row-col)==(queen_r-queen_c)|| (row+col)==(queen_r+queen_c))
	       data[row][col]= data[row][col] + (flag *queen_r);
}

void display(int queen_pos[DIM+1])
{
 int row,col;
 gotoxy(1,5);
  for(row= 1,printf("\n\t"); row<=DIM; row++,printf("\n\t"))
   for(col = 1; col<= DIM ;col++)
   {  if(queen_pos[row] == col)
      printf("Q ");
     else
      printf("_ ");
    }

}
int main()
{
 int data[DIM+1][DIM+1]={0};
 int queen_pos[DIM+1]={0};
 int row,col,safe_pos,solCtr=0;
 clrscr();
 safe_pos=0;
 row=1;
while(1)
{
while(row<=DIM)
{
 for(col=safe_pos+ 1;col<=DIM ; col++)
 {
  if(data[row][col]==0)//safety check
  {
    path_tracker(data,row,col,1);    //block the path
    queen_pos[row]=col;      //update queen position
    row++;        //goto nxt row
    safe_pos=0;
    break;
  }
 }
 if(col>DIM)//backtracking
 {
   row--;
   path_tracker(data,row,queen_pos[row],-1);    //free the path
   safe_pos= queen_pos[row];
   queen_pos[row]=0;
 }
}
   display(queen_pos);
   gotoxy(5,3);
   printf("Sol Ctr: %2d",++solCtr);
   delay(200);
   if(solCtr==92)
     break;
   row--;
   path_tracker(data,row,queen_pos[row],-1);    //free the path
   safe_pos= queen_pos[row];
   queen_pos[row]=0;

}
/*
 for(row= 1,printf("\n\t"); row<=DIM; row++,printf("\n\t"))
  for(col = 1; col<= DIM ;col++)
    printf("%2d ",data[row][col]);
*/
 getch();
 return 0 ;
}
