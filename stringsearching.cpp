#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    char arr[]="barber story :Jack went too the barber yesterday and forgot his wallet in his car. And then when he realized he then rushed from the barber shop to fetch it. The barber felt suspecious and called the police. Jack rushing back sences something different with others look on him and then when it was his turn the barber did not allow him to sit on the client's chair. Jack gets angry and mocks the barber shop by its name barberbarberbarber. Everyone is offenced incluving the barber";
    char searchstring[]="barber";
    char bmt[128];
    int cnt=0;
    memset(bmt,0,128*sizeof(char));
    int srchlen=strlen(searchstring);
    int arrlen=strlen(arr),flag;
    for(int itr=srchlen-2;itr>=0;itr--)
    {
        if(bmt[searchstring[itr]]==0)
            bmt[searchstring[itr]]=srchlen-itr-1;
            printf("%d - %c",srchlen-itr-1,searchstring[itr]);
    }
    for(int itr=srchlen-1,ptr=srchlen-1;itr<arrlen;)
    {
        flag=0;
        if(arr[itr]==searchstring[ptr])
        {
            for(int itr2=0;itr2<srchlen;itr2++)
            {
                if(arr[itr-itr2]!=searchstring[ptr-itr2])
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                cnt++;
            }
        }
        if(bmt[arr[itr]]!=0)
        {
            itr+=bmt[arr[itr]];
        }
        else
        {
            itr+=srchlen;
        }
    }
    cout<<endl<<"count:"<<cnt;
}
