#include <bits/stdc++.h>
using namespace std;
using ll= long long;

void Input(int v, map<string,int> &v_index, int e,  vector<vector<int>> &G)
{
    for(int i=0; i<v; i++)
    {
        string v_name;
        cin>>v_name;
        v_index[v_name]=i;
    }
    for(int i=0; i<e; i++)
    {
        string v1,v2;
        cin>>v1>>v2;
        G[v_index[v1]][v_index[v2]]=1;
    }
}

void Output(int v, map<string,int> v_index, int e,  vector<vector<int>> G)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}
void AdjacentPeaks(int v, map<string,int> v_index, int e, vector<vector<int>> G, string v_name)
{
    bool found=false;
    auto it=v_index.find(v_name);
    if(it==v_index.end()){
         cout<<"No find";
         return;
    }
    for(int j=0 ; j<v; j++)
    {
        if(G[v_index[v_name]][j]!=0)
        {
            for(auto it:v_index)
            {
                if(it.second==j) cout<<it.first<<" ";
            }
            found=true;
        }
    
    }
    if(!found) cout<<"No find";
}

void XuatDinhCoBacK(int k,int v, map<string,int> v_index, int e, vector<vector<int>> G){
  bool found=false;
  for(int i=0 ; i<v; i++){
        int bac=0;
        for(int j=0; j<v; j++){
            if(G[i][j]!=0) bac++;
            if(G[j][i] != 0) bac++;
        } 

        if(bac==k) {
            for(auto it : v_index)
            {
                if(it.second == i)
                    cout << it.first << ' ';
            }
            found=true;
        }
    }

  if(!found) cout<<"No find";
}
void DFS(string v_start,int v, map<string,int> v_index, int e, vector<vector<int>> G)
{
    vector<bool> visited(v,false);
    vector<int> res;
    int start=v_index[v_start];
    stack<int> s;
    s.push(start);
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        if(!visited[u])
        {
            visited[u]=true;
            res.push_back(u);
        for(int i=0; i<v; i++)
        {
            if(G[u][i]==1 && !visited[i])
            {
                s.push(i);
            }
        }
        }
    }

    for(auto i:res)
    {
        for(auto it:v_index){
            if(i==it.second){
                cout<<it.first<<" ";
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int v, e;
    cin >> e >> v;
    vector<vector<int>> G (v, vector<int>(v, 0)); 
    map<string, int> v_index; 
    Input(v, v_index, e, G);
    string v_start;
    cin>>v_start;
    DFS(v_start,v,v_index,e,G);
    XuatDinhCoBacK(k,v,v_index,e,G);
    AdjacentPeaks(v,v_index,e,G,v_name);
    Output(v, v_index, e, G);
    return 0;   
}