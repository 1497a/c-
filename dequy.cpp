#include<iostream>
#include<math.h>
using namespace std;
int dequy(int a[],int n){
    if(n==0) return a[n];
    
    return a[n-1]+dequy(a,n-1);
}
int findMax(int a[], int n)
{
    if(n==1) return a[0];
    int i=findMax(a,n-1);
    if(a[n-1]>i) return a[n-1];
    return i;
}
int findMin(int a[], int n)
{
    if(n==1) return a[0];
    int i=findMin(a,n-1);
    if(a[n-1]<i) return a[n-1];
    return i;
}
void sort(int a[], int n)
{
	if (n == 1)return;
	else{
		sort(a, n - 1); 
		if (a[n - 1] < a[n - 2])
		{ 
			int temp = a[n - 1]; 
			a[n - 1] = a[n - 2];
			a[n - 2] = temp;
		sort(a, n - 1);
		}
	}

}
int main(){
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    //cout<<a[i];}
    cout<<"\n";
    sort(a,n);
    //cout<<findMin(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i];

}