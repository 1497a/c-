#include<iostream>
#include<math.h>
using namespace std;
#define maxn 100
typedef struct point
{
    float x, y;
}pt;
typedef struct lines
{
    float x,y;
}line;
line duongthang(pt a,pt b)
{
    line l;
    l.x=(b.y-a.y)/(b.x-a.x);
    l.y=a.y-(l.x*a.x);
    return l;
}
int tongs(int n)
{
    if(n==1) return 1;
    return tongs(n-1)+n;
}
int tongs_2(int n){
    if(n==1) return 1;
    return tongs_2(n-1)+n*2-1;
}
int tongs_3(int n){
    if(n==0) return 0;
    return tongs_3(n-1)+n*2;}

int isprime(int n){
    if(n<2) return 0;
    int k=sqrt(n);
    for(int i=2;i<=k;i++)
        if(n%i==0) return 0;
    return 1;
}
int UCLN(int a,int b)
{
    a=abs(a);
    b=abs(b);
    while(b!=a)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
int findmax(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
        if(max<a[i]) max=a[i];
    return max;
}
int findmaxk(int a[][maxn],int n,int m ,int k)
{
    
    int max=a[k][0];
    for(int j=0;j<m;j++) {
        
        if(max<a[k][j]) max=a[k][j];
    }
    return max;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void nhapmang2chieu(int a[][maxn],int &n,int &m )
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) cin>>a[i][j];
}
void xuatmang2chieu(int a[][maxn],int n,int m )
{
    cout<<endl;
    for(int i=0;i<n;i++){ 
    for(int j=0;j<m;j++) 
    cout<<a[i][j]<<" ";
    cout<<endl;}
}
void xuatmang1chieu(int a[],int n )
{
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
void swapkl(int a[][maxn],int n,int m ,int k,int l)
{    
    for(int j=0;j<n;j++) 
        swap(a[j][k],a[j][l]);
    
}
void deleteatk(int a[],int k,int &n)
{
    for(int j=k;j<n-1;j++)
        a[j]=a[j+1];
    n--;
}
void deletek(int a[],int k,int &n)
{
    for(int j=0;j<n;j++)
        if(a[j]==k) deleteatk(a,j,n);
}
int  ptdt(pt a,pt b){
    float c,d;
    c=-(a.y-b.y)/(b.x-a.x);
    d=a.x*c+a.y;
   return c,d;
}
pt gdline(line a,line  b)
{
    pt c;
    c.x=0;
    c.y=0;
    if((a.x ==b.x)&& (a.y !=b.y)) return c;
    if(a.x !=b.x){
    c.x= (-a.y+b.y)/(a.x-b.x);
    c.y=a.x*c.x+b.x;}
    return c;
}
void nhappt(pt &a)
{
    cin>>a.x>>a.y;
}
int main(){
    //int n=6,m,a[maxn][maxn],k=1,l=3,b[6]={12,3,5,3,2,5};
    //nhapmang2chieu(a,n,m);
    //swapkl(a,n,m,k,l);
    //xuatmang2chieu(a,n,m);
    pt a,b;
    nhappt(a);
    nhappt(b);
    ptdt(a,b);
    return 0;
}