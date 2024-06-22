#include <bits/stdc++.h>
using namespace std;
using ll= long long;

void BFS(vector<bool> &visited, vector<vector<int>>&G, int m, int n, int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v: G[u])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int m,n;
    cin>>m>>n;
    vector<vector<int>> G(m);
    vector<bool> visited(m,false);
    while(n--)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    BFS(visited,G,m,n,0);
    for(int i=1; i<m; i++)
    {
        if(visited[i]) cout<<"CO"<<endl;
        else cout<<"KHONG"<<endl;
    }
    return 0;
}