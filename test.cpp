#include "sort.h"
int main(){
    int a[10];
    for(int i=0;i<9;i++)
    {
        cin>>a[i];
    }
    insertionsort(a,9);
    cout<<"Chuoi sau khi sap xep la:"<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"DA UPDATE";
    return 0;
}