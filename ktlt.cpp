#include<iostream>
#include<math.h>
#define maxn 100
#define maxm 100
using namespace std;
int a[maxm][maxn];
int m,n;
int dequy(int n){
    if(n<10) return n;
    return n%10+dequy(n/10);
}
bool is_cp(int n){
    int sqr=sqrt(n);
    return (sqr*sqr==n);
}
int is_perfectdigit (int n){
    int sum=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)sum+=i;
    }
    if(sum==n) return 1;
    return 0;
}
int is_Prime(int n){
    if(n<2) return 0;
    int k=sqrt(n);
    for(int i=2;i<=k;i++)if(n%i==0) return 0;
    return 1;

}
void nhapfile(char* fname)
{	
	FILE* fp=fopen(fname,"w");
    int a,b;
    cout<<"Moi nhap so dong:";cin>>a;
    cout<<"Moi nhap so cot:";cin>>b;
	fprintf(fp,"%d %d\n",a,b);
    int d;
    cout<<"Bat dau nhap.";
	for(int i=0;i<a;i++){
	for(int j=0;j<b;j++)
    {cin>>d;
    fprintf(fp,"%d\t",d);}
    fprintf(fp,"\n");
    }

	fclose(fp);
}
void duyetfile(int a[maxm][maxn],char* fname,int &m,int &n)
{
    FILE* fp=fopen(fname,"rt");
    if(fp!=NULL){
	fscanf(fp,"%d%d",&m,&n);
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		fscanf(fp,"%d",&a[i][j]);
	}}
    }
	fclose(fp);
}
void printcp(int n)
{
    FILE* fp=fopen("CP.txt","a");
    fprintf(fp,"%d\t",n);
    fclose(fp);
}
void printprime(int n){
    FILE* fp=fopen("NT.txt","a");
    fprintf(fp,"%d\t",n);
    fclose(fp);
}
void printhc(int n){
    FILE* fp=fopen("HC.txt","a");
    fprintf(fp,"%d\t",n);
    fclose(fp);
}
void ghi(){
    for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
        if(is_cp(a[i][j])) printcp(a[i][j]);
        if(is_Prime(a[i][j])) printprime(a[i][j]);
        if(is_perfectdigit(a[i][j])) printhc(a[i][j]);
    }
    }
}
int main(){ 
    nhapfile("table.inp");
    duyetfile(a,"table.inp",m,n);
    ghi();
    cout<<is_Prime(4);
    return 0;
}