#include<iostream>
const int MAX=50;
typedef int type;
const int STOP=-99;
using namespace std;
struct Queue
{
    int front, rear;
    int elem[MAX];
};
void khoiTao(Queue &q){
    q.front=-1;
    q.rear=-1;

}
int isEmpty(Queue q){
    if(q.front==-1) return 1;
    return 0;
}
int isFull(Queue q){
    return(q.rear-q.front==MAX-1);
}
int enQueue(Queue &q, type x){
    int i;
    
    if(isFull(q)) return 0;
    else{
        if(q.front==-1) q.front=0;
        else {if(q.rear == MAX-1){
            for(i= q.front;i< q.rear;i++)
            q.elem[i-q.front]=q.elem[i];
            q.rear=MAX-1-q.front;
            q.front=0;
            
        }}
        q.rear ++;
        q.elem[q.rear]=x;
        return q.rear;
    }
}int enQueue(Queue &q, type x){
    int i;
    
    if(isFull(q)) return 0;
    else{
        if(q.front==1) q.front=0;
        else {if(q.rear == MAX-1){
            for(i= q.front;i< q.rear;i++)
            q.elem[i-q.front]=q.elem[i];
            q.rear=MAX-1-q.front;
            q.front=0;
        }}
        q.rear ++;
        q.elem[q.rear]=x;
        return q.rear;
    }
}
void print(Queue q){
    if(isEmpty(q)!=1){
        for(int i=q.front;i<=q.rear;i++){
            cout<<q.elem[i]<<" ";
        }
    }
    else cout<<"RONG!!!";
}
void setValue(Queue& q){
    int x;
    while(1){
        cout<<"Nhap DL vaof Queue(Nhap-99) de thoat";
        cin>>x;
        if(x==STOP) break;
            
    }
}
int deQueue(Queue& q){
    if(isEmpty(q)!=1){
        if(q.front==q.rear) khoiTao(q);
        else{
            int t=q.elem[q.front];
            q.front=q.front+1;
            return t;
        }
    }
    else return 0;
}
void first_Element(Queue q){
    if(isEmpty(q)!=1)
    cout<<q.elem[q.front]<<endl;
    else cout<<"RONG!!!";
}

int main(){
    Queue q;
    khoiTao(q);
    setValue(q);
    cout<<"Phan tu dau tien la: ";
    first_Element(q);
    print(q);
    cout<<"Sau khi dequeue"<<deQueue(q);
    
}