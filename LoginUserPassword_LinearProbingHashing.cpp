#include <bits/stdc++.h>
using namespace std;
using ll= long long;

#define MAXTABLESIZE 10000
const int TableSize = 10000;

struct NODE {
    string username;
    string password;
};
typedef NODE* HASHTABLE[MAXTABLESIZE];

int HF(string username)
{
    unsigned int hashvalue=0;
    for(char ch: username)
    {
        hashvalue=37*hashvalue+ch;
    }
    return hashvalue%TableSize;
}
int HF_LinearProbing(string username, int i)
{
    int h=HF(username);
    return (h+i)%TableSize;
}

void CreateHash(HASHTABLE &ht, int &CurrentSize, int n )
{
    CurrentSize=0;
    for(int i=0; i<MAXTABLESIZE; i++)
    {
        ht[i]=NULL;
    }
    int j=0;
    for(int i=0; i<n; i++)
    {
        string username, password;
        cin>>username>>password;

        // Tìm kiếm nếu key đã xuất hiện rồi thì không thêm vào nữa
        int index=HF_LinearProbing(username,j);
        while(ht[index]!=NULL && ht[index]->username!=username)
        {
            j++;
            index=HF_LinearProbing(username,j);
        }
        if(ht[index]==NULL)
        {
            ht[index]=new NODE();
            CurrentSize++;
        }
        ht[index]->username=username;
        ht[index]->password=password;
    }
}
void OutPassword(HASHTABLE ht, int &CurrentSize, int m)
{
   
    int j=0;
    for(int i=0 ; i<m; i++)
    {
        string username;
        cin>>username;
        int index=HF_LinearProbing(username,j);
         bool found=false;
        while(ht[index]!=NULL)
        {
            if(ht[index]->username==username){
                cout<<ht[index]->password<<endl;
                found=true;
                break;
            }
            j++;
            index=HF_LinearProbing(username,j);
        }
        if(!found)  cout << "Unregistered User." << endl;
    }
    
}
int main() {
    HASHTABLE H;
    int CurrentSize;
    int n, m;
    cin >> n >> m;

    CreateHash(H, CurrentSize, n);
    OutPassword(H, CurrentSize, m);

    return 0;
}

