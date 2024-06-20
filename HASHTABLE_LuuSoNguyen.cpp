#include<bits/stdc++.h>
using namespace std;

struct NODE {
    int key;
    NODE *pNext;
};

struct LIST {
    NODE * pHead, *pTail;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    LIST *table;
};
void CreateEmptyList(LIST &L)
{
    L.pHead=NULL;
    L.pTail=NULL;
}
NODE* CreateNode(int x)
{
    NODE* p=new NODE;
    if(p==NULL) exit(1);
    p->key=x;
    p->pNext=NULL;
}
int HF(HASHTABLE ht, int key) { return key % ht.M; }

void InsertHashTable(HASHTABLE &ht, int x)
{
    NODE* p= CreateNode(x);
    int index=HF(ht,x);
    if(ht.table[index].pHead==NULL)
    {
        ht.table[index].pHead=p;
        ht.table[index].pTail=p;
    }
    else
    {
        ht.table[index].pTail->pNext=p;
        ht.table[index].pTail=p;
    }
    ht.n++;
} 
void CreateHashTable(HASHTABLE& ht)
{
    cin>>ht.M;
    for(int i=0; i<ht.M; i++) CreateEmptyList(ht.table[i]);
    while(1){
        int x;
        cin>>x;
        if(x==-1)  break;
        InsertHashTable(ht,x);
    }
}
void Traverse(HASHTABLE ht)
{
    for(int i=0; i<ht.M; i++)
    {
        cout<<i<<" ";
        NODE *p=ht.table[i].pHead;
        while(p!=NULL)
        {
            cout<<"--> ";
            cout<<p->key<<" ";
            p=p->pNext;
        }
        cout<<endl;
    }
}
int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);

    return 0;
}