#include <iostream>
#include<math.h>
using namespace std;
struct node {
    int infor;
    node* next;
};  
struct list {
    node* head, * tail;
};
list head, tail;
node* getnode(int x)
{
    node* p=new node;
    if (p == NULL) exit(1);
    p->infor = x;
    p->next = NULL;
    return p;
}
void chenvaodau(list &l, node* p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = p;
    }
    else {
        p->next = l.head;
        l.head = p;
    }
}
void chenvaocuoi(list& l, node* p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail=p;
    }
}
void chenvaosauq(list& l, node* q,int x) {
    node* p = getnode(x);
    if (p == NULL) exit(1);
    if (q != NULL) {
        p->next = q->next;
        q->next = p;
    }
    else chenvaodau(l, p);
}
void appendlist(list& l, list& ll)
{
    if (l.head == NULL) l = ll;
    else {
        l.tail->next = ll.head;
    }
 }
void xuatlist(list l) {
    node* p = l.head;
    while (p != NULL) {
        cout << p->infor<<" ";
        p = p->next;
    }
    cout << endl;
}
int isPrime(int n) {
    if (n < 2) return 0;
    int k = sqrt(n);
    for (int i = 2; i < k; i++)
        if (n % i == 1) return 0;
    return 1;
}
float average(list l) {  
    int sum = 0,  n= 0;
    for (node* p = l.head; p != NULL; p = p->next) {
        if (isPrime(p->infor)==1) { sum += p->infor; n++; }
    }
   return  n>0?1.0*sum/n:0;
}
void sort(list l) {
    for (node* p = l.head; p != l.tail; p = p->next) {
        for(node* q=p->next;q!=NULL;q=q->next)
        {if (abs(p->infor) <abs( q->infor) ){
            int tam = p->infor; p->infor = q->infor;
            q->infor = tam;
        }
        }
    }
}
float cau5(list l) {
    int sum = 0, flag= 1,n=0;
    for (node* p = l.head; p != NULL; p = p->next) {
        sum *= sqrt(abs(p->infor));
        n++;
        if(p->infor<0) flag=-1;
    }
    return  (flag!=-1) ? 1.0 * sum / n : 0;
}
float cau6(list l) {
    int postive = 1, negative = 0, count = 0;
    for (node* p = l.head; p !=NULL; p = p->next) {
        if (p->infor < 0)negative += abs(p->infor);
        else if (p->infor > 0) { postive *= p->infor; count++ ; }
    }
    return (count!=0)?1.0*negative/postive:-1;
}
int xoaphantudau(list &l) {
    node* p = l.head;
    l.head = l.head->next;
    p->next = NULL;
    delete p;
    return 1;
}
int xoaphantucuoi(list& l) {
    for (node* k = l.head; k != NULL; k = k->next)
    {
        if (k->next == l.tail)
        {
            delete l.tail;
            k->next = NULL;
        }
}
    return 1;
}
void insertati(list &l,int i,int x,int n)
{
    node* p=l.head;
    for(int j=0;j<i-1;j++)
        p=p->next;
    if(i==0) chenvaodau(l,getnode(x));
    else if(i==n-1) chenvaocuoi(l,getnode(x));
    else 
    chenvaosauq(l,p,x);
    

}
int sum(int x) {
    int sum=0;
    while (x >0) {
        sum = sum + (x % 10);
        x=(x / 10);
    }
    return sum;
}
void cau2(list& l,int n ) {
    node* p;
    p = l.head;
    int i = 1;
    for (i; i < n;i++) {
        chenvaosauq(l, p, sum(p->infor));
        p = p->next->next;
    }
    if (p ->next==NULL) chenvaocuoi(l,getnode(sum(p->infor)));
}
int findX(list l,int x){
    int n=0;
    for(node* p=l.head;p!=NULL;p=p->next){
        if(p->infor==x) return n;
        n++;
    }
    return -1;
}
int  dem(list l) {  
    int n = 0;
    for (node* p = l.head; p != NULL; p = p->next) {
        if (isPrime(p->infor)==1) n++; 
    }
   return  sum;
}
//1 2 3
//
int main()
{
    list l{};
    int n,x,t,i;
    cout << "Danh sach co bao nhieu phan tu? "; cin >> n;
    cout << "Moi ban nhap gia tri: ";
    for (int j = 0; j < n; j++)
    {
        cin >> x;
        chenvaocuoi(l, getnode(x));
    }
    // cout<<"Nhap i: ";

    // cin >> i;
    cout<<"Nhap gia tri can tim: ";
    cin>>x;;
    xuatlist(l);
    cout<<findX(l,x);
    return 0;
}
