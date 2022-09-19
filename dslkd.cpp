#include <iostream>
using namespace std;
struct node {
    int infor;
    node* next;
    node* prev;
};
struct list {
    node* head, * tail;
};
list head, tail;
node* getnode(int x)
{
    node* p = new node;
    if (p == NULL) exit(1);
    p->infor = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void chenvaodau(list& l, node* p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = p;
    }
    else {
        l.head->prev = p;
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
        p->prev = l.tail;
        l.tail = p;
    }
}
void chenvaosauq(list& l, node* q, int x) {
    node* p = getnode(x);
    node* k = q->next;
    if (p == NULL) exit(1);
    if (q != NULL) {
     
        p->next = k;
        p->prev = q;    
        q->next = p;
        if (p != NULL)  k->prev = p;
        if (q == l.tail) l.tail = p;        
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
        cout << p->infor << " ";
        p = p->next;
    }
    cout << endl;
}

void sort(list l) {
    for (node* p = l.head; p != l.tail; p = p->next) {
        for (node* q = p->next; q != NULL; q = q->next)
        {
            if (abs(p->infor) < abs(q->infor)) {
                int tam = p->infor; p->infor = q->infor;
                q->infor = tam;
            }
        }
    }
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

//1 2 3
//
int main()
{
    list l{};
    int n, x, t;
    cout << "Danh sach co bao nhieu phan tu? "; cin >> n;
    cout << "Moi ban nhap gia tri: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        chenvaocuoi(l, getnode(x));
    }
    cin >> t;
    xuatlist(l);
    return 0;
}
