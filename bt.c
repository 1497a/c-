#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct at // tao mot cau truc kieu du lieu la at(an tiem)
{
    int hp1, hp2, d, s;
    char t[8];
}at;
at b; // Khai bao cac bien toan cuc
float P1, P2;
void input(char *fname) // Nhap du lieu vao file input.txt
{
    at a;
    FILE *fp = fopen(fname, "w");
    printf("Moi ban bat dau nhap nhap:\n");
    scanf("%d %d %d %s %d", &a.hp1, &a.hp2, &a.d, &a.t, &a.s);
    fprintf(fp, "%d %d %d %s  %d", a.hp1, a.hp2, a.d, a.t, a.s);
    fclose(fp);
}
void duyetfile(at b , char *fname) // lay du lieu ra tu file input.txt
{
    FILE *fp = fopen(fname, "r");
    fscanf(fp, "%d%d%d%s%d", &b.hp1, &b.hp2, &b.d, &b.t, &b.s);
    fclose(fp);
}
void output(char *fname, float n) // dien ket qua vao file output.txt
{
    FILE *fp = fopen(fname, "w");
    fprintf(fp, "Ket Qua: %.3f", n);
    fclose(fp);
}
int  check(at b)// kiem tra du lieu nhap vao co hop le hay ko 
{
    if ((b.hp1 < 1 || b.hp1 > 999) || 
    (b.hp2 < 0 || b.hp2 > 500) ||
     (b.d < 1 || b.d > 1000) || 
     (b.s < 1 || b.s > 100)) return 0;
    if ((strcmp(b.t, "Flood") != 0)
    &&(strcmp(b.t, "Storm") != 0)
    &&(strcmp(b.t, "Rain") != 0)
    &&(strcmp(b.t, "Shower") != 0)
    &&(strcmp(b.t, "Drizzle") != 0)
    &&(strcmp(b.t, "Cloudy") != 0)) return 0;
    return 1;
}
int count(int n)
{
    int tmp = 0;
    while (n > 0)
    {
        n /= 10;
        ++tmp;
    }
    return tmp;
}
int is_armstrong(int n) // xac dinh so armstrong
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
int is_Prime(int n) // xac dinh so nguyen to
{
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for (int i = 2; i < k; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int triangular(int n) // tao so tam giac
{
    if (n == 1)
        return 1;
    return n + triangular(n - 1);
}
float g() // tinh gia tri g(s)
{
    if (b.s % 6 == 0)
        return b.s * 2;
    if (b.s % 6 == 1)
        return b.s / 2;
    if (b.s % 6 == 2)
        return -((b.s % 9) * (b.s % 9) * (b.s % 9)) / 5;
    if (b.s % 6 == 3)
        return -((b.s % 30) * (b.s % 30)) + 3 * b.s;
    if (b.s % 6 == 4)
        return -b.s;
    if (b.s % 6 == 5)
        return -triangular((b.s % 5) + 5);
}
float pt() // tinh gia tri p(t)
{
    if (strcmp(b.t, "Flood") == 0)
    {
        if (b.s % 6 == 0)
            return -0.1;
        if (b.s % 6 == 1)
            return -0.15;
        if (b.s % 6 == 2)
            return -0.20;
        if (b.s % 6 == 3)
            return -0.25;
        if (b.s % 6 == 4)
            return -0.05;
        if (b.s % 6 == 5)
            return 0;
    }
    if (strcmp(b.t, "Storm") == 0)
    {
        if (b.s % 6 == 0)
            return -0.05;
        if (b.s % 6 == 1)
            return -0.10;
        if (b.s % 6 == 2)
            return -0.15;
        if (b.s % 6 == 3)
            return -0.20;
        if (b.s % 6 == 4)
            return 0;
        if (b.s % 6 == 5)
            return 0.05;
    }
    if (strcmp(b.t, "Rain") == 0)
    {
        if (b.s % 6 == 0)
            return 0;
        if (b.s % 6 == 1)
            return -0.05;
        if (b.s % 6 == 2)
            return -0.10;
        if (b.s % 6 == 3)
            return -0.15;
        if (b.s % 6 == 4)
            return 0.05;
        if (b.s % 6 == 5)
            return 0.1;
    }
    if (strcmp(b.t, "Shower") == 0)
    {
        if (b.s % 6 == 0)
            return 0.05;
        if (b.s % 6 == 1)
            return 0;
        if (b.s % 6 == 2)
            return -0.05;
        if (b.s % 6 == 3)
            return -0.10;
        if (b.s % 6 == 4)
            return 0.10;
        if (b.s % 6 == 5)
            return 0.15;
    }
    if (strcmp(b.t, "Drizzle") == 0)
    {
        if (b.s % 6 == 0)
            return 0.1;
        if (b.s % 6 == 1)
            return 0.05;
        if (b.s % 6 == 2)
            return 0;
        if (b.s % 6 == 3)
            return -0.05;
        if (b.s % 6 == 4)
            return 0.15;
        if (b.s % 6 == 5)
            return 0.2;
    }
    if (strcmp(b.t, "Cloudy") == 0)
    {
        if (b.s % 6 == 0)
            return 0.15;
        if (b.s % 6 == 1)
            return 0.1;
        if (b.s % 6 == 2)
            return 0.05;
        if (b.s % 6 == 3)
            return 0;
        if (b.s % 6 == 4)
            return 0.20;
        if (b.s % 6 == 5)
            return 0.25;
    }
}
void gangt() // gan gia tri vao P1 va P2
{

    if (is_Prime(b.hp1))
    {
        P1 = 1000;
        P2 = (b.hp1 + b.s) % 1000;
    }
    else
    {
        P1 = b.hp1;
        P2 = (b.hp1 + b.d) % 100;
    }
}
float xuli() // Xu li du lieu theo de bai
{
    float p, f;

    if (is_armstrong(b.hp1) && is_armstrong(b.hp2)) // Kiem tra so armstrong
        return p = 1.000;
    gangt(); // Gan gia tri
    if (b.d < 200)
        return p = P1 / 1000;

    if (200 <= b.d && b.d < 300)
    {
        float sb = ((b.d + P1 + P2) / 1000);
        if (sb > 0.8)
            return p = 0.0;
        else
        {
            b.hp1 = b.hp1 - 100;
            if (b.hp2 > 50)
                b.hp2 = b.hp2 - 50;
            else
                b.hp2 = 0;
            b.d += 100;
        }
    }
    gangt(); // gan gia tri lan 2 khi bien hp1 va hp2 thay doi
    if (300 <= b.d && b.d < 800)
    {
        f = (40 - (abs(b.d - 500)) / 20 + g()) * (1 + pt());
        p = ((P1 + P2 * f) / (1000 + abs(P2 * f)));
        return (p < 0) ? 0 : p;
    }
    if (b.d >= 800)
    {
        f = (-b.d * b.s) * 1.0 / 1000;
        p = ((P1 + P2 * f) / (1000 + abs(P2 * f)));
        return (p < 0) ? 0 : p;
    }
}
int main()
{
    input("input.txt");
    duyetfile(b, "input.txt");
    if(check(b)) output("output.out",xuli());
    else output("output.out",-1);// neu khong hop le thi ket qua la -1.000
    return 0;
}