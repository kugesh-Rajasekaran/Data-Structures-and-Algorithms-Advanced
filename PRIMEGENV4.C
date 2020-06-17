#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100000000
int main()
{
   long long int num,till,primeCtr=0,ind,multiplier,limit,mask;
   long long int * primes=NULL;
   limit=64;
    primes=( long long int *)calloc((SIZE/limit)+1,sizeof(long long int));
  // primes[0]=primes[1]=-1;
    primes[0]=primes[0]|3;
 //      primes[0]=primes[0]|1; primes[0]=primes[0]|2;//
   till = sqrt(SIZE);
  for(num=2 ; num <= till ; num++)
  {
    mask=1;
    mask = mask<<(num%limit);
  // if(primes[num] == 0)
   if((primes[num/limit]&mask)==0)
   {
       for(multiplier= 2 ; multiplier*num < SIZE; multiplier++)
        {
            mask = 1;
            mask = mask << ((multiplier*num)%limit);
            primes[(multiplier*num)/limit]=primes[(multiplier*num)/limit]|mask;
            //primes[multiplier*num]=1;
        }
   }
  }
  for(ind=0 ; ind<=SIZE; ind++)
  {
     mask=1;
     mask = mask<<(ind%limit);
      if((primes[ind/limit]&mask)==0)
           primeCtr++;
   }
   printf("%lld",primeCtr);

  free(primes);
   return 0;
}
