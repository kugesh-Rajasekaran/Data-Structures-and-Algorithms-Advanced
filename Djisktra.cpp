#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
int cnt=0;
struct edges
{
    char A,B;
    int weight;
};
struct lolistnode
{
    char data;
    int weight;
    struct lolistnode *next;
};
struct lolisthead
{
    char data;
    struct lolisthead *next;
    struct lolistnode *frnt;
}*lhead;
struct djisktra
{
    char data;
    bool visited;
    int cost;
    char prev;
}*tble;
void print()
{
    for(struct lolisthead *iter=lhead;iter!=NULL;iter=iter->next)
    {
        cout<<iter->data<<":";
        for(struct lolistnode *iter2=iter->frnt;iter2!=NULL;iter2=iter2->next)
        {
            cout<<"("<<iter2->data<<","<<iter2->weight<<")"<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
struct lolisthead* ispresentinhead(char a)
{
    if(lhead==NULL)
        return NULL;
    for(struct lolisthead *iter=lhead;iter!=NULL;iter=iter->next)
        {
            if(iter->data==a)
            {
                return iter;
            }
        }
    return NULL;
}
void pushlistnode(struct lolisthead *head,char a,int w)
{
    struct lolistnode *newnode =(struct lolistnode*) malloc(sizeof(struct lolistnode));
    newnode->data=a;
    newnode->weight=w;
    newnode->next=NULL;
    if(head->frnt==NULL)
    {
        head->frnt=newnode;
        return;
    }
    struct lolistnode *iter=head->frnt;
    for(;iter->next!=NULL;iter=iter->next);
    iter->next=newnode;
}
void pushlisthead(char data)
{
    struct lolisthead *newheadnode = (struct lolisthead*) malloc(sizeof(struct lolisthead));
    newheadnode->data=data;
    newheadnode->next=NULL;
    newheadnode->frnt=NULL;
    if(lhead==NULL)
    {
        lhead=newheadnode;
    }
    else
    {
        struct lolisthead *iter=lhead;
        for(;iter->next!=NULL;iter=iter->next);
        iter->next=newheadnode;
    }
}
int findmin(int cnt)
{
    int min=INT_MAX,ind=0;
    for(int i=0;i<cnt;i++)
    {
        if(min>tble[i].cost && tble[i].visited==false)
        {
            min=tble[i].cost;
            ind=i;
        }
    }
    tble[ind].visited=true;
    return ind;
}
int findind(char a)
{
    for(int i=0;i<cnt;i++)
    {
       if(tble[i].data==a)
       {
           return i;
       }
    }
}
void updatedj(int itr)
{
    struct lolisthead *fm;
    fm=ispresentinhead(tble[itr].data);
    if(fm==NULL)
        return;
    struct lolistnode *iter =fm->frnt;
    for(;iter!=NULL;iter=iter->next)
    {
        int ind=findind(iter->data);
        if(tble[ind].visited == false && tble[ind].cost>(iter->weight+tble[itr].cost))
        {
            tble[ind].prev=tble[itr].data;
            tble[ind].cost=iter->weight+tble[itr].cost;
        }
    }
}
edges data[]={{'A','E',1},{'A','C',2},{'A','F',3},{'D','B',4},{'E','C',5},{'G','F',6},{'H','G',8},{'I','E',10},{'J','E',10},{'K','D',12},{'H','B',64},{'M','B',102}};
int main()
{
    struct lolisthead *fm,*to;
    for(int i=0;i<sizeof(data)/sizeof(data[0]);i++)
    {
        fm=ispresentinhead(data[i].A);
        to=ispresentinhead(data[i].B);
        if(fm==NULL)
        {
            pushlisthead(data[i].A);
            cnt++;
            fm=ispresentinhead(data[i].A);
        }
        if(to==NULL)
        {
            pushlisthead(data[i].B);
            cnt++;
            to=ispresentinhead(data[i].B);
        }
        pushlistnode(fm,data[i].B,data[i].weight);
        pushlistnode(to,data[i].A,data[i].weight);
    }
    print();
    tble = (struct djisktra*) malloc(cnt*sizeof(struct djisktra));
    int itr=0;
    for(struct lolisthead* iter = lhead;iter!=NULL;iter=iter->next)
    {
        tble[itr].data=iter->data;
        tble[itr].prev='_';
        tble[itr].cost=INT_MAX;
        tble[itr].visited=false;
        itr++;
    }
    char start;
    cout<<"\nENTER THE STARTING NODE:  ";
    cin>>start;
    tble[findind(start)].cost=0;
    tble[findind(start)].prev='-';
    int iter;
    for(int i=0;i<cnt;i++)
    {
        iter=findmin(cnt);
        updatedj(iter);
    }
    cout<<endl;
    for(int i=0;i<cnt;i++)
    {
        printf("(%c-%d-%4d-%c)\n",tble[i].data,tble[i].visited,tble[i].cost,tble[i].prev);
    }
    return 0;
}