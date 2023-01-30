#include<iostream>
using namespace std;
typedef struct  Node* Nodeptr;
typedef  int TYPEINFO;
const int STOP =-99;
struct Node
{
    int data;
    Node* link;
};
struct Queue
{
    Nodeptr front, rear;
};void khoiTao(Queue &q){
    q.front=NULL;
    q.rear=NULL;

}
int isEmpty(Queue q){
    if(q.front==NULL) return 1;
    return 0;
}
Nodeptr tao_Node(TYPEINFO x){
    Nodeptr p;
    p=new Node;
    p->data=x;
    p->link=NULL;
    return p;
}
void enQueue(Queue &q, TYPEINFO x){
    Nodeptr p;
    p=tao_Node(x);
    if(isEmpty(q)){
        q.front=p;
        q.rear=p;
    }
    else{
       q.rear->link=p;
       q.rear=p;
    }
}

void setValue(Queue& q){
    int x;
    while(1){
        cout<<"Nhap DL vaof Queue(Nhap-99) de dung :";
        cin>>x;
        if(x==STOP) break;
        enQueue(q,x);
    }
}
void print(Queue q){
    Nodeptr p;
    p=q.front;
    while(p!=NULL){
        cout<<p->data<<" "; 
        p   =p->link;
    }

}
TYPEINFO deQueue(Queue& q){
    if(isEmpty(q))
        return -1;
    else {
        Nodeptr p= q.front;
        q.front=p->link;
        TYPEINFO t=p->data;
        delete p;
        return t;
        }
    
}
TYPEINFO first_Element(Queue q){
    if(isEmpty(q)){
        return 0;
    }
  return  q.front->data;
}
int main(){
    Queue q;
    khoiTao(q);
    setValue(q);
    cout<<"Phan tu dau tien la: ";
    cout<<first_Element(q)<<endl;
    print(q);
    deQueue(q);
}