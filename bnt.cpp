#include <iostream>
#include<math.h>
using namespace std;
struct node{
    int infor;
    node* left, * right;
};
typedef node* tree;
int chenvaobst(tree& root, int x) {
    if (root != NULL)
    {
        if (root->infor == x) return 0;
        if (root->infor > x) return chenvaobst(root->left, x);
        else    return chenvaobst(root->right, x);
    }
    else {
        root = new node;
        if (root == NULL) return -1;
        root->infor = x;
        root->left = root->right = NULL;
        return 1;
    }
};
void taobst(tree& root) {
    int k, n;
    cout << "\n nhap n: "; cin >> n;
    root = NULL;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        chenvaobst(root, k);
    }
}
void LNR(tree root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->infor << " ";
        LNR(root->right);
    }
}
int  tong(tree root,int &s) {
    if (root != NULL) {
        tong(root->right, s);
        s = s + root->infor;
        tong(root->left, s);
    }
    return s;
}
int gtln(tree root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->infor;
}
int demnutla(tree root) {
    if (root == NULL) return 0;
    if ((root->left == NULL) && (root->right == NULL)) return 1;
    return demnutla(root->left)+demnutla(root->right);  
}
int demnutco1caycon(tree root) {
    if (root == NULL) return 0;
    if (((root->left != NULL) && (root->right == NULL)) || 
        ((root->left == NULL) && (root->right != NULL))) 
        return 1+ demnutco1caycon(root->left) + demnutco1caycon(root->right);
    return demnutco1caycon(root->left) + demnutco1caycon(root->right);
}
int demnutco2caycon(tree root) {
        if (root == NULL) return 0;
        if ((root->left != NULL) && (root->right != NULL))
            return 1+ demnutco2caycon(root->left) + demnutco2caycon(root->right);
        return demnutco2caycon(root->left) + demnutco2caycon(root->right);
}
int demnut(tree root) {
    if (root == NULL) return 0;
    return demnut(root->left) + demnut(root->right) + 1;

}
void waytox(tree root, int x) {
    cout << "Moi may nhap so x: "; cin >> x;
    while (root->infor != x) {
        cout << root->infor << " ->";
        if (root->infor > x) root = root->left;
        else
            if (root->infor < x)root = root->right;
    }
    cout << root->infor;

}
int isPrime(int x) {
    if (x < 2) return 0;
    int k = sqrt(x);
    for (int i = 2; i < k; i++)
        if ( x % i == 0) return 0;
    return 1;
}
int le(int x)
{
    if(x%2==1) return 1;
    return 0;
}
int chan(int x)
{
    if(x%2==0) return 1;
    return 0;
}
int demnguyento(tree root) {
    if (root == NULL) return 0;
    return isPrime(root->infor) + demnguyento(root->left) + demnguyento( root->right);
}
int demnsole(tree root) {
    if (root == NULL) return 0;
    return le(root->infor) + demnguyento(root->left) + demnguyento( root->right);
}
int demnsochan(tree root) {
    if (root == NULL) return 0;
    return chan(root->infor) + demnguyento(root->left) + demnguyento( root->right);
}
void xy(tree root,int x,int y,int &s) {
    
    if (root != NULL) {
        xy(root->left,x,y,s);
        if(root->infor>y&&root->infor<x) s++;
        xy(root->right,x,y,s);
    }
}
//8 3 20 2 5 11 30 9 18 4
int main()
{
    int s = 0,x,y;
    tree root ;
    taobst(root);
    cout<<" NHap x,y";cin>>x>>y;
    xy(root,x,y,s);
    cout<<s;
    return 0;
}

