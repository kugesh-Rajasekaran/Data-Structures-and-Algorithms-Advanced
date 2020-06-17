#include<iostream>
#include<malloc.h>
using namespace std;
struct edges
{
    char A,B;
    int weight;
};
void print();
edges data[]={{'A','E',1},{'A','C',2},{'A','F',3},{'D','B',4},{'E','C',5},{'F','A',5},{'G','F',6},{'H','G',8},{'I','E',10},{'J','E',10},{'K','D',12},{'H','B',64},{'M','B',102}};
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
void pushlisthead(char data)
{
    struct lolistnode *newnode =(struct lolistnode*) malloc(sizeof(struct lolistnode));
    newnode->data=data;
    newnode->next=NULL;
    newnode->weight=-1;
    struct lolisthead *newheadnode = (struct lolisthead*) malloc(sizeof(struct lolisthead));
    newheadnode->data=data;
    newheadnode->frnt=newnode;
    newheadnode->next=NULL;
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
bool ispresentinhead(char a)
{
    if(lhead==NULL)
        return false;
    for(struct lolisthead *iter=lhead;iter!=NULL;iter=iter->next)
        {
            if(iter->data==a)
            {
                return true;
            }
        }
    return false;
}
struct lolisthead* findhead(char a)
{
    for(struct lolisthead *iter=lhead;iter!=NULL;iter=iter->next)
    {
        for(struct lolistnode *iter2=iter->frnt;iter2!=NULL;iter2=iter2->next)
        {
            if(iter2->data==a)
            {
                return iter;
            }
        }
    }
    return NULL;
}
void remove (struct lolisthead *node)
{
    struct lolisthead *iter=lhead,*prev;
    for(;iter!=node;prev=iter,iter=iter->next);
    if(prev==NULL)
    {
        lhead=iter->next;
        return;
    }
    prev->next=iter->next;
    free(iter);
}
void kruskalistswap(struct lolisthead *fm,struct lolisthead *to)
{
    struct lolistnode *iter2;
    for(iter2=fm->frnt;iter2->next!=NULL;iter2=iter2->next);
    iter2->next=to->frnt;
    to->frnt=NULL;
    remove(to);
    print();
}
void kruskals()
{
    struct lolisthead *fm,*to;
    for(int i=0;i<sizeof(data)/sizeof(data[0]);i++)
    {
        fm=findhead(data[i].A);
        to=findhead(data[i].B);
        if(fm!=to && fm!=NULL && to!=NULL)
        {
            kruskalistswap(fm,to);
        }
    }
}
void print()
{
    for(struct lolisthead *iter=lhead;iter!=NULL;iter=iter->next)
    {
        cout<<iter->data<<":";
        for(struct lolistnode *iter2=iter->frnt;iter2!=NULL;iter2=iter2->next)
        {
            cout<<iter2->data<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int cmp;
    for(int i=0;i<sizeof(data)/sizeof(data[0]);i++)
    {
        if(!ispresentinhead(data[i].A))
        {
            pushlisthead(data[i].A);
        }
        if(!ispresentinhead(data[i].B))
        {
            pushlisthead(data[i].B);
        }
    }
    print();
    kruskals();
    print();
}
