#include<bits/stdc++.h>
using namespace std;
#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái xuất hiện của key
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}
//###INSERT CODE HERE -
void Insert(HASHTABLE &ht, int key)
{
    if((float)(ht.n+1)/ht.M >LOAD) return;
    int i=0;
    int index=HF_LinearProbing(ht,key,i);
    // Tìm kiếm nếu key đã xuất hiện rồi thì không thêm vào nữa
    while(ht.table[index].flag==OCCUPIED)
    {
        if(ht.table[index].key == key) return;

        i++;
        index=HF_LinearProbing(ht,key,i);
    }

    ht.table[index].flag=OCCUPIED;
    ht.table[index].key=key;
    ht.n++;
}

void Delete(HASHTABLE &ht, int key)
{
    int i=0;
    int index=HF_LinearProbing(ht,key,i);
    while(ht.table[index].flag!=EMPTY)
    {
        if(ht.table[index].flag==OCCUPIED && ht.table[index].key==key)
        {
            ht.table[index].flag=DELETED;
            ht.n--;
            return;
        }
        i++;
        index=HF_LinearProbing(ht,key,i);
    }
}
void CreateHashTable(HASHTABLE &ht)
{
    cin>>ht.M;
    int num,operation, value;
    cin>>num;
    ht.n=0;
    ht.table=new NODE[ht.M];

    for(int i=0 ; i<ht.M; i++)
    {
        ht.table[i].flag=EMPTY;
        ht.table[i].key=0;
    }
    for(int i=0 ; i<num; i++)
    {
        cin>>operation>>value;
        if(operation==1) Insert(ht,value);
        else if(operation==0) Delete(ht,value);
    }
}
void Traverse(HASHTABLE ht)
{
    for(int i=0; i<ht.M; i++)
    {
        if(ht.table[i].flag == OCCUPIED) 
            cout<<i<<" --> "<<ht.table[i].key<<endl;
        else if(ht.table[i].flag == EMPTY)
            cout<<i<<" --> "<<"EMPTY"<<endl;
        else 
            cout<<i<<" --> "<<"DELETED"<<endl;

    }
}
void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}