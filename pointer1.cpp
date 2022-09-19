#include<iostream>
using namespace std;
void define_pointer(){
    int*p;
    int a=100;
    p=&a;//on tro p tro vao dia chi chua du lieu cua a
    cout<<*p;//==cout<<a; in ra gia tri cua vi tri ma con tro p chia vao
    cout<<p;// hien dia chi con tro tro vao
}
void input_Array_By_pointer(int *&a,int &n)//them & de thay doi duoc con tro a khong nhu mang se tu thay doi 
{
    cout<<"Nhap so phan tu cua mang: "; cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap phan tu thu "<<i<<" :";cin>>*(a+i);//*(a+i)==a[i]
    }
}
void output_Array_By_pointer(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<"Phan tu thu "<<i<<" :"<<*(a+i);
}
int dmax(int *a,int n){
    int max=*a;
    for(int i=0;i<n;i++){
        if(*(a+i)>max) max=*(a+i);
    }
    return max;
}
void swap(int &x,int &y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void input_Multi_Dimensional_Array_By_pointer(int *&a,int &m, int& n)
{
    cout<<"Nhap so cot cua mang: "; cin>>m;
    cout<<"Nhap so cot cua mang: "; cin>>n;
    a=new int [m*n]// cap phat mang dong cho a voi m*n kich thuoc
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        cout<<"Nhap phan tu thu "<i*j<<" :";
        cin>>*(a+n*i+j);
    }
}
void output_Multi_Dimensional_Array_By_pointer(int *a,int m, int n)
{
   for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        cout<<"Phan tu thu "<<*(a+n*i+j)<<" ";
    } 
}
int main()
{
    int c=10,d=21;
    int *a=&c;// Vì con trỏ (pointer) là một biến chứa một địa chỉ bộ nhớ, nên khi giá trị cho con trỏ, giá trị đó phải là 1 địa chỉ.
    int *b=&d;
}