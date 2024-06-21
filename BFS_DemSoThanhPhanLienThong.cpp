#include <bits/stdc++.h>
using namespace std;
using ll= long long;

const int maxN=1e5+7;

int n, m, components=0;
bool visit[maxN];
vector<int> g[maxN];

void BFS(int s)
{
    components++;
    queue<int> q;
    q.push(s);
    visit[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // kiểm tra các đỉnh kề mà chưa đánh dấu push vào q
        for(auto v: g[u])
        {
            if(!visit[v]) {
                q.push(v);
                visit[v]=true;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // Set tất cả giá trị trong visit là flase;
    fill_n(visit,n+1, false);
    for(int i=1 ; i<=n; i++)
    {
        if(!visit[i]) BFS(i);
    }
    cout<<components<<endl;
   
    return 0;
}