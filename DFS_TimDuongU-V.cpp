#include <bits/stdc++.h>
using namespace std;
using ll= long long;
const int maxN=1e5+7;
int n, m, s,t;
int par[maxN];
vector<int> g[maxN];
map<string,int> v_index;

void Input(int n, int m)
{
    for(int i=0; i<n ; i++)
    {
        string v;
        cin>>v;
        v_index[v]=i;
    }
    for(int i=0 ; i<m; i++)
    {
        string v1,v2;
        cin>>v1>>v2;
        g[v_index[v1]].push_back(v_index[v2]);
        
    }
}
void DFS(int s, bool visit[])
{
    fill_n(visit,n+1, false);
    fill_n(par, n+1, -1);

   
    stack<int> st;
    st.push(s);
    visit[s]=true;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        for(auto v: g[u])
        {
            if(!visit[v]){
                par[v]=u;
                visit[v]=true;
                st.push(v);
            }
        }
    }
}

void Path(int e)
{
    vector<int> path;
    for(int v=e; v!=-1 ; v=par[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for(auto i:path)
    {
         for(auto it:v_index)
         {
             if(it.second==i) cout<<it.first<<" ";
         }

    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin>>n>>m;
    Input(n,m);
    int t;
    bool visit[maxN];
    cin>>t;
     while(t--)
     {
        string v_s, v_e;
        cin>>v_s>>v_e;
        int s=v_index[v_s];
        int e=v_index[v_e];
        BFS(s,visit);
        if(!visit[e]) cout<<"no_path"<<endl;
        else Path(e);
    }
    return 0;
}