#include<iostream>
#include<malloc.h>
using namespace std;
struct edges
{
    char A,B;
    int weight;
};
char queuebfs[100],stackdfs[100],visited[100];
int frnt=-1,rer=-1,top=-1,vtop=-1;
void pushdfs(char a)
{
    stackdfs[++top]=a;
    visited[++vtop]=a;
}
char popdfs()
{
    return stackdfs[top--];
}
bool visiteddfs(char a)
{
    for(int i=0;i<=vtop;i++)
    {
        if(a==visited[i])
        {
            return true;
        }
    }
    return false;
}
bool visitedbfs(char a)
{
    for(int i=0;i<=rer;i++)
    {
        if(a==queuebfs[i])
        {
            return true;
        }
    }
    return false;
}
void enqueue(char a)
{
    if(frnt==-1)
    {
        frnt++;
    }
    queuebfs[++rer]=a;
}
char dequeue()
{
    if(frnt==-1||(frnt==rer&&frnt!=0))
    {
        return 0;
    }
    return(queuebfs[frnt++]);
}
class nodes
{
    char node;
    int weight;
    nodes *nextnode;
public:
    void setnode(char n,int w)
    {
        node=n;weight=w;
    }
    char getnode()
    {
        return node;
    }
    int getweight()
    {
        return weight;
    }
    void setnext(nodes *node)
    {
        nextnode=node;
    }
    nodes* getnext()
    {
        return nextnode;
    }
};
class header
{
    char nodehead;
    header* nexthead;
    nodes *first,*rear;
public:
    header()
    {
        nodehead=100;
        nexthead=NULL;
        first=NULL;
        rear=NULL;
    }
    char getnodehead()
    {
        return nodehead;
    }
    void setnodehead(char n)
    {
        nodehead=n;
    }
    header* getnexthead()
    {
        return nexthead;
    }
    void setnexthead(header *n)
    {
        nexthead=n;
    }
    void setfront(nodes *f)
    {
        first=f;
    }
    nodes* getfront()
    {
        return first;
    }
    void setrear(nodes *r)
    {
        rear=r;
    }
    nodes* getrear()
    {
        return rear;
    }
    void pushhead(char nodename)
    {
        header *newnode = (header*) malloc(sizeof(header));
        newnode->setnodehead(nodename);
        newnode->setfront(NULL);
        newnode->setrear(NULL);
        newnode->setnexthead(NULL);
        if(this->getnexthead()==NULL)
        {
            this->setnexthead(newnode);
        }
        else
        {
            header *temp;
            temp=this->getnexthead();
            while(temp->getnexthead()!=NULL)
            {
                temp=temp->getnexthead();
            }
            temp->setnexthead(newnode);
        }
    }
    header* ispresent(char nodename)
    {
        header *temp;
        temp=this->getnexthead();
        if(temp!=NULL)
        {
            while(temp!=NULL)
            {
                if(temp->getnodehead()==nodename)
                {
                    return temp;
                }
                temp=temp->getnexthead();
            }
        }
        return NULL;
    }
    void pushnode(char data,int weight)
    {
        nodes *newnode = (nodes*) malloc(sizeof(nodes));
        newnode->setnext(NULL);
        newnode->setnode(data,weight);
        nodes *f=getfront();
        if(f==NULL)
        {
            this->setfront(newnode);
            this->setrear(newnode);
        }
        else
        {
            this->getrear()->setnext(newnode);
            this->setrear(newnode);
        }
    }
    void print()
    {
        header *hiter;
        nodes *iter;
        hiter=this->getnexthead();
        while(hiter!=NULL)
        {
            iter=hiter->getfront();
            cout<<hiter->getnodehead()<<"\t:\t";
            while(iter!=NULL)
            {
                cout<<"("<<iter->getnode()<<","<<iter->getweight()<<")\t->\t";
                iter=iter->getnext();
            }
            hiter=hiter->getnexthead();
            cout<<endl;
        }
    }
    void bfs()
    {
        header *hptr = this->getnexthead();
        enqueue(hptr->getnodehead());
        do
        {
            char ch=dequeue();
            header *iter=this->getnexthead();
            while(iter->getnodehead()!=ch)
            {
                iter=iter->getnexthead();
            }
            nodes *nodeiter = iter->getfront();
            while(nodeiter!=NULL)
            {
                if(!visitedbfs(nodeiter->getnode()))
                {
                    enqueue(nodeiter->getnode());
                }
                nodeiter=nodeiter->getnext();
            }
        }while(frnt<rer);
        cout<<endl;
        for(int prnt=0;prnt<=rer;prnt++)
        {
            cout<<queuebfs[prnt]<<"->\t";
        }
        cout<<endl;
    }
    void dfs()
    {
        header *hptr = this->getnexthead();
        pushdfs(hptr->getnodehead());
        cout<<endl;
        do
        {
            char ch=popdfs();
            cout<<ch<<"->\t";
            header *iter=this->getnexthead();
            while(iter->getnodehead()!=ch)
            {
                iter=iter->getnexthead();
            }
            nodes *nodeiter = iter->getfront();
            char arr[100],arrtop=-1;;
            while(nodeiter!=NULL)
            {
                if(!visiteddfs(nodeiter->getnode()))
                {
                    arr[++arrtop]=nodeiter->getnode();
                }
                nodeiter=nodeiter->getnext();
            }
            for(int i=arrtop;i>=0;i--)
            {
                pushdfs(arr[i]);
            }
        }while(top!=-1);
        cout<<endl;
    }
}headdata;
int main()
{
    edges data[]={{'D','E',1},{'A','B',2},{'G','F',3},{'C','B',4},{'A','C',5},{'A','F',5},{'D','F',6},{'A','G',8},{'A','E',10},{'C','E',10},{'A','D',12},{'E','B',64},{'G','B',102}};
    header *from,*to;
    for(int i=0;i<sizeof(data)/sizeof(edges);i++)
    {
        from=headdata.ispresent(data[i].A);
        to=headdata.ispresent(data[i].B);
        if(from==NULL)
        {
            headdata.pushhead(data[i].A);
            from=headdata.ispresent(data[i].A);
        }
        if(to==NULL)
        {
            headdata.pushhead(data[i].B);
            to=headdata.ispresent(data[i].B);
        }
        from->pushnode(data[i].B,data[i].weight);
        to->pushnode(data[i].A,data[i].weight);
    }
    headdata.print();
    cout<<endl<<"Breadth First Search:-\n";
    headdata.bfs();
    cout<<endl<<"Depth First Search:-\n";
    headdata.dfs();
    return 0;
}
