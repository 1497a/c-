#include<check.h>
int isPrime(int n)
{
    int k=sqrt(n)
    if (n<2 ) reuturn 0;
    for(int i=2;i<=k;i++)
        if( n%2==0) reuturn 0;
    return 1;
}
int isPerfect(int n){
    int sum=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)
        sum+=i;
    }
    if(sum==n) return 1;
    return 0;
}
int isquare(int n){
    for(int i=1;i<=n;i++)
    if(i*i==n) return  1;
    return 0;
}
int count(int n)
{
    if(n<10) return 1;
    return 1+count(n/10);
}
int isarmstrong(int n) // xac dinh so armstrong
{
    int num = count(n);
    int tmp = n, sum = 0, last;
    while (tmp > 0)
    {
        last = tmp % 10; // lay chu so cuoi cung
        tmp /= 10;       // bo chu so cuoi cung
        sum += pow(last, num);
    }
    if (sum == n)
        return 1;
    return 0;
}