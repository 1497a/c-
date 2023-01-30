#include "io.h"
#define maxv 100
typedef struct node *list;
struct  node
{
    int infor;
    list next;
};
typedef list Graph[maxv]; //maxv là số đỉnh tối ta của v
Graph G;
void Initialize(Graph &G)
{
int i,x,y,m,n;
list t;
cout<<"given number of edges and vertices of Graph:"; 
cin>>m>>n;
for(i=1;i<=n;i++) G[i]=NULL;
for(i=1;i<=m;i++)
{   
cout<<"given edge "<<i<<"(x, y):"; cin>>x>>y;
t=new(node); t->infor=x; t->next=G[y]; G[y]=t;
t=new(node); t->infor=y; t->next=G[x]; G[x]=t;
}
}
int main(){
    return 0;
}