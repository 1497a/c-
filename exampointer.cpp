#include<iostream>
#include<math.h>
using namespace std;
struct SV{
    int mssv;
    char hoten[32];
    float dcb,dcn1,dcn2;
};      
void input_Array_By_pointer(int *&a,int &n)//them & de thay doi duoc con tro a khong nhu mang se tu thay doi 
{
    cout<<"Nhap so phan tu cua mang: "; cin>>n;
    a=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap phan tu thu "<<i+1<<" :";
        cin>>*(a+i);//*(a+i)==a[i]
    }
}
void output_Array_By_pointer(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<"Phan tu thu "<<i+1<<" :"<<*(a+i)<<"\n";
}

void input_Multi_Dimensional_Array_By_pointer(int *&a,int &m, int& n)
{
    cout<<"Nhap so cot cua mang: "; cin>>m;
    cout<<"Nhap so cot cua mang: "; cin>>n;
    a=new int [m*n];// cap phat mang dong cho a voi m*n kich thuoc
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        cout<<"Nhap phan tu thu "<<i*j<<" :";
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
void tangmang(int*&a,int&n){
    int *resize = new int[n+1];
    // sao chép phần tử
	for (int i = 0; i < n; i++)
	{
		resize[i] = a[i];
	}
    delete[] a; // Xóa mảng hiện tại

	a = resize; // Trỏ sang mảng đã resize
	n = n+1;
    delete[] resize;
}
void giammang(int*&a,int&n){
    int *resize = new int[n-1];

	// sao chép phần tử
	for (int i = 0; i < n; i++)
	{
		resize[i] = a[i];
	}
    delete[] a; 

	a = resize; 
	n = n-1;
    delete[] resize;
}
void delete1_At_K(int *&a,int &n,int k)
{
    if(k<0) k=0;
    if(k>=n)k=n-1;
    for(int i=k;i<n-1;i++)
    *(a+i)=*(a+i+1);
    giammang(a,n);
}
int is_Prime(int x)
{
    if(x<2) return 0;
    int k=sqrt(x);
    for(int i=2;i<=k;i++)
        if(x%i==0) return 0;
    return 1;
}
void add_X_At_K(int *&a,int &n,int x,int k)
{
    if(k<0) k=0;
    if(k>=n)k=n-1;
    

	tangmang(a,n);
    output_Array_By_pointer(a,n);
    cout<<"\n";
    for(int i=n-1;i>=k;i--)
    *(a+i)=*(a+i-1);
    a[k]=x;
}   

void delete_prime(int *&a,int &n){
    for(int i=0;i<n;i++)
        if(is_Prime(*(a+i))==1){ 
            delete1_At_K(a,n,i);
            --i;
        }
    
}
int main()
{
   int *a,n,x,k;
   input_Array_By_pointer(a,n);
   cout<<"Mang sau khi nhap la: \n";
   output_Array_By_pointer(a,n);
   cout<<endl;
//    cout<<"Moi ban nhap vi tri can xoa: ";cin>>k;
//    cout<<"Moi ban nhap gia tri can them: ";cin>>x;
//    add_X_At_K(a,n,x,k);
    delete_prime(a,n);
   output_Array_By_pointer(a,n);
}