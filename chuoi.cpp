#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
void basic(){
    char* a=new char[10],b;// khai biến một con trỏ a theo kiểu ký tự
    getchar();// Nhập và chả về 1 ký tự
    //getch(); Tương tự getchar nhưng ko xuât ra màn hình
    //putchar(a);// Xuất một số ở dạng  ký tự ra màn hình
    //isalnum(b);// Trả  về giá trị khác không nếu là chữ hoặc số,trả về không nếu ngược lại
    isalpha(b);// Trả  về giá trị khác không nếu là chữ ,trả về không nếu ngược lại
    tolower(b);// Xuất giá trị chữ thường
    toupper(b);// Xuất giá trị chữ in. Cả hai đều trả giá trị đúng nếu nó không phải là chữ trong AsCCi
    toascii(b);// Như trên trả về vị trị của nó trong bảng accsi
    // Mỗi ký tự sẽ chứa một ô trong mảng một chiều 
    gets(a);//Nhập chuỗi
    puts(a);//Xuất chuối
    strlen(a);// Đo độ dài của chuỗi.
    strcpy(a,a);// copy của chuôi b sang cho chuỗi a
    strcmp(a,a);// này chắc nhớ ha tự tìm lại 
    strrev(a);// Đảo ngược chuỗi
    strlwr(a);//Đổi tất cả thành chữ thường
    strupr(a);//Đổi tất cả thành chữ Hoa
    strcat(a,"Ai biet");//Thêm chuỗi thứ 2 vào sau chuỗi thứ 1
    strchr(a,'s');// Tìm kiếm 's' trong a nếu có trỏ tới vị trí xuất hiện đầu tiền không thì NULL
    strrchr(a,'s');// Tìm kiếm 's' trong a nếu có trỏ tới vị trí xuất hiện cuối cùng không thì NULL
    strstr(a,a);// Tìm kiếm 'âs' trong a nếu có trả lại chuỗi tìm kiếm không thì NULL
    strtok(a,".");//Chia 1 chuỗi dài thành các chuỗi nhỏ được phân biệt riêng rẽ bởi các ký tự đặc biệt được chọn.
}
void tachchuoi(char *a){
    char* token=strtok(a," ");//token sẽ là các chuỗi  con sau khi tách
    while(token!=NULL){//tạo vòng lặp để in hết các chuỗi tách
        cout<<token<<endl;
        token=strtok(NULL," ");
    }

}
int specialchar(char* s){
    int count=0,tmp=strlen(s);
    for(int i=0;i<tmp;i++)
    {
        if((isalnum(s[i])==0)&&(s[i]!=' ')) count++;
    }
    return count;
}
void Bruteforce(char* a, char* b)
{
    int  k=0,n=strlen(a),m=strlen(b);
    
    for(int i=0;i<n-m+1;i++) {
        if(b[0]==a[i]){  
        for(int j=0;j<m;j++){
            if (b[j]==a[j+i])k++;
            else k=0;
        }
    if (k==strlen(b))break ;
    }
    }
    if (k==strlen(b)) cout<<"1 : ";
    else cout<<6;
}
int main(){
    
    char a[100]="Nam Thu Kieu Kiet Kien CUng Cu cao ";
    char b[100]="Cao";
    //cout<<strlen(a);
    Bruteforce(a,b);
    return 0;
}