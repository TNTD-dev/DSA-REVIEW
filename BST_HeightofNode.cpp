#include <bits/stdc++.h>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

TREE CreateTNode(int x)
{
    TNODE* p;
    p=new TNODE;
    if(p==NULL) exit(1);

    p->key=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}
void Insert(TREE &T, int x)
{
    if(T)
    {
        if(T->key==x) return;
        else if(T->key>x) return Insert(T->pLeft,x);
        else return Insert(T->pRight,x);
    }
    T=CreateTNode(x);
}
void CreateTree(TREE &T)
{
    int x;
    while(1){
        cin>>x;
        if(x==-1) break;
        Insert(T,x);
    }
}

TREE FindNode(TREE T, int x)
{
    while(T!=NULL)
    {
        if(T->key==x) return T;
        else if(T->key>x) T=T->pLeft;
        else T=T->pRight;
    }
    return NULL;
}
int HeightofNode(TREE T)
{
    if(T==NULL) return -1;
    int left=HeightofNode(T->pLeft);
    int right=HeightofNode(T->pRight);
    return 1+max(left,right);
}
int HeightOfNode(TREE T, int x)
{
    TREE p=FindNode(T,x);
    if(p==NULL) return -1;
    return HeightofNode(p);
}

int main() {
    TREE T;
    int x;

    cin >> x;

    T = NULL;
    CreateTree(T);

    if(T==NULL) cout << "Empty Tree.";
    else cout << HeightOfNode(T, x);

    return 0;
}